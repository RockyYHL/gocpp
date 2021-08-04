#include <iostream>
using namespace std;

/*
    4.6 继承
    继承是面向对象的三大特性之一
    
    4.6.1 继承的基本语法
        继承的语法： class 子类：继承方式 父类

        好处：减少重复代码
        子类 也成为 派生类
        父类 也成为 基类

        派生类中的成员，包含两大部分：
            一类是从基类继承过来的，一类是自己增加的成员
            从基类继承过来的表现其共性，而新增的成员体现了其个性
    
    4.6.2 继承方式
        继承方式一共有三种：
            - 公共继承
            - 保护继承
            - 私有继承
    
    4.6.3 继承中的对象模型
        问题：从父类继承过来的成员，哪些属于子类对象中？
        父类中所有非静态成员属性都会被子类继承下去
        父类中私有成员属性，是被编译器给隐藏了，因此是访问不到的，但是确实被继承下去了

    4.6.4 继承中的构造和析构顺序
        子类继承父类后，当创建子类对象，也会调用父类的构造函数
        问题：父类和子类的构造和析构函数是谁先谁后？   （构造：父类 > 子类； 析构： 子类 > 父类)

    4.6.5 继承同名成员处理方式
        问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或者父类中同名的数据呢？
        - 访问子类同名成员，直接访问即可
        - 访问父类同名成员，需要加作用域

        如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
        如果想访问到父类中被隐藏的同名成员函数，需要加作用域

    4.6.6 同名静态成员处理方式
        问题：继承中同名的静态成员在子类对象上如何进行访问
        静态成员和非静态成员出现同名，处理方式一致
            - 访问子类同名成员，直接访问即可
            - 访问父类同名成员，需要加作用域

    4.6.7 多继承语法
        C++允许一个类继承多个类
        语法：  class 子类：继承方式 父类1， 继承方式 父类2 。。。
        多继承可能会引发父类中有同名成员出现，需要添加作用域区分

        C++实际开发中不建议使用多继承

    4.6.8 菱形继承
        菱形继承概念：
            两个派生类继承同一个基类
            又有某个类同时继承两个派生类
            这种继承被称为菱形继承，或者钻石继承

        菱形继承问题：
            1.羊继承了动物的数据，驼同样继承了动物的数据，当草拟吗使用数据时，就会产生二义性
            2.草拟吗继承自动物的属性继承了两份，其实我们应该清除，这份数据我们只需要一份就可以

        利用虚继承解决
        vbptr 虚基类指针
        虚继承继承的只是父类的指针，两份指针会通过偏移量找到一份唯一的数据
    
*/

// class Python(Java){
//     public:
// };

class basePage
{
public:
    void header()
    {
        cout << "page1/page2/page3/page4" << endl;
    }
    void footer()
    {
        cout << "help1/help2/help3/help4" << endl;
    }
    void left()
    {
        cout << "project1/project2/project3/project4" << endl;
    }
};

class Java : public basePage
{
public:
    void content()
    {
        cout << "java content" << endl;
    }
};

class Python : public basePage
{
public:
    void content()
    {
        cout << "Python content" << endl;
    }
};

void test01()
{
    cout << "Java page : " << endl;
    Java java;
    java.header();
    java.left();
    java.content();
    java.footer();
    cout << "Python page : " << endl;
    Python python;
    python.header();
    python.left();
    python.content();
    python.footer();
}

class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son1 : public Base1
{
public:
    void func()
    {
        m_A = 10;
        m_B = 10;
        // m_C = 10;   父类中的私有权限成员，子类访问不到
    }
};

class Son2 : protected Base1
{
public:
    void func()
    {
        m_A = 100;
        m_B = 100;
        // m_C = 100;
    }
};

class Son3 : private Base1
{
public:
    void func()
    {
        m_A = 100;
        m_B = 200;
        // m_C = 300;
    }
};

class Grandson : public Son3
{
public:
    void func()
    {
        // m_A = 1000;
    }
};

class Son : public Base1
{
public:
    int m_D;
};

void test02()
{
    Son1 s1;
    s1.m_A = 100;
    // s1.m_B = 200;  Son1中的m_B是保护权限，类外访问不到
}

class test
{
};

class test2 : public Base1
{
};

void test03()
{
    cout << sizeof(Son) << endl;
    cout << sizeof(test) << endl;
    cout << sizeof(test2) << endl;
}

class Base2
{
public:
    Base2()
    {
        cout << "Base2 gouzao " << endl;
    }
    ~Base2()
    {
        cout << "Base2 xigou" << endl;
    }
};

class Son4 : public Base2
{
public:
    Son4()
    {
        cout << "Son4 gouzao " << endl;
    }
    ~Son4()
    {
        cout << "Son4 xigou" << endl;
    }
};

void test04()
{
    Son4 s4;
}

class Base5
{
public:
    Base5()
    {
        m_A = 100;
    }

    int m_A;
    void func(){
        cout << "Base5 - func" << endl;
    } 

    void func(int a){
        cout << "Base5 - func(int a)" << endl;
    } 
};

class Son5 : public Base5
{
    public:
    int m_A;
    Son5(){
        m_A = 200;
    }
    void func(){
        cout << "Son5 - func" << endl;
    } 
};

void test05()
{
    Son5 s5;
    cout << "s5.m_A: " << s5.m_A << endl;
    cout << "s5.Base5::m_A: " << s5.Base5::m_A << endl;

    s5.func();
    s5.Base5::func();
    s5.Base5::func(10);
}

class Base6
{
    public:
    Base6(){
        m_A = 100;
    }
    int m_A;
};

class Base7
{
    public:
    Base7(){
        m_B = 100;
    }
    int m_B;
};

class Son6 : public Base6, public Base7
{
    public:
    Son6(){
        m_C = 300;
        m_D = 400;
    }
    int m_C;
    int m_D;
};

void test06(){
    Son6 s6;
    cout << "sizeof Son6: " << sizeof(s6) << endl;
    cout << "m_A = " << s6.Base6::m_A << endl;
}

class Animal
{
    public:
    int m_Age;
};

class Sheep : virtual public Animal  //虚基类
{};

class Tuo : virtual public Animal
{};

class SheepTuo : public Sheep, public Tuo
{};

void test07(){
    SheepTuo st;
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 38;     // 类似于共享

    cout << "st.Sheep::m_Age : " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age : " << st.Tuo::m_Age << endl;
    cout << "st.m_Age : " << st.m_Age << endl;
    cout << "sizeof : " << sizeof(st) << endl;


}
int main()
{

    // test01();
    // test03();
    // test04();
    // test05();
    // test06();
    test07();
    return 0;
}