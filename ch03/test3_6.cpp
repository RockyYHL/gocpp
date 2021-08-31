#include <iostream>
using namespace std;
#include <queue>

/*
    3.6 queue容器
    3.6.1 queue基本概念
        概念：queue是一种先进先出的数据结构，它有两个出口
*/

class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};

void test01()
{
    queue<Person> q;
    Person p1("A", 20);
    Person p2("B", 30);
    Person p3("C", 50);
    Person p4("D", 10);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    while(!q.empty()){
        cout << "ele in top: " << q.front().name << "\t" << q.front().age << endl;
        cout << "ele in back: " << q.back().name << "\t" << q.back().age << endl;

        q.pop();
    }

    cout << "queue size is: " << q.size() << endl;

}

int main()
{

    test01();
    return 0;
}