#include <iostream>
using namespace std;
#include <list>

/*
    3.7 list容器

    3.7.1 list基本概念
        功能：将数据进行链式存储
        链表：（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的

        链表的组成：链表由一系列结点组成

        结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域

        STL中的链表是一个双向循环链表 （每个结点都有两个地址，一个记录pre结点，一个记录next结点）

        链表 -好处： 
                1.可以对任意的位置进行快速插入或删除元素，修改指针即可，不需要移动大量元素
                2.采用动态存储分配，不会造成内存浪费和溢出  
            -缺点： 
                1.链表灵活，但是空间（指针域）和时间（遍历）额外耗费大

        list有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的

        由于链表的存储方式并不是连续的存储空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器

        总结：STL中list和vector是两个最常使用的容器，各有优缺点

    3.7.2 list构造函数
        功能：创建list容器

    3.7.3 list赋值和交换
        功能描述： 给list容器进行赋值，以及交换list容器
    
    3.7.4 list大小操作
        功能描述：对list容器的大小进行操作
        empty、size、resize

    3.7.5 list插入和删除
            功能描述： 对list容器进行数据的插入和删除

    3.7.6 list数据存取
        功能描述： 对list容器中数据进行存取
        l.front();
        l.back();

        list不支持下标访问，只支持前移后移，不支持随机访问

    3.7.7 list反转和排序
        功能描述：
            将容器中的元素反转，以及符合容器中的数据进行排序

    3.7.8 排序案例
        案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
        排序规则：按照年龄进行排序，如果年龄相同则按身高进行排序

*/

void printList(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
}

void test01()
{
    // 默认构造函数
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);

    // 区间方式构造
    list<int> l2(l1.begin(), l1.end());
    printList(l2);

    // 拷贝构造
    list<int> l3(l1);
    printList(l3);

    // n个ele
    list<int> l4(10, 10000);
    printList(l4);
}

void test02()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);

    // operator= 赋值
    list<int> l2 = l1;
    printList(l2);

    // assign赋值
    list<int> l3;
    l3.assign(l2.begin(), l2.end());
    printList(l3);

    // n ele
    list<int> l4;
    l4.assign(10, 100);
    printList(l4);
}

void test03()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);

    list<int> l4;
    l4.assign(10, 100);
    printList(l4);

    l1.swap(l4);
    printList(l1);
    printList(l4);
}

void test04()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);

    printList(l1);

    // 删除
    l1.pop_back();
    printList(l1);

    l1.pop_front();
    printList(l1);

    // insert输入
    l1.insert(l1.begin(), 1000);
    printList(l1);

    // 删除，按照迭代器
    list<int>::iterator it = l1.begin();
    l1.erase(++it);
    printList(l1);

    // 按值移除,所有
    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    printList(l1);
    l1.remove(10000);
    printList(l1);

    // 清空
    l1.clear();
    printList(l1);
}

bool myCompare(int v1, int v2)
{
    // 降序， 就让第一个数 > 第二个数
    return v1 > v2;
}

void test05()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(23);
    l1.push_back(13);
    l1.push_back(82);
    l1.push_back(45);
    printList(l1);

    l1.reverse();
    printList(l1);

    // 所有不支持随机访问迭代器的容器，不可以用标准算法
    // 不支持随机访问的迭代器的容器，内部会提供一些排序算法
    l1.sort(myCompare);
    printList(l1);

    // l1.reverse();
    // printList(l1);
}

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }

    int age;
    int height;
    string name;
};

void printPersonList(const list<Person> &l)
{
    for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "name: " << it->name << "\tage: " << it->age << "\theight:" << it->height << endl;
    }
}

// 指定排序规则
bool comparePerson(Person &p1, Person &p2){
    if(p1.age == p2.age){
        return p1.height > p2.height;
    }
    // 按照年龄升序
    return p1.age < p2.age;
}

void test06()
{
    list<Person> l1;
    // 准备数据
    Person p1("zhangfei", 45, 178);
    Person p2("liubei", 43, 173);
    Person p3("guanyu", 52, 173);
    Person p4("zhaoyun", 45, 188);
    Person p5("machao", 25, 198);

    l1.push_back(p1);
    l1.push_back(p2);
    l1.push_back(p3);
    l1.push_back(p4);
    l1.push_back(p5);

    printPersonList(l1);

    cout << "----------------------------------" << endl;

    // 排序
    l1.sort(comparePerson);
    printPersonList(l1);

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