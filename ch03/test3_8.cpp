#include <iostream>
using namespace std;
#include <set>

/*
    3.8 set/multiset容器

    3.8.1 set基本概念
        简介： 所有元素都会在插入时自动被排序
        本质：set/multiset属于关联式容器，底层结构是用二叉树实现
        set和multiset区别：
            - set不允许容器中有重复的元素
            - multiset允许容器中有重复的元素
        
    3.8.2  set构造和赋值
        功能描述：创建set容器以及赋值

    3.8.3 set大小和交换
        功能统计： 统计set容器大小以及交换set容器
        size()/empty()/swap(s2)
        set不支持resize，不可以指定容器的大小

    3.8.4 set插入和删除
        功能描述： set容器进行插入数据和删除数据
        函数原型：
            - insert（elem);
            - clear();
            - erase(pos);  // 删除pos迭代器所指的元素，返回下一个元素的迭代器
            - erase(beg, end);  //删除区间所有元素，返回下一个元素的迭代器
            - erase(elem); 

    3.8.5 set查找和统计
        功能描述：
            - 对set容器进行查找数据以及统计数据
        函数原型：
            - find(key);    // 查找key是否存在，返回该键的元素的迭代器，若不存在，返回set.end()
            - count(key);   // 统计key元素的个数
    
    3.8.6 set和multiset区别
        学习目标： 掌握set和multiset的区别
        区别：
            - set不可以插入重复数据，而multiset可以
            - set插入数据的同时会返回插入结果，表示是否插入成功
            - multiset不会检测数据，因此可以插入重复数据

    3.8.7 pair对组创建
        功能描述：
            成对出现的数据，利用对组可以返回两个数据

    3.8.8 set容器排序
        学习目标： set容器默认排序规则为从小到大，掌握如何改变排序规则
        主要技术点：
            利用仿函数，改变排序规则

    3.8.9 set自定义数据类型怎么排序
    
*/
void printSet(const set<int> &s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    // set只有insert方式
    s1.insert(23);
    s1.insert(34);
    s1.insert(87);
    s1.insert(12);
    s1.insert(23);

    printSet(s1);

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值
    set<int> s3 = s2;
    printSet(s3);
}

void test02()
{
    set<int> s1;
    // set只有insert方式
    s1.insert(23);
    s1.insert(34);
    s1.insert(87);
    s1.insert(12);
    s1.insert(23);
    printSet(s1);

    set<int>::iterator it = s1.begin();
    set<int>::iterator itNew = s1.erase(it);
    printSet(s1);
    cout << *itNew << endl;

    // cout << s1.erase(it) << endl;
}

void test03()
{
    set<int> s1;
    // set只有insert方式
    s1.insert(23);
    s1.insert(34);
    s1.insert(87);
    s1.insert(12);
    s1.insert(23);
    printSet(s1);

    set<int>::iterator pos = s1.find(23);
    if (pos != s1.end())
    {
        cout << "find it " << *pos << endl;
    }
    else
    {
        cout << "not find" << endl;
    }

    // 对于set而言，0 、 1
    int num = s1.count(23);
    cout << num << endl;
}

void test04()
{
    set<int> s1;
    // set只有insert方式
    s1.insert(23);
    s1.insert(34);
    s1.insert(87);
    s1.insert(12);
    s1.insert(23);
    printSet(s1);

    // 插入成功后会返回 一个数据
    pair<set<int>::iterator, bool> ret = s1.insert(10);

    if (ret.second)
    {
        cout << "success" << endl;
    }
    else
    {
        cout << "failed" << endl;
    }
    // 重复插入
    ret = s1.insert(10);

    if (ret.second)
    {
        cout << "success" << endl;
    }
    else
    {
        cout << "failed" << endl;
    }

    multiset<int> s2;
    multiset<int>::iterator ret2 = s2.insert(10);
    cout << *ret2 << endl;
    ret2 = s2.insert(10);
    cout << *ret2 << endl;
}

void test05()
{
    // 1.
    pair<int, string> p1(1, "Tom");
    cout << "age: " << p1.first << endl;
    cout << "name: " << p1.second << endl;

    // 2.
    pair<string, int> p2 = make_pair("Fuck", 2);
    cout << "age: " << p2.first << endl;
    cout << "name: " << p2.second << endl;
}

bool compareSet(int &n1, int &n2)
{
    return n1 > n2;
}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test06()
{
    set<int> s1;
    // set只有insert方式
    s1.insert(23);
    s1.insert(34);
    s1.insert(87);
    s1.insert(12);
    s1.insert(23);
    printSet(s1);

    set<int, MyCompare> s2;
    // set只有insert方式
    s2.insert(23);
    s2.insert(34);
    s2.insert(87);
    s2.insert(12);
    s2.insert(23);

    for (set<int, MyCompare>::const_iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

class Person
{
public:
    string name;
    int age;

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

class MyCompare2
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.age > p2.age;
    }
};

void test07()
{
    Person p1("A", 20);
    Person p2("B", 30);
    Person p3("C", 50);
    Person p4("D", 10);

    set<Person, MyCompare2> s1;
    // 自定义的数据类型需要指定规则， 利用仿函数
    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);

    for (set<Person>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << it->age << " " << it->name;
    }
}

int main()
{

    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    test07();
    return 0;
}