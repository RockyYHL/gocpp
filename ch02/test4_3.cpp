#include <iostream>
using namespace std;

/*
    4.3 C++对象模型和this指针

    4.3.1 成员变量和成员函数分开存储
        在C++中，类的成员变量和成员函数分开存储
        只有非静态成员变量才属于类的对象上
        空对象占用内存空间为：1  （是为了区分空对象占内存的位置，每个空对象也应该有一个独一无二的内存地址）
        静态成员变量、非静态成员函数、静态成员函数 都不属于类的对象上

    4.3.2 this指针概念
        通过4.3.1我们知道在C++中成员变量和成员函数是分开存储的
        每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
        那么问题是：这一块代码是如何区分哪个对象调用自己的呢？

        C++ 通过提供特殊的对象指针，this指针，解决上述问题，this指针指向被调用的成员函数所属的对象

        this指针是隐含每一个非静态成员函数的一种指针
        this指针不需要定义，直接使用即可

        this指针的用途是：
            - 当形参和成员变量同名时，可用this指针区分
            - 在类的非静态成员函数中返回对象本身，可以用 return *this    （链式编程思想）
        
    4.3.3 空指针访问成员函数
        C++中空指针也是可以调用成员函数的，但也要注意没有用到this指针
        如果用到this指针，需要加以判断保证代码的健壮性

    4.3.4 const修饰成员函数
        常函数：
            - 成员函数后加const后我们称这个函数为常函数
            - 常函数内不可以修改成员属性
            - 成员属性声明时加关键字mutable后，在常函数中依然可以修改
        // this指针的本质 是指针常量，指针的指向是不可以改变的
        常对象：
            - 声明对象前加const称该对象为常对象
            - 常对象只能调用常函数
*/

class Person
{
    int m_A;
    static int m_B;
    void func()
    {
    }
    static void func2()
    {
    }
};

class Person2
{
public:
    Person2(int age)
    {
        this->age = age;
    }

    Person2 &PersonAddAge(Person2 &p)
    { // Person 的话会一直返回一个Person新对象，Person& 会一直返回p2这个对象
        this->age += p.age;
        return *this;
    }

    int age;
};

class Person3
{
public:
    void showClassName()
    {
        cout << "this is Person Class" << endl;
    }

    void showPersonAge()
    {
        if(this == NULL){
            return;
        }
        cout << "age = " << this->age << endl;
    }

    int age;
};

class Person4
{
public:
    void showPerson() const {
        // this->m_A = 10;
        this->m_B = 10;
    }
    void func(){

    }

    int m_A;
    mutable int m_B;
};

int Person::m_B = 0; // 静态变量类内声明，类外定义

void test01()
{
    Person p;
    cout << "size of p: " << sizeof(p) << endl;
}

void test02()
{
    Person p;
    cout << "size of p: " << sizeof(p) << endl;
}

void test03()
{
    Person2 p(18);
    cout << "the age is : " << p.age << endl;
}

void test04()
{
    Person2 p1(10);
    Person2 p2(10);
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    // p2.PersonAddAge(p1)->PersonAddAge(p1)->PersonAddAge(p1);
    cout << "p2 age is : " << p2.age << endl;
}

void test05()
{
    Person3 * p = NULL;
    p->showClassName();
    p->showPersonAge();
}

void test06(){
    Person4 p;
    p.showPerson();
    // p.func();

}

int main()
{

    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();

    return 0;
}