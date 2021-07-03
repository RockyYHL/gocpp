#include<iostream>
using namespace std;

// 1.宏常量  （定义常量的两种方法）
#define day 7

int main(){

    cout << "一周一共有" << day << "天" << endl;

    // 2.const修饰变量
    const int month = 12;
    cout << "一年总共有 " << month << " 个月份" << endl;
    // month = 13; 

    // 定义变量或常量的时候，不要用C++关键字，否则会产生歧义
    // int double = 12;


    // 标识符（变量、常量的名字）命名规则
    // int 12abc = 12;





    return 0;
}