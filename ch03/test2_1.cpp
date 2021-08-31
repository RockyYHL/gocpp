#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
    2 STL初识

    2.1 STL的诞生
        - 长久以来，软件界一直希望建立一种可重复利用的东西
        - C++的面向对象和泛型编程思想，目的就是复用性的提升
        - 大多情况下，数据结构和算法一直都未能有一套标准，导致被迫从事大量重复工作
        - 为了建立数据结构和算法的一套标准，诞生了STL
    
    2.2 STL基本概念
        - STL（Standard Template Library，标准模板库）
        - STL从广义上分为： 容器（container）、算法（algorithm）、迭代器（Iterator）
        - 容器和算法之间通过迭代器进行无缝连接
        - STL几乎所有的代码都采用了模板类或者模板函数

    2.3 STL六大组件
        STL大体分为六大组件，分别是容器、算法、迭代器、仿函数、适配器（配接器）、空间配置

        1. 容器：各种数据结构，如vector、list、deque、set、map等，用来存放数据
        2. 算法：各种常用的算法，如sort、find、copy、for_each等
        3. 迭代器：扮演了容器与算法之间的胶合剂
        4. 仿函数：行为类似函数，可以作为算法的某种策略
        5. 适配器：一种用力啊修饰容器或者仿函数或迭代器接口的东西
        4. 空间配置器：负责空间的配置与管理

    2.4 STL中容器、算法、迭代器
        容器：置物之所也
        STL容器就是将运用最广泛的一些数据结构实现出来
        常用的数据结构：数组，链表，树，栈，队列，集合，映射表 等
        这些容器分为序列式容器和关联式容器两种：
            序列式容器：强调值的排序，序列式容器中的每个元素均有固定的位置
            关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系
        
        算法：问题之解法也
        有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法（algorithm）
        算法分为质变算法和非质变算法
        质变算法： 是指运算过程中会更改区间内的元素的内容，例如拷贝，替换，删除等等
        非质变算法：是指运算过程中不会更改区间的元素内容，例如查找、计数、遍历、寻找极值等等

        迭代器：容器和算法之间的粘合剂
        提供一种方法： 是之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式
        每个容器都有自己的迭代器
        迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针

        迭代器种类：
        输入迭代器    | 对数据的只读访问                                   | 只读，支持 ++、==、！=
        输出迭代器    | 对数据的只写访问                                   | 只写，支持 ++
        前向迭代器    | 读写操作，并能向前推进迭代器                         | 读写，支持 ++、==、！=
        双向迭代器    | 读写操作，并能向前和向后操作                         | 读写，支持 ++、--
        随机访问迭代器 | 读写操作，可以跳跃的方式访问任意数据，功能是最强的迭代器  |读写，支持 ++、--、[n]、-n、<、<=、>、>=

        常用的容器中迭代器种类分为双向迭代器，和随机访问迭代器

    2.5 容器算法迭代器初识
        了解STL中容器、算法、迭代器概念之后，我们利用代码感受STL的魅力
        STL中最常用的容器为vector， 可以理解为数组，下面我们将学习如何向这个容器中插入数据，并遍历这个容器

        2.5.1 vector存放内置数据类型
            容器：vector
            算法：for_each
            迭代器：vector<int>::iterator

        2.5.2 Vector存放自定义数据类型
            学习目标： vector中存放自定义数据类型，并打印输出
        
        2.5.3 Vector容器嵌套容器
            学习目标：容器中嵌套容器，我们将所有数据进行遍历输出



 



*/

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    // 创建一个vector容器，数组
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(60);
    v.push_back(80);
    v.push_back(30);

    vector<int>::iterator itBegan = v.begin(); // 起始迭代器，指向容器中的第一个元素
    vector<int>::iterator itEnd = v.end();     // 结束迭代器，指向容器中最后一个元素的下一个位置

    // // 第一种遍历方式
    // while (itBegan != itEnd)
    // {
    //     cout << *itBegan << endl;
    //     itBegan++;
    // }

    // // 第二种遍历方式
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // 第三种遍历方式，利用STL中提供的遍历算法
    for_each(v.begin(), v.end(), myPrint);
}

void printVector(vector<vector<float>> frame_info)
{
    if (frame_info.empty())
    {
        cout << "The vector is empty!" << endl;
        return;
    }

    int i, j;
    cout << "Use index : " << endl;
    for (i = 0; i < frame_info.size(); i++)
    {
        for (j = 0; j < frame_info[0].size(); j++)
            cout << "frame_info: " << frame_info[i][j] << " ";
        cout << "---------" << i << "---------" << endl;
    }
    cout << "**************************" << endl;
}

void testother()
{
    static vector<vector<float>> frame_info; //初始化row*column二维动态数组，初始化值为0
    vector<float> object_info;
    object_info.push_back(20 + 60);
    object_info.push_back(20 + 60);
    object_info.push_back(40 + 60);
    object_info.push_back(40 + 60);
    object_info.push_back(0);
    object_info.push_back(0);
    object_info.push_back(0);
    object_info.push_back(0);
    object_info.push_back(0);

    frame_info.push_back(object_info);

    printVector(frame_info);
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_age = age;
        this->m_name = name;
    }

    string m_name;
    int m_age;
};

void test02()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 60);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << (*it).m_name << "\t"
             << "age: " << (*it).m_age << endl;
    }
}

// 存放自定义数据类型 指针
void test03()
{
    vector<Person *> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 60);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << (**it).m_name << '\t' << "age: " << (**it).m_age << endl;
    }
}

void test04()
{
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++){
        // cout << (*it) << endl;
        for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++){
            cout << (*it2) << " ";
        }
        cout << endl;
    }
}

int main()
{

    // test01();
    // testother()
    // test02();
    // test03();
    test04();
    return 0;
}