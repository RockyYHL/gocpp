#include "speechManager.h"

SpeechManager::SpeechManager()
{
    this->initSpeech();
    this->createSpeaker();
}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::showMenu()
{
    cout << "*******************************" << endl;
    cout << "*******welcome to speech*******" << endl;
    cout << "*******1.Start to game*********" << endl;
    cout << "*******2.History*********" << endl;
    cout << "*******3.Clear record*********" << endl;
    cout << "*******0.Exit*********" << endl;
    cout << "*******************************" << endl;
    cout << endl;
}

void SpeechManager::exitSystem()
{
    cout << "Good Bye" << endl;
    exit(0); // 退出系统
}

void SpeechManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    this->m_index = 1;

    this->loadRecord();
    this->m_record.clear();
}

void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "player";
        name += nameSeed[i];

        Speaker sp;
        sp.name = name;

        for (int j = 0; j < 2; j++)
        {
            sp.score[j] = 0;
        }

        // 创建选手编号，并放进v1
        this->v1.push_back(i + 10001);
        // 选手编号及对应选手放入map
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

void SpeechManager::speechDraw()
{
    cout << "Round " << this->m_index << " is drawing" << endl;
    cout << "-----------------------" << endl;
    cout << "Sequence after drawing" << endl;

    if (this->m_index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    cout << "-----------------------" << endl;
}

void SpeechManager::speechContest()
{
    cout << "Round " << this->m_index << " is starting" << endl;

    // 准备临时容器，存放小组成绩
    multimap<double, int, greater<double>> groupScore;

    int num = 0; //记录人员个数

    vector<int> v_src; // 比赛选手容器
    if (this->m_index == 1)
    {
        v_src = this->v1;
    }
    else
    {
        v_src = this->v2;
    }

    // 遍历所有选手比赛
    for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
    {
        // 评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f; //600~1000
            // cout << score << " ";
            d.push_back(score);
        }
        // cout << endl;
        sort(d.begin(), d.end(), greater<double>()); // 降序排列
        d.pop_front();
        d.pop_back();

        double sum = accumulate(d.begin(), d.end(), 0);
        double avg = sum / (double)d.size();

        // 将平均分放入map容器
        this->m_Speaker[*it].score[this->m_index - 1] = avg;

        // 打印平均分
        // cout << "Num: " << *it << "\tName: " << this->m_Speaker[*it].name << "\tScore: " << this->m_Speaker[*it].score[this->m_index - 1] << endl;

        // 将打分数据，放入到临时小组容器中
        groupScore.insert(make_pair(avg, *it));
        num++;

        // 每6人取出前三名
        if (num % 6 == 0)
        {
            cout << "Group" << num / 6 << "grades: " << endl;
            for (multimap<double, int, greater<double>>::iterator mt = groupScore.begin(); mt != groupScore.end(); mt++)
            {
                cout << "Num: " << mt->second << "\tName: " << this->m_Speaker[mt->second].name << "\tScore: " << this->m_Speaker[mt->second].score[this->m_index - 1] << endl;
            }

            int count = 0;
            for (multimap<double, int, greater<double>>::iterator mt2 = groupScore.begin(); mt2 != groupScore.end() && count < 3; mt2++)
            {
                if (this->m_index == 1)
                {
                    v2.push_back(mt2->second);
                }
                else
                {
                    vVictory.push_back(mt2->second);
                }
                count++;
            }

            groupScore.clear();
        }
    }

    cout << "Round " << this->m_index << " is over !" << endl;
}

void SpeechManager::showScore()
{
    cout << "------------Round " << this->m_index << " good players is : ----------------------" << endl;
    vector<int> v;
    if (this->m_index == 1)
    {
        v = this->v2;
    }
    else
    {
        v = this->vVictory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "Num: " << *it << "\tName: " << this->m_Speaker[*it].name << "\tScore: " << this->m_Speaker[*it].score[this->m_index - 1] << endl;
    }
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); // 用追加的方式写文件

    // 将每个选手的数据写入到文件中
    for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
    {
        ofs << *it << "," << this->m_Speaker[*it].score[1] << ",";
    }
    ofs << endl;

    ofs.close();
    cout << "Record is saved !" << endl;
    this->fileEmpty = false;
}

void SpeechManager::startSpeech()
{
    // 第一轮开始比赛
    // 抽签
    this->speechDraw();
    // 比赛
    this->speechContest();
    // 显示晋级结果
    this->showScore();
    // 第二轮开始比赛
    this->m_index++;
    // 抽签
    this->speechDraw();
    // 比赛
    this->speechContest();
    // 显示最终结果
    this->showScore();
    // 保存分数到文件中
    this->saveRecord();

    // 重置比赛，获取记录。初始化容器和属性
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();

    cout << "Game Over !!!!" << endl;
}

void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in); //读文件
    if (!ifs.is_open())
    {
        this->fileEmpty = true;
        // cout << "File is not excits !" << endl;
        ifs.close();
        return;
    }

    // 文件清空情况
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "File is empty !" << endl;
        this->fileEmpty = true;
        ifs.close();
        return;
    }

    this->fileEmpty = false;
    ifs.putback(ch); //将上面读取的单个字符放回去

    string data;
    int index = 0;

    while (ifs >> data)
    {
        // 存放6个string字符串
        vector<string> v;

        // cout << data << endl;
        int pos = -1;
        int start = 0;

        while (true)
        {
            pos = data.find(",", start);

            if (pos == -1)
            {
                // 没有找到情况
                break;
            }
            string temp = data.substr(start, pos - start);
            // cout << temp << endl;
            v.push_back(temp);

            start = pos + 1;
        }

        this->m_record.insert(make_pair(index, v));
        index++;
    }

    ifs.close();

    // for (map<int, vector<string>>::iterator it = this->m_record.begin(); it != this->m_record.end(); it++)
    // {
    //     cout << it->first << "\tguanjun num: " << it->second[0] << "\t grade: " << it->second[1] << endl;
    // }
}

void SpeechManager::showRecord()
{
    if (this->fileEmpty)
    {
        cout << "File is not ecxist or empty !" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_record.size(); i++)
        {
            cout << i + 1 << " "
                 << "guanjun Num: " << this->m_record[i][0] << " score: " << this->m_record[i][1] << " "
                 << "yajun Num: " << this->m_record[i][2] << " score: " << this->m_record[i][3] << " "
                 << "jijun Num: " << this->m_record[i][4] << " score: " << this->m_record[i][5] << endl;
        }
    }
}

void SpeechManager::clearRecord()
{
    cout << "Do you want to delete?(y/n)" << endl;

    char select = 'a';
    cin >> select;

    if (select == 'y')
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        this->initSpeech();
        this->createSpeaker();
        this->loadRecord();

        cout << " Clear csv successfully !!!" << endl;
    }
    else
    {
        return;
    }
}