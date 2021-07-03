// # define __cplusplus 201103L

// #include "StdAfx.h"
#include <iostream>
using namespace std;

void TestReference1 ()
{
     int a = 1;
     int& b = a;
 
     cout<<"a:address->" <<&a<< endl;
     cout<<"b:address->" <<&b<< endl;
     cout<<"a:->" <<a<< endl;
     cout<<"b:->" <<b<< endl;
 
     a = 2;
     b = 3;
     int& c = b;// 引用一个引用变量，别名的别名
     c = 4;
     cout<<"a:->" <<a<< endl;
     cout<<"b:->" <<b<< endl;
     cout<<"c:->" <<c<< endl;
}

template<typename T1,typename T2>
void printX(T1 t1,T2 t2){
	cout << "进入两个参数的模板函数" << endl;
	cout << t1 << endl;
	cout << t2 << endl; 
}
 
template<typename T,typename... Args>
void printX(T& firstarg,Args&... args){
	cout << "进入可变参数的模板函数" << endl;
	cout << "sizeof...(Args)=" << sizeof...(Args) << endl;
	cout << "sizeof...(args)=" << sizeof...(args) << endl;
	cout << firstarg << endl;
	printX(args...);
}

int main(){
    //cout << __cplusplus << endl;
    //TestReference1();
    string str = "hello";
	int i = 25;
	double j = 12.23;
	float m = 123.56;
	printX(str,i,j,m);
    return 0;
}