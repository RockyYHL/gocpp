#include <iostream>
using namespace std;

template<class T1, class T2>
class Person7{
public:
    Person7(T1 name, T2 age);
    void showPerson7();

    T1 m_name;
    T2 m_age;
};