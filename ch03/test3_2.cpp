#include <iostream>
#include <vector>
using namespace std;

/*
    3.2 vector容器
    
    3.2.1 vector基本概念
        功能： vector数据结构和数组非常相似，也成为单端数组
        vector与普通数组的区别：
            不同之处在于数组是静态空间，而vector可以动态扩展
        动态扩展：
            并不是在原空间之后续接新空间，而是找更大的内存空间，然后将源数据拷贝新空间，释放原空间
            vector容器的迭代器是支持随机访问的迭代器

    3.2.2 vector构造函数

    3.2.3 vector赋值操作

    3.2.4 vector容量和大小
        功能描述：
            对vector容器的容量和大小操作
        函数原型：
            empty();                    // 判断容器是否为空
            capacity();                 // 容器的容量
            size();                     // 返回容器中元素的个数
            resize(int num);            // 重新指定容器的长度为num,若容器变长，则以默认方式填充新位置
                                        // 如果容器变短，则末尾超出容器长度的元素被删除
            resize(int num, elem)       // 重新指定容器的长度为num，若容器变长，则以elem值填充新位置
                                        // 如果容器变短，则末尾超出容器长度的元素被删除

    3.2.5 vector插入和删除
        功能描述： 对vector容器进行插入，删除操作

        函数原型：
            - push_back(ele);               //  尾部插入元素ele
            - pop_back();                   // 删除最后一个元素
            - insert(const_iterator pos, ele);  // 迭代器指向位置pos插入元素
            - insert(const_iterator pos, int count, ele);   // 迭代器指向位置pos插入count个元素ele
            - erase(const_iterator pos);        // 删除迭代器指向的元素
            - erase(const_iterator start, const_iterator end);  // 删除迭代器从start到end之间的元素
            - clear();                      // 删除元素内所有的元素
             
    3.2.6 vector数据存取
         功能描述： 对vector中的数据的存取操作

        函数原型：
            - at(int idx);  // 返回索引idx指向的数据
            - operator[];   // 返回索引idx所指向的数据
            - front();         //返回容器中第一个数据元素
            - back();           // 返回容器中最后一个元素

    3.2.7 vector互换容器
        功能描述： 实现两个容器内元素进行互换
        函数原型：
            - swap(vec);    // 将vec与本身的元素互换
        总结：swap可以使用两个容器互换，可以达到使用的收缩内存的效果
    
    3.2.8 vector预留空间
        功能描述：减少vector在动态扩展时的扩展次数
        函数原型：
            - reserve(int len); // 容器预留len个元素长度，预留位置不初始化，元素不可访问

            


*/

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    // 通过区间方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // n个elem方式构造
    vector<int> v3(10, 100); // 10 个 100
    printVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

void test02()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

void test03()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty())
    {
        cout << "v1 is empty" << endl;
    }
    else
    {
        cout << "v1 is not empty" << endl;
        cout << "v1 capacity is " << v1.capacity() << endl;
        cout << "v1 size is " << v1.size() << endl;
    }

    v1.resize(15, 100);
    printVector(v1);

    v1.resize(5);
    printVector(v1);
}

void test04()
{
    vector<int> v;
    // 尾插
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    printVector(v);

    // 尾删
    v.pop_back();
    printVector(v);

    //插入,第一个参数是迭代器
    v.insert(v.begin(), 100);
    printVector(v);

    v.insert(v.begin(), 2, 1000);
    printVector(v);

    // 删除,参数也是迭代器
    v.erase(v.begin() + 2);
    printVector(v);

    // 清空
    v.clear();
    printVector(v);
}

void test05(){
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i >0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    v1.swap(v2);
    printVector(v1);
    printVector(v2);


}

// vector.swap实际用途：
// 巧用swap可以收缩内存空间
void test06(){
    vector<int> v1;
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
    }

    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 size: " << v1.size() << endl;

    v1.resize(3);
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 size: " << v1.size() << endl;

    /*
        vector<int>(v1)匿名对象，拷贝构造函数创造新的对象，按照v1的size来初始化
        本质是指针交换
        匿名对象的空间在当前行结束后就释放掉了，自动执行析构
    */
    vector<int>(v1).swap(v1);
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 size: " << v1.size() << endl;

}

void test07(){
    vector<int> v1;

    // 利用reserve来预留空间
    v1.reserve(100000);

    int num = 0; //统计开辟次数
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);

        if(p != &v1[0]){
            p = &v1[0];
            num++;
        }
    }

    cout << "num : " << num << endl;   //看看插10万个数，分配了多少次内存，动态扩展
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