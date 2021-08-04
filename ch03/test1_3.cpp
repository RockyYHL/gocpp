#include <iostream>
using namespace std;

/*
    1.3类模板

        1.3.1类模板语法
            类模板作用： 建立一个通用类，类中的成员、数据类型可以不具体定制，用一个虚拟的类型来代表

            语法:
                template<typename T>
                类
            解释：
                template -- 声明创建模板
                typename -- 表名其后面的符号是一种数据类型，可以使用class代替
                T -- 通用的数据类型，名称可以替换，通常为大写字母
            
            总结：
                类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板

        1.3.2类模板和函数模板的区别
            类模板与函数模板的区别主要有两点：
                1.类模板没有自动类型推导的使用方式
                2.类模板在模板参数列表中可以有默认参数

        1.3.3类模板中成员函数的创建时机
            类模板中成员函数和普通类中成员函数创建时机是有区别的：
                - 普通类中的成员函数一开始就可以创建
                - 类模板中的成员函数在调用时才创建

            总结： 类模板中的成员函数并不是一开始就创建的，在调用时才去调用
            

*/

template <class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_age = age;
        this->m_name = name;
    }

    void show()
    {
        cout << "name: " << this->m_name << endl;
        cout << "m_age: " << this->m_age << endl;
    }

    NameType m_name;
    AgeType m_age;
};

void test01()
{
    Person<string, int> p1("Jack", 20);
    p1.show();
}

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};

template <class T>
class myClass
{
public:
    T obj;

    void func1(){
        obj.showPerson1();
    }

    void func2(){
        obj.showPerson2();
    }
};

void test02(){
    myClass<Person1> p1;
    p1.func1();
    // p1.func2();
}

int main()
{

    // test01();
    test02();
    return 0;
}