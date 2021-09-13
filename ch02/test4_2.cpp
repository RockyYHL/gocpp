#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    4.2 谓词
    4.2.1 谓词概念
        概念：
         - 返回bool类型的仿函数成为谓词
         - 如果operator（）接受一个参数，那么叫做一元谓词
         - 如果operator（）接受两个参数，那么叫做二元谓词

    4.2.2 一元谓词
*/

class CreateFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 查找容器中是否有大于5的元素
    vector<int>::iterator it = find_if(v.begin(), v.end(), CreateFive());
    if (it == v.end())
    {
        cout << "Not find !" << endl;
    }
    else
    {
        cout << "Find it: " << *it << endl;
    }
}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(60);
    v.push_back(20);
    v.push_back(13);
    v.push_back(17);

    sort(v.begin(), v.end());
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // 使用函数对象，改变排序规则
    sort(v.begin(), v.end(), MyCompare());
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

}

int main()
{

    // test01();
    test02();
    return 0;
}