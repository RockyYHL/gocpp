#include <iostream>
using namespace std;

/*
    4.2.7 类对象作为类成员
        C++ 类中的成员可以是另一个类的对象，我们称之为对象成员
        结论：当其他类的对象作为本类的成员，先构造其他类的对象，再构造自身
    4.2.8 静态成员
        静态成员就是在成员变量和成员函数前加上关键字static，成为静态成员
        静态成员为：
            静态成员变量
                -所有对象共享同一份数据
                -在编译阶段分配内存
                -类内声明，类外初始化
            静态成员函数
                -所有对象共享同一个函数
                -静态成员函数只能访问静态成员变量
*/
class Phone
{
public:
    Phone(string pname)
    {
        m_pname = pname;
        cout << "Phone gouzao hanshu diaoyong" << endl;
    }
    string m_pname;
    ~Phone(){
        cout << "Phone xigou hanshu diaoyong" << endl;
    }
};

class Person
{
public:
// Phone m_phone = pname; 隐式转换法
    Person(string name, string pname) : m_name(name), m_phone(pname)
    {
        cout << "Person gouzao hanshu diaoyong" << endl;
    }
    ~Person(){
        cout << "Person xigou hanshu diaoyong" << endl;
    }

    static void func(){
        m_A = 1000;   //
        // m_B = 900;  // 静态成员函数不可以访问非静态成员变量
        cout << "static void func diaoyong" << endl;
    }

    static int m_A;
    int m_B;
    string m_name;
    Phone m_phone;
};

int Person::m_A = 0;

void test01(){
    Person p("zhangsan", "iphone max");
    cout << p.m_name << " carry " << p.m_phone.m_pname << endl;
}

void test02(){
    // 1.通过对象进行访问
    Person p("zhangsan", "iphone max");
    p.func();
    // 2.通过类名进行访问
    Person::func();

}

int main()
{
    // test03();
    // test01();
    test02();

    return 0;
}