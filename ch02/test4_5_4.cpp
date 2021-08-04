#include <iostream>
using namespace std;

/*
    4.5.4 赋值运算符重载
    
    C++编译器至少给一个类添加4个函数：
        1.默认构造函数（无参，函数体为空）
        2.默认析构函数（无参，函数体为空）
        3.默认拷贝构造函数，对属性进行值拷贝
        4.赋值运算符 operator= ，对属性进行值拷贝

        如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题

        浅拷贝带来的问题：堆区的内存重复释放
        解决方案：利用深拷贝，

    4.5.5 函数调用运算符重载
        - 函数调用运算符（）也可以重载
        - 由于重载后使用方式非常像函数的调用，因此成为仿函数
        - 仿函数没有就固定写法，非常灵活
*/

class Person
{
public:
    Person(int age)
    {
        m_age = new int(age);
    }
    int *m_age;

    ~Person()
    {
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
    }

    Person &operator=(Person &p)
    {
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
        m_age = new int(*p.m_age);
        return *this;
    }

    bool operator==(Person &p)
    {
        if (*this->m_age == *p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void test01()
{
    Person p1(20);

    Person p2(30);

    Person p3(100);

    p3 = p2 = p1;

    cout << "p1.age： " << *p1.m_age << endl;
    cout << "p2.age： " << *p2.m_age << endl;
    cout << "p3.age： " << *p3.m_age << endl;
}

void test02()
{
    Person p1(20);

    Person p2(30);

    Person p3(30);

    if (p1 == p2)
    {
        cout << "p1 equals p2" << endl;
    }
    else
    {
        cout << "p1 not equals p2" << endl;
    }

    if (p3 == p2)
    {
        cout << "p3 equals p2" << endl;
    }
    else
    {
        cout << "p3 not equals p2" << endl;
    }
}

class myPrint
{
    public:
    void operator()(string test){
        cout << test << endl;
    }
};

void myPrint02(string test){
    cout << test << endl;
}

class myAdd
{
    public:
    int operator()(int num1, int num2){
        return num1 + num2;
    }
};

void test03(){
    myPrint myprint;
    myprint("hello world");    // 和函数调用很像，因此成为仿函数，实际上是类的对象
    myPrint02("hello world");

    myAdd myadd;
    int ret = myadd(10, 20);
    cout << ret << endl;
    cout << "unname object: " << myAdd()(100, 100) << endl;   //匿名对象

}

int main()
{

    // test01();
    // test02();
    test03();
    return 0;
}