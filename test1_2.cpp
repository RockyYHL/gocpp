#include<iostream>
using namespace std;
// #include<string>

// 1.宏常量  （定义常量的两种方法）
#define day 7

int main(){
    // 数据类型的存在意义：给变量分配合适的内存空间
    // 整型、浮点型、字符型

    // sizeof关键字可以统计数据类型所占的内存大小
    int a = 10;
    cout << "short类型的所占内存大小： " << sizeof(a) << endl;

    // 默认情况下，输出小数会输出6位有效数字

    // 字符用单引号，里面只能放一个字符
    // char b = 'sdf';
    // cout << b << endl;

    // 转义字符
    // 水平制表符 \t 整齐的输出后面的内容

    // 字符串型,要用双引号
    char str1[] = "hello world";
    string str2 = "hello C++";
    cout << str1 << "\n" << str2 << endl;

    // bool类型
    bool flag = true;
    cout << flag << endl;

    // 数据的输入，作用：从键盘获取数据
    int inta;
    cout << "请输入一个整型数据： " << endl;
    cin >> inta;
    cout << inta << endl;







    return 0;
}