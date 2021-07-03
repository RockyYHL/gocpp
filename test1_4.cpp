#include<iostream>
using namespace std;

// 1.宏常量  （定义常量的两种方法）
#define day 7

int main(){

    // int num1 = 0;
    // int num2 = 0;
    // int num3 = 0;
    // int max = 0;

    // cout << "请输入第一只小猪的重量：\n" << endl;
    // cin >> num1;
    // cout << "请输入第二只小猪的重量：\n" << endl;
    // cin >> num2;
    // cout << "请输入第三只小猪的重量：\n" << endl;
    // cin >> num3;

    // if (num1>num2){
    //     if (num1>num3){
    //         max = num1;
    //     }else{
    //         max = num3;
    //     }
    // }else{
    //     if (num2 > num3){
    //         max = num2;
    //     }else{
    //         max = num3;
    //     }
    // }

    // cout << "最大重量：\n" << endl;
    // cout << max << endl;

    // 三目运算符,返回的是变量，可以继续进行操作
    // int a = 10;
    // int b = 2;
    // int c = 9;
    // bool r = true;

    // (a > b != c) ? r = true : r = false;
    // cout << r << endl;

    // goto 语句
    cout << "1.xxxxxx" << endl;
    cout << "2.xxxxxx" << endl;
    goto FLAG;
    cout << "3.xxxxxx" << endl;
    cout << "4.xxxxxx" << endl;
    FLAG:
    cout << "5.xxxxxx" << endl;

    





    return 0;
}