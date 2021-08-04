#include <iostream>
using namespace std;

/*
    运算符重载
        运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

    4.5.1 加号运算符重载
        作用：实现两个自定义数据类型想加的运算
        方式：
        - 成员函数重载
        - 全局函数重载
    总结1：对于内置的数据类型的表达式的运算符是不可能改变的
    总结2：不要滥用运算符重载

    4.5.2 左移运算符重载 
        作用：可以输出自定义数据类型

    4.5.3 递增运算符重载
        作用：通过递增运算符，实现自己的整型数据


*/

class Person
{
public:
    int m_A;
    int m_B;
    Person(int a, int b);

    Person operator+(Person &p)
    {
        Person temp(0, 0);
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;

        return temp;
    }
};

class Person2
{
    friend ostream &operator<<(ostream &cout, Person2 &p);

private:
    int m_A = 10;
    int m_B = 10;

    // void operator<<(Person2){

    // }
};

ostream &operator<<(ostream &cout, Person2 &p)
{ // 本质 operator<<(cout, p),简化 cout << p
    cout << "p.m_A = " << p.m_A << "  p.m_B = " << p.m_B;
    return cout;
}

Person operator+(Person &p1, int n)
{
    Person temp(0, 0);
    temp.m_A = p1.m_A + n;
    // temp.m_B = p1.m_B + p2.m_B;

    return temp;
}

// Person operator+(Person &p1, Person &p2)
// {
//     Person temp(0, 0);
//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_B + p2.m_B;

//     return temp;

// }

Person::Person(int a, int b)
{
    this->m_A = a;
    this->m_B = b;
}

void test01()
{
    Person p1(10, 10);
    Person p2(20, 20);
    // // 成员函数重载本质调用
    // Person p3 = p1.operator+(p2);
    // // 全局函数重载本质调用
    // Person p3 = operator+(p1, p2);
    Person p3 = p1 + p2;
    Person p4 = p1 + 100;

    cout << "p3 s m_A: " << p3.m_A << endl;
    cout << "p3 s m_B: " << p3.m_B << endl;
    cout << "p4 s m_A: " << p4.m_A << endl;
    cout << "p4 s m_B: " << p4.m_B << endl;
}

void test02()
{
    Person2 p;
    // p.m_B = 10;
    // p.m_A = 10;

    cout << p << endl;
}

class myInteger
{
    friend ostream &operator<<(ostream &cout, myInteger &myint);

public:
    myInteger()
    {
        this->m_Num = 0;
    }

    myInteger &operator++() // 返回引用是为了一直对一个对象进行递增
    {
        this->m_Num++;
        return *this;
    }

    // void operator++(int) int 代表站位参数，可以用于区分前置和后置递增
    myInteger operator++(int)
    {
        // 先记录结果，后递增，最后将记录返回
        myInteger temp = *this;
        this->m_Num++;
        return temp;                 // 不能返回局部变量的引用
    }

public:
    int m_Num;
};

ostream& operator<<(ostream &cout, myInteger &myint)
{
    cout << myint.m_Num;

    return cout;
}

void test03()
{
    myInteger myint;
    cout << ++(++myint) << endl;
    // cout << myint++ << endl;
    cout << myint << endl;
}

void test04()
{
    myInteger myint;
    myInteger m_int = myint++;
    cout << m_int << endl;
    // cout << myint++ << endl;
    cout << myint << endl;
}

int main()
{

    // test01();
    // test02();
    // test03();
    test04();
    return 0;
}