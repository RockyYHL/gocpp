#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

/*
    4.3 内建函数对象
    4.3.1 内建函数对象意义
        概念：
            - STL内建了一些函数对象
        分类：
            - 算数仿函数
            - 关系仿函数
            - 逻辑仿函数
        用法：
            - 这些仿函数所产生的对象，用法和一般函数完全相同
            - 使用内建函数对象，需要引入头文件 #include<functional>

    4.3.2 算术仿函数
        功能描述：
            - 实现四则运算
            - 其中negative是一元运算，其他都是二元运算

    4.3.3 关系仿函数
        功能描述：
            实现关系对比

    4.3.4 逻辑仿函数
        -功能描述： 实现逻辑运算


*/

void test01()
{
    negate<int> n;
    cout << n(50) << endl;
}

void test02()
{
    plus<int> p;
    cout << p(10, 20) << endl;
}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

//关系仿函数
void test03()
{
    vector<int> v;
    v.push_back(21);
    v.push_back(32);
    v.push_back(3);
    v.push_back(365);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), MyCompare());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    sort(v.begin(), v.end(), MyCompare());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 逻辑仿函数
void test04()
{
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    // 利用逻辑非，将容器v搬运到v2中，并执行取反的操作
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), v2.end(), logical_and<bool>());

    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

}

int main()
{

    // test01();
    // test02();
    // test03();
    test04();
    return 0;
}
