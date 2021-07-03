#include <iostream>
using namespace std;
#include "/home/yhl/yhl/gocpp/include/swap.h"

// 1.宏常量  （定义常量的两种方法）
#define day 7

int main()
{
    /*
        函数语法：
        返回值类型 函数名 （参数列表）
        {
            函数体语句

            return表达式
        }

        常见的函数样式有4种：
        1.有参无返
        2.无参无返
        3.无参有返
        4.有参有返

        函数声明：
        意义：提前告诉编译器函数的存在，可以利用函数的声明
        声明可以写多次，定义只能写一次

        函数分文件编写：
        四个步骤：
        1.创建后缀名为.h的头文件
        2.创建后缀名为.cpp的源文件
        3.在头文件中写函数的声明
        4.在源文件中写函数的定义
    */
    
    int a = 10;
    int b = 20;

    swap(a, b);


    return 0;
}