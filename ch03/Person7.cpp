#include <iostream>
#include "Person7.h"
using namespace std;


template<class T1, class T2>
Person7<T1, T2>::Person7(T1 name, T2 age){
    this->m_name = name;
    this->m_age = age;
}

template<class T1, class T2>
void Person7<T1, T2>::showPerson7(){
    cout << "name: " << this->m_name << endl;
    cout << "age: " << this->m_age << endl;
}