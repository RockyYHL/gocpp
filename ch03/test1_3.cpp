#include <iostream>
#include "Person7.hpp"
#include "MyArray.hpp"
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

        1.3.4类模板做函数参数
            学习目标：
                - 类模板实例化出的对象，向函数传参的方式

            一共有三种传入方式：
                1.指定传入的类型 -- 直接显示对象的数据类型
                2.参数模板化 -- 将对象中的参数变为模板进行传递
                3.整个类模板 -- 将这个对象类型 模板化进行传递

            总结：　
                通过类模板创建的对象，可以有三种方式向函数中传参
                第1种是最常用的：指定传入的类型

        1.3.5类模板与继承
            当类模板碰到继承时，需要注意以下几点：
                - 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
                - 如果不指定，编译器无法给子类分配内存
                - 如果想灵活制定出父类中T的类型，子类也需变为类模板

        1.3.6类模板成员函数类外实现
            学习目标: 能够掌握类模板中的成员函数类外实现

        1.3.7类模板分文件编写
            学习目标：
                - 掌握类模板成员函数分文件编写产生的问题以及解决方式
            问题：
                - 类模板中成员函数创建时机是在调用阶段，导致文件编写时链接不到
            解决：
                - 解决方式1： 直接包含.cpp源文件
                - 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp, .hpp是约定的名称，并不是强制

        1.3.8类模板和友元
            学习目标：
                - 掌握类模板配合友元函数的类内和类外实现
            全局函数类内实现 - 直接在类内声明友元即可
            全局函数类外实现 - 需要提前让编译器知道全局函数的存在  

        1.3.9类模板案例
            案例描述： 
                实现一个通用的数组类，要求如下：
                    - 可以对内置数据类型以及自定义数据类型的数据进行存储
                    - 将数组中的数据存储到堆区
                    - 构造函数中可以传入数组的容量
                    - 提供对应的拷贝构造函数以及operator 防止浅拷贝问题
                    - 提供尾插法和尾删法对数组中的数据进行增加和删除
                    - 可以通过下标的方式访问数组中的元素
                    - 可以获取数组中当前元素个数和数组的容量
            
            伪代码：
                class MyArray{
                private:
                    T * pAddress;    // 数组
                    m_capacity;     // 容量
                    m_size;        // 大小

                public:
                    构造函数（容量）
                    拷贝构造
                    operator=
                    利用下标方式访问数组中的元素
                    尾插法
                    尾删法
                    获取数组容量
                    获取数组大小
                    析构函数

                }


            

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

    void func1()
    {
        obj.showPerson1();
    }

    void func2()
    {
        obj.showPerson2();
    }
};

void test02()
{
    myClass<Person1> p1;
    p1.func1();
    // p1.func2();
}

// 类模板对象做函数参数
template <class T1, class T2>
class Person3
{
public:
    Person3(T1 name, T2 age)
    {
        this->m_age = age;
        this->m_name = name;
    }

    void showPerson()
    {
        cout << "name: \t" << this->m_name << endl;
        cout << "age: \t" << this->m_age << endl;
    }

    T1 m_name;
    T2 m_age;
};

void printPerson3_1(Person3<string, int> &p)
{
    p.showPerson();
}

template <class T1, class T2>
void printPerson3_2(Person3<T1, T2> &p)
{
    p.showPerson();
    cout << "T1 type: " << typeid(T1).name() << endl;
    cout << "T2 type: " << typeid(float).name() << endl;
}

template <class T>
void printPerson3_3(T p)
{
    p.showPerson();
    cout << "T type: " << typeid(T).name() << endl;
}

void test03()
{
    Person3<string, int> p("Sun Wukong", 20);

    Person3<string, int> p2("Zhu Bajie", 20);

    printPerson3_1(p);

    printPerson3_2(p2);

    Person3<string, int> p3("Tang Seng", 40);

    printPerson3_3(p3);
}

template <class T>
class Base
{
public:
    T m;
};

// class Son : public Base{     // 错的，必须要知道父类中的T类型，才能继承给子类
class Son : public Base<int>
{
};

template <class T1, class T2>
class Son2 : public Base<T2>
{
    T1 obj;
};

void test04()
{
    Son2<int, char> s2;
}

template <class T1, class T2>
class Person6
{
public:
    Person6(T1 name, T2 age);
    // {
    //     this->m_age = age;
    //     this->m_name = name;
    // }

    void showPerson6();
    // {
    //     cout << "name: " << this->m_name << "age: " << this->m_age << endl;
    // }
    T1 m_name;
    T2 m_age;
};

template <class T1, class T2>
Person6<T1, T2>::Person6(T1 name, T2 age)
{
    this->m_age = age;
    this->m_name = name;
}

template <class T1, class T2>
void Person6<T1, T2>::showPerson6()
{
    cout << "name: " << this->m_name << "age: " << this->m_age << endl;
}

void test06()
{
    Person6<string, int> p("Tom", 99);
    p.showPerson6();
}

// template<class T1, class T2>
// class Person7{
// public:
//     Person7(T1 name, T2 age);
//     void showPerson7();

//     T1 m_name;
//     T2 m_age;
// };

// template<class T1, class T2>
// Person7<T1, T2>::Person7(T1 name, T2 age){
//     this->m_name = name;
//     this->m_age = age;
// }

// template<class T1, class T2>
// void Person7<T1, T2>::showPerson7(){
//     cout << "name: " << this->m_name << endl;
//     cout << "age: " << this->m_age << endl;
// }

void test07()
{
    Person7<string, int> p("Wang", 89);
    p.showPerson7();
}

template <class T1, class T2> // 类外实现全局模板函数需要提前声明这个类
class Person8;

template <class T1, class T2>
void printPerson2(Person8<T1, T2> p)
{
    cout << "name: " << p.m_name << "\n"
         << "age: " << p.m_age << endl;
}

template <class T1, class T2>
class Person8
{

    friend void printPerson2<>(Person8<T1, T2> p); // 加空模板参数列表
    friend void printPerson(Person8<T1, T2> p)
    {
        cout << "name: " << p.m_name << "\n"
             << "age: " << p.m_age << endl;
    }

public:
    Person8(T1 name, T2 age)
    {
        this->m_age = age;
        this->m_name = name;
    }

private:
    T1 m_name;
    T2 m_age;
};

void test08()
{
    Person8<string, int> p("Jack", 99);
    printPerson2(p);
}

void printArr(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void test09()
{
    MyArray<int> arr(5);
    // MyArray<int> arr2(arr);
    // MyArray<int> arr3(100);
    // arr3 = arr;

    for (int i = 0; i < 5; i++)
    {
        arr.push_back(i);
    }
    cout << "arr：" << endl;
    printArr(arr);

    cout << "arr capacity is : " << arr.getCapacity() << endl;
    cout << "arr size is : " << arr.getSize() << endl;

    MyArray<int> arr2(arr);
    cout << "arr2：" << endl;
    printArr(arr2);

    // 尾删
    arr2.pop_back();
    cout << "arr2 after pop ：" << endl;
    printArr(arr2);
    cout << "arr2 capacity is : " << arr2.getCapacity() << endl;
    cout << "arr2 size is : " << arr2.getSize() << endl;
}

// 测试自定义数据类型数组

class Person10
{
public:
    Person10() {}
    Person10(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    string m_name;
    int m_age;
};

void printPersonArr(MyArray<Person10> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i].m_name << arr[i].m_age << endl;
    }
}

void test10()
{
    MyArray<Person10> arr(10);

    Person10 p1("sunwukong", 99);
    Person10 p2("hanxin", 20);
    Person10 p3("zhaoyun", 30);
    Person10 p4("anqila", 26);
    Person10 p5("bailishouyue", 27);
    Person10 p6("chengyaojin", 29);

    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    arr.push_back(p5);
    arr.push_back(p6);

    printPersonArr(arr);

    cout << "arr capacity is : " << arr.getCapacity() << endl;
    cout << "arr size is : " << arr.getSize() << endl;

    // 尾删
    arr.pop_back();
    cout << "arr after pop ：" << endl;
    printPersonArr(arr);
    cout << "arr capacity is : " << arr.getCapacity() << endl;
    cout << "arr size is : " << arr.getSize() << endl;
}

int main()
{

    // test01();
    // test02();
    // test03();
    // test06();
    // test07();
    // test08();
    // test09();
    test10();
    return 0;
}