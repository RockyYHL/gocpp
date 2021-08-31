#include <iostream>
using namespace std;
#include <map>

/*
    3.9 map/multimap容器

    3.9.1 map基本概念
        简介：
            - map中所有元素都是pair
            - pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
            - 所有元素都会根据元素的键值自动排序
        本质：
            - map/multimap数据关联式容器，底层结构是二叉树实现
        优点：
            - 可以根据key值快速找到value值
        map和multimap区别：
            - map不允许容器中有重复的key值元素
            - multimap中允许容器中有重复的key值元素

    3.9.2 map构造和赋值
        功能描述：
            - 对map中进行构造和赋值操作

    3.9.3 map大小和交换
        功能描述：
            - 统计map容器大小以及交换map容器
        size()/empty()/m.swap(m2)

    3.9.4 map插入和删除
        功能描述：
            - map容器进行插入数据和删除数据

    3.9.5 map查找和统计
        功能描述：
            对map容器进行查找数据以及统计数据
        函数原型：
            - find(key)
            - cout(key)

    3.9.10 map 容器排序
        学习目标：map容器默认排序规则为，按照key值进行从小到大排序，掌握如何改变排序规则
        主要技术点：利用仿函数，可以改变排序规则

*/

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << (*it).first << "\tvalue: " << (*it).second << endl;
    }
    cout << endl;
}



void test01()
{
    //创建map容器
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(5, 13));
    m.insert(pair<int, int>(2, 30));
    m.insert(pair<int, int>(4, 50));
    printMap(m);

    // map<int, int> m2(m);
    // printMap(m2);

    // map<int, int> m3 = m;
    // printMap(m3);

    cout << "map size: " << m.size() << endl;
    cout << "map empty:" << m.empty() << endl;

    map<int, int> m4;
    m4.insert(pair<int, int>(32, 10));
    m4.insert(pair<int, int>(4, 13));
    m4.insert(pair<int, int>(5, 30));
    m4.insert(pair<int, int>(532, 50));
    m4.insert(pair<int, int>(77, 50));
    printMap(m4);

    m.swap(m4);
    printMap(m);
    printMap(m4);
}

void test02()
{
    map<int, int> m;
    // 插入第一种
    m.insert(pair<int, int>(1, 10));
    // 第二种
    m.insert(make_pair(4, 90));
    // 第三种
    m.insert(map<int, int>::value_type(2, 30));
    // 第四种 主要是用来访问
    m[5] = 20;
    printMap(m);

    // 删除
    m.erase(m.begin());
    // 按照key删
    m.erase(5);

    printMap(m);
}

// 利用仿函数，自己设置排序规则
// 对于自定义数据类型，必须要自己设置排序规则
class myCompare
{
public:
    bool operator()(int v1, int v2){
        return  v1 > v2;
    }
};

void printMapC(map<int, int, myCompare> &m)
{
    for (map<int, int, myCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << (*it).first << "\tvalue: " << (*it).second << endl;
    }
    cout << endl;
}

void test03()
{
    map<int, int, myCompare> m4;
    m4.insert(pair<int, int>(1, 10));
    m4.insert(pair<int, int>(2, 13));
    m4.insert(pair<int, int>(3, 30));
    m4.insert(pair<int, int>(4, 50));
    m4.insert(pair<int, int>(5, 50));
    printMapC(m4);
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}