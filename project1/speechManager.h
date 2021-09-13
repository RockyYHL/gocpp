#pragma once // 防止头文件重复包含
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>

//设计演讲比赛管理类
class SpeechManager
{
public:
    SpeechManager();
    ~SpeechManager();
    void showMenu();
    void exitSystem();
    void createSpeaker();
    void startSpeech();
    void speechDraw();
    void speechContest();
    void showScore();
    void saveRecord();
    // 初始化容器和属性
    void initSpeech();
    void loadRecord();
    void showRecord();
    void clearRecord();

    // 比赛选手 容器 12 人
    vector<int> v1;
    // 第一轮晋级容器  6人
    vector<int> v2;
    // 胜利前三名容器 3人
    vector<int> vVictory;
    //存放编号以及对应的具体选手容器
    map<int, Speaker> m_Speaker;
    // 记录比赛轮数
    int m_index;
    // 文件是否为空
    bool fileEmpty;
    // 往届记录
    map<int, vector<string>> m_record;

};