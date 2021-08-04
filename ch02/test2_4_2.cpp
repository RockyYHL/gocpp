#include <iostream>

using namespace std;

/*
        4.2 对象的初始化和清理
            C++中的面向对象来源于生活，每个对象都会有初始化设置以及对象销毁前的清理数据设置    
        4.2.1 构造函数和析构函数
            对象的初始化和清理也是两个非常重要的安全问题
            一个对象或者变量没有初始状态，对其使用后果是未知
            同样的使用完一个对象或变量，没有及时清理，也会造成一定的安全问题

            C++利用了构造函数和析构函数解决上述问题，这两个函数编译器自动调用，完成对象初始化和清理工作
            对象的初始化和清理工作是编译器强制我们要做的事情，因此如果我们不提供构造和析构，编译器会提供
            编译器提供的构造函数和析构函数是空实现

            构造函数：主要作用在于创建对象时为成员属性赋值，构造函数由编译器自动调用，无须手动调用
            析构函数：主要作用在于对象销毁前系统自动调用，执行一些清理工作

            构造函数语法： 类名（）{}
                1.构造函数，没有返回值也不写void
                2.函数名与类名相同
                3.构造函数可以有参数，因此可以发生重载
                4.程序在调用对象时会自动调用构造，无需手动调用，而且只会调用一次
            析构函数语法：～类名（）{}
                1.析构函数，没有返回值也不写void
                2.函数名与类名相同，在名称前加上～
                3.析构函数不可以有参数，因此不可以发生重载
                4.程序在对象销毁前会自动调用析构，无需手动调用而且只会调用一次

            4.2.2 构造函数的分类及调用
                两种分类方式：
                    按参数分为：有参构造和无参构造
                    按类型分：普通构造和拷贝构造
                三种调用方式：
                    括号法
                    显示法
                    隐式转换法
                注意事项：
                    1.调用默认构造函数时不要加（）  Person p();
                    2.不要利用拷贝构造函数初始化匿名对象  Person(p3) === Person p3 会被编译器认为是对象声明
                
                
    */

class Person
{
public:
    Person()
    {
        cout << "gouzao hanshu diaoyong" << endl;
    }
    Person(int a)
    {
        age = a;
        cout << "gouzao(int a) hanshu diaoyong" << endl;
    }
    Person(const Person &p)
    {
        age = p.age;
        cout << "gouzao(const Person &p) hanshu diaoyong" << endl; //拷贝构造
    }

    ~Person()
    {
        cout << "xigou hanshu diaoyong" << endl; // 在栈上的数据，程序执行完后，会释放这个对象
    }

    int age;
};

int main()
{

    Person p;
    Person p2(10);
    Person p3(p2);     // 括号法
    cout << p2.age << endl;
    cout << p3.age << endl;

    Person p4 = Person(20);   // 显示法
    Person p5 = Person(p4);

    Person(30);   // 匿名对象，当前行执行结束后，系统会立即回收
    cout << "ok" << endl;

    Person p6 = 10;    // 隐式法，相当于 Person p6 = Person(10);
    Person p7 = p6;

    return 0;
}