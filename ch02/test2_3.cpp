#include<iostream>
using namespace std;

/* 
        3 函数的提高

        3.1 函数的默认参数
            在C++中，函数的形参列表中的形参时可以由默认值的
            语法： 返回值类型 函数名 （参数 = 默认值）{}
            注意事项：
                1.某个位置已经有了默认值，那么这个位置往后，从左到右都必须由默认值
                2.如果函数声明由默认参数，函数实现就不能由默认参数（声明和实现只能有一个由默认参数）
        3.2 函数占位参数
            C++函数的形参列表里可有占位参数，用来做占位，调用函数时必须填补该位置
            语法： 返回值类型 函数名 （数据类型） {}
            目前占位参数还用不到，占位参数还可以由默认参数
        3.3 函数重载
            3.3.1 函数重载概述
            作用： 函数名可以相同，提高复用性
            函数重载满足条件：
                - 同一个作用域下(都在main里，或都是在全局域)
                - 函数名称相同
                - 函数参数类型不同，或者个数不同，或者顺序不同
                注意：函数的返回值时不可以作为重载的条件(二义性)
            3.3.2 函数重载的注意事项
                - 引用作为重载条件(会默认走不带const的可读可写函数)
                - 函数重载碰到默认参数
    */



int func(int a, int b=20, int c=20){
    return a + b + c;
}

int func2(int a, int b=10);

int func2(int a, int b){
    return a + b;
}

int func3(int a, int){
    cout << "this is func3 a: " << a << endl;
}

void func4(){
    cout << "func4" << endl;
}

void func4(int a){
    cout << "func4(inta)" << endl;
}

void func5(const int &a){
    cout << "func(const int &a)" << endl;
}

void func5(int &a){
    cout << "func5(int &a)" << endl;
}

void func6(int a, int b=10){
    cout << "func6(int a, int b)" << endl;
}

void func6(int a){
    cout << "func6(int a)" << endl;
}

int main(){

    
    cout << func(1) << endl;
    cout << func2(20) << endl;
    func3(10, 20);

    func4();
    func4(10);

    int c = 10;
    func5(c);
    func5(20);

    func6(2, 3);

    return 0;
}