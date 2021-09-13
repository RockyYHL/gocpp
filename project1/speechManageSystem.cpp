#include <iostream>
using namespace std;
#include "speechManager.h"

int main()
{
    // 创建管理类对象
    SpeechManager sm;

    // 测试
    // for(map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it !=sm.m_Speaker.end(); it++){
    //     cout << "num: " << it->first << "\tname: " << it->second.name << endl;
    // }

    int choice = 0;

    while (true)
    {
        sm.showMenu();

        cout << "Please input your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: //开始比赛
            sm.startSpeech();
            break;
        case 2: //查看往届比赛记录
            sm.showRecord();
            break;
        case 3: // 清空比赛记录
            sm.clearRecord();
            break;
        case 0: // 退出系统
            sm.exitSystem();
            break;
        
        default:
            break;
        }
    }

    return 0;
}