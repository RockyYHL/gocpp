#include <iostream>
using namespace std;

/*
    4.2.3 拷贝构造函数的调用时机
        C++中的拷贝构造函数通常有三种情况：
            - 使用一个已经创建完毕的对象来创建一个新对象
            - 值传递方式给函数参数传值
            - 以值方式返回局部对象

    4.2.4 构造函数调用规则
        默认情况下，C++编译器至少给一个类添加3个函数
            1.默认构造函数（无参，函数体为空）
            2.默认析构函数（无参，函数体为空）
            3.默认拷贝构造函数，对属性进行拷贝

        构造函数调用规则如下：
            - 如果用户定义有参构造函数，C++ 不在提供默认无参构造，但会调用默认拷贝构造
            - 如果用户定义拷贝构造函数，C++ 不会在提供其他构造函数

    4.2.5 深拷贝和浅拷贝
        深拷贝和浅拷贝是面试经典问题，也是常见的一个坑
        浅拷贝：简单的赋值 (带来的问题，堆区的内存二次释放)
        深拷贝：在堆区重新申请空间，进行拷贝操作

        总结：如果属性有在堆区开辟的，需要自己释放堆区内存，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

    4.2.6 初始化列表
        作用：C++ 提供了初始化列表语法，用来初始化属性
        语法：构造函数（）：属性1（值1），属性2（值2）。。。

*/
class Person
{

public:
    Person()
    {
        cout << "gouzao hanshu diaoyong" << endl;
    }
    Person(int age)
    {
        m_age = age;
        cout << "gouzao(int age) hanshu diaoyong" << endl;
    }
    Person(int age, int height)
    {
        m_age = age;
        // m_height = new int(height);
    }

     Person(int age, int B, int C)
    {
        m_age = age;
        m_B = B;
        m_C = C;
    }

    // 列表初始化属性
    // Person(int a, int b, int c) : m_age(10), m_B(20), m_C(30) {}

    Person(const Person &p)
    {
        // m_age = p.m_age;
        cout << "gouzao(copy) hanshu diaoyong" << endl;
        m_age = p.m_age;
        // m_height = new int(*p.m_height);
    }

    ~Person()
    {
        // if (m_height != NULL)
        // {
        //     delete m_height;
        //     m_height = NULL;
        // }
        cout << "xigou hanshu diaoyong" << endl;
    }

    int m_age;
    // int *m_height;
    int m_B;
    int m_C;
};

void test01()
{
    Person p1(20);
    Person p2(p1);
}

void doWork(Person p)
{
}

void test02()
{
    Person p;
    doWork(p);
}

Person doWork2()
{
    Person p1(30);
    return p1;
}

void test03()
{
    Person p = doWork2();
    cout << p.m_age << endl;
    p.m_age = 1000;
    cout << p.m_age << endl;
}

void test04()
{
    Person p;
    p.m_age = 18;

    Person p2(p);
    cout << "p2 s age is :" << p2.m_age << endl;
}

void test05()
{
    Person p1(18, 160);
    cout << "p1 s age is : " << p1.m_age << endl;
    // cout << "p1 s height is : " << *p1.m_height << endl;

    Person p2(p1);
    cout << "p2 s age is : " << p2.m_age << endl;
    // cout << "p1 s height is : " << *p2.m_height << endl;
}

void test06()
{
    Person p;
    cout << "p.m_age: " << p.m_age << endl;
    cout << "p.m_B: " << p.m_B << endl;
    cout << "p.m_C: " << p.m_C << endl;
}

void test07()
{
    Person p(10, 20, 30);
    cout << "p.m_age: " << p.m_age << endl;
    cout << "p.m_B: " << p.m_B << endl;
    cout << "p.m_C: " << p.m_C << endl;
}

void test08(){
    Person p1(20);
    Person p2(p1);
}

int main()
{
    // test01();
    // test02();
    test03();
    // test04();
    // test05();
    // test07();
    // test08();
    return 0;
}