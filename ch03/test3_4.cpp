#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
// #include<string>
using namespace std;

/*
    3.4 案例-评委打分

    3.4.1 案例描述
        有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委最低分，取平均分
    
    3.4.2 实现步骤
        1.创建五名选手，放到vector中
        2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分，可以把10个评分打分存到deque容器中
        3.sort算法对deque容器中分数排序，去除最高和最低分
        4.deque容器遍历一遍，累加总分
        5.获取平均分
*/

class Person
{
public:
    Person(string name, int score)
    {
        this->name = name;
        this->score = score;
    }

    string name;
    int score;
};

void createPerson(vector<Person> &v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "player";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);
        v.push_back(p);
    }
}

void printPersonVector(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << it->name << "\t"
             << "score: " << it->score << endl;
    }
}

void setScore(vector<Person> &v){
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 将评委的分数，放入到deque中
        deque<int> d;
        for(int i = 0; i < 10; i++){
            int score = rand() % 41 + 60;
            d.push_back(score);
        }
        sort(d.begin(), d.end());

        d.pop_front();
        d.pop_back();

        cout << it->name << " score:\t";
        int sum = 0;
        for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++){
            sum += *dit;
            cout << *dit << "\t";
        }
        cout << endl;

        int avg = sum / d.size();

        // 将分数赋值到选手上
        it->score = avg;

    }
}

int main()
{
    // 随机数种子
    srand((unsigned int) time(NULL));

    // 1.创建五名选手
    vector<Person> v;
    createPerson(v);
    // printPersonVector(v);

    // 2.打分
    setScore(v);
    
    // 3.显示最后得分
    printPersonVector(v);

    return 0;
}