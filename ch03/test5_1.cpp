#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

/*
    5 STL常用算法
        概述：
            - 算法主要是由头文件<algorithm> <functional> <numeric>组成
            - <algorithm>是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等等
            - <numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
            - <functional>定义了一些模板类，可以声明函数对象

    5.1 常用遍历算法
        算法简介：
            - for_each  //遍历容器
            - transform   //搬运容器到另一个容器中

    5.2 常用查找算法
        算法简介：
            - find  // 查找元素,返回值是迭代器
            - find_if   // 按条件查找
            - adjacent_find // 查找相邻重复元素
            - binary_search // 二分查找法,无序序列不可用
            - count // 统计元素个数
            - count_tf  // 按条件统计元素个数

*/

void print01(int val)
{
    cout << val << " ";
}

class Print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), print01); // 非常常用遍历算法
    for_each(v.begin(), v.end(), Print02());
}

class Transform
{
public:
    int operator()(int v)
    {
        return v + 100;
    }
};

void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> vTarget;
    vTarget.resize(v.size()); // 需要先指定目标容器大小
    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for (vector<int>::iterator it = vTarget.begin(); it != vTarget.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    bool operator==(const Person &p)
    {
        if (this->age = p.age && this->name == p.name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string name;
    int age;
};

void test03()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if (pos == v.end())
    {
        cout << "Not find" << endl;
    }
    else
    {
        cout << "Find it" << endl;
    }

    vector<Person> vP;
    Person p1("Tom", 23);
    Person p2("Jerry", 33);
    Person p3("Jack", 4);
    vP.push_back(p1);
    vP.push_back(p2);
    vP.push_back(p3);

    vector<Person>::iterator posP = find(vP.begin(), vP.end(), p2);
    if (posP == vP.end())
    {
        cout << "Not find p2" << endl;
    }
    else
    {
        cout << "Find it p2" << endl;
    }
}

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test04()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
    if (pos == v.end())
    {
        cout << "Not find >5" << endl;
    }
    else
    {
        cout << "Find it >5" << endl;
    }
}

void test05()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(3);

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos == v.end())
    {
        cout << "Not find " << endl;
    }
    else
    {
        cout << "Find it " << *pos << endl;
    }
}

void test06()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(3);

    sort(v.begin(), v.end()); // 必须是有序数列

    bool ret = binary_search(v.begin(), v.end(), 2);

    if (ret)
    {
        cout << "Find it" << endl;
    }
    else
    {
        cout << "Not Find" << endl;
    }
}

class Person2
{
public:
    Person2(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    bool operator==(const Person2 &p)
    {
        if (this->age == p.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string name;
    int age;
};

void test07()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(3);

    int num = count(v.begin(), v.end(), 3);
    cout << num << endl;

    vector<Person2> vP;
    Person2 p1("A", 20);
    Person2 p2("B", 22);
    Person2 p3("C", 21);
    Person2 p4("D", 27);

    vP.push_back(p1);
    vP.push_back(p2);
    vP.push_back(p3);
    vP.push_back(p4);

    Person2 pt("E", 21);

    int num2 = count(vP.begin(), vP.end(), pt);
    cout << num2 << endl;
}

class Greater20
{
public:
    bool operator()(int val)
    {
        return val > 20;
    }
};

class Greater15
{
public:
    bool operator()(const Person& p)
    {
        return p.age > 20;
    }
};

void test08()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(3);

    int ret = count_if(v.begin(), v.end(), Greater20());
    cout << ret << endl;
}

void test09()
{
    vector<Person> vP;
    Person p1("A", 20);
    Person p2("B", 22);
    Person p3("C", 21);
    Person p4("D", 27);
    vP.push_back(p1);
    vP.push_back(p2);
    vP.push_back(p3);
    vP.push_back(p4);
    

    int ret = count_if(vP.begin(), vP.end(), Greater15());
    cout << ret << endl;
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    // test08();
    test09();
    return 0;
}