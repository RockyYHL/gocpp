#include <iostream>
using namespace std;

/*
    友元
        生活中你的家有客厅（public），有你的卧室（private）
        客厅所有来的客人可以进去，但是你的卧室是私有的，也就是说只有你能进去
        但是呢，你可以允许你你的好友闺蜜基友进去
        在程序里，有些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

        友元的目的就是让一个函数或者类，访问另一个类中私有成员

        友元的关键字为 friend

        友元的三种实现：
            - 全局函数做友元
            - 类做友元
            - 成员函数做友元
*/

class Building
{
    friend void goodGay(Building &b);

public:
    Building()
    {
        m_sittingRoom = "keting";
        m_bedRoom = "woshi";
    }

public:
    string m_sittingRoom;

private:
    string m_bedRoom;
};

class Building2;
class GoodGay2
{
public:
    GoodGay2();
    void visit();  // 参观函数，访问Building中的属性
    void visit2();
    Building2 * building;
};

class Building2
{
    friend class GoodGay;
    friend void GoodGay2::visit();
// public:
//     class GoodGay2;
public:
    Building2();
    
public:
    string m_sittingRoom;

private:
    string m_bedRoom;
    
};

class GoodGay
{
public:
    GoodGay();
    void visit();  // 参观函数，访问Building中的属性
    Building2 * building;
};


// 全局函数
void goodGay(Building &b)
{
    cout << "goodGay is visiting: " << b.m_sittingRoom << endl;

    cout << "goodGay is visiting: " << b.m_bedRoom << endl;
}

// 类外写成员函数
Building2::Building2(){
    m_sittingRoom = "keting";
    m_bedRoom = "woshi";
}

GoodGay::GoodGay(){
    building = new Building2;
}

GoodGay2::GoodGay2(){
    building = new Building2;
}

void GoodGay::visit()
{
    cout << "class GoodGay is vising: " << building->m_sittingRoom << endl;

    cout << "class GoodGay is vising: " << building->m_bedRoom << endl;
}

void GoodGay2::visit()
{
    cout << "class GoodGay2 is vising: " << building->m_sittingRoom << endl;

    cout << "class GoodGay2 is vising: " << building->m_bedRoom << endl;
}

// void GoodGay2::visit2()
// {
//     cout << "class GoodGay2 is vising: " << building->m_sittingRoom << endl;

//     cout << "class GoodGay2 is vising: " << building->m_bedRoom << endl;
// }




void test01()
{
    Building b;
    goodGay(b);
}

void test02(){
    GoodGay gg;
    gg.visit();
}

void test03(){
    GoodGay2 gg;
    gg.visit();
}

int main()
{

    // test01();
    // test02();
    test03();
    return 0;
}