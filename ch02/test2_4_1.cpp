#include <iostream>
using namespace std;

 /*
        4 类和对象
            C++面向对象的三大特性为：封装/继承/多态
            C++认为万事万物都皆为对象，对象上有其属性和行为

        4.1 封装
            4.1.1 封装的意义
                封装是C++面向对象的三大特性之一
                - 将属性和行为作为一个整体，表现生活中的事务
                - 将属性和行为加以权限控制    
                封装的意义一： 
                在设计类的时候，属性和行为写在一起，表现事物
                语法： class 类名{访问权限： 属性/行为(都叫做成员)} 
                属性（成员属性，成员变量）
                行为（成员函数，成员方法）
                封装的意义二：
                类在设计时，可以把属性和行为放在不同的权限下，加以控制
                访问权限有三种：
                    1.public 公共权限      类内可以访问，类外可以访问
                    2.protected 保护权限   类内可以访问，类外不可访问    儿子也可以访问父亲的保护内容
                    3.private 私有权限     类内可以访问，类外不可访问    儿子不可以访问父亲的私有内容
            4.1.2 struct和class的区别
                在C++中struct和class唯一的区别就在于 默认的访问权限不同
                区别：
                    - struct默认权限为公共
                    - class 默认权限为私有
            4.1.3 成员属性设置为私有
                优点1：将所有的成员属性设置为私有，可以自己控制读写权限
                优点2：对于写权限，我们可以检测数据的有效性

    */


const double PI = 3.14;

class Circle
{
public:
    int m_r;

    double calculateZC()
    {
        return 2 * PI * m_r;
    }
};


class Person{
public:
    string m_name;
protected:
    string m_car;
private:
    int m_password;
public:
    void func(){
        m_name = "zhangsan";
        m_car = "aodi";
        m_password = 123456;
    }
};

struct S
{
   int m_A;
};

class C{
    int m_A;
};

class Person2
{
public:
void setName(string name){
    m_Name = name;
}
string getName(){
    return m_Name;
}
void setAge(int age){
    if(age > 0){
        m_Age = age;
    }else{
        cout << "wrong age !" << endl;
        // return;
    }
}
int getAge(){
    // m_Age = 0;
    return m_Age;
}
void setLover(string lover){
    m_lover = lover;
}
private:
    string m_Name;
    int m_Age;
    string m_lover;
};



int main()
{

   
    Circle c1;
    c1.m_r = 10;
    cout << "the ZC of c1 is : " << c1.calculateZC() << endl;

    Person p1;
    p1.m_name = "lisi";
    // p1.m_car = "kaidilake";    // 保护权限/私有权限的内容，类外访问不到
    // p1.m_password = 4132341;

    C s;
    // s.m_A = 20;     //class默认的权限时private
    S s2;
    s2.m_A = 20;    //struct默认的权限为public

    Person2 p2;
    p2.setName("zhangsan");
    cout << p2.getName() << endl;
    // cout << p2.getAge() << endl;
    // cout << p2.m_Age << endl;
    p2.setLover("ahaha");
    // p2.setAge(0);
    p2.setAge(100);
    cout << p2.getAge() << endl;

    return 0;
}