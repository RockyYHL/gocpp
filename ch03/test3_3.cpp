#include <iostream>
using namespace std;
#include <deque>
#include<algorithm>   // 标准算法头文件

/*
    3.3 deque容器

    3.3.1 deque容器基本概念
        功能：双端数组，可以对头端进行插入删除操作
        deque与vector区别：
            - vector对于头部的插入删除效率低，数据量越大，效率越低
            - deque相对而言，对头部的插入删除速度比vector快
            - vector访问元素时的速度会比deque快，这和两者内部实现有关
        deque内部工作原理：
            deque内部有个中控器，维护每段缓冲区中的内容，缓冲区存放真实数据
            中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
        deque容器的迭代器也是支持随机访问的
    
    3.3.2 deque构造函数
        与vector基本一致
    
    3.3.3 deque赋值操作
        与vector基本一致
    
    3.3.4 deque大小操作
        功能描述：对deque容器的大小进行操作
        没有capacity，可以无线加

    3.3.4 deque插入和删除操作
        多了   push_front/pop_front

    3.3.6 数据存取
        功能描述：对deque中的数据的存取操作
        d.front(); //返回第一个元素
        d.back();  //返回最后一个元素

    3.3.7 deque排序
        功能描述：利用算法实现对deque容器进行排序


*/
void printDeque(const deque<int> d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)   //const限定为只读状态
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());  // 构造函数区间方式赋值
    printDeque(d2);

    deque<int> d3(10, 100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);

}

void test02(){
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    if(d1.empty()){
        cout << "d1 is empty" << endl;
    }else{
        cout << "d1 is not empty" << endl;

    }
}

void test03(){
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    // 对于支持随机访问的迭代器的容器，都可以利用sort算法直接进行排序
    sort(d1.begin(), d1.end());     // 升序
    printDeque(d1);


}

int main()
{

    // test01();
    // test02();
    test03();

    return 0;
}