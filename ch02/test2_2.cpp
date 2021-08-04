#include<iostream>
using namespace std;

/*
        2. 引用
        
        2.1 引用的基本使用
            作用：给变量起别名
            语法： 数据类型 &别名 = 原名
        2.2 引用注意事项
            引用必须初始化 int &b; 这样是错误的
            引用在初始化后，不可以改变
        2.3 引用做函数参数
            作用：函数传参时，可以利用引用技术让形参修饰实参
            优点：可以简化指针修改实参
            通过引用参数产生的效果同按地址传递是一样的，引用的语法更简单清楚
        2.4 引用做函数的返回值
            作用：引用是可以作为函数的返回值存在的
            注意：不要返回局部变量引用
            用法：函数调用作为左值
        2.5 引用的本质
            本质：引用的本质在C++内部实现是一个指针常量，指针指向的地址不可以改变，但是地址中的值可以改变
        2.6 常量引用
            作用：常量引用主要用来修饰形参，防止误操作
            在函数形参列表中，可以加const修饰形参，防止形参改变实参

    */
   


void mySwap01(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void mySwap02(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mySwap03(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int& test01(){
    int a = 10;
    return a;
}

int& test02(){
    static int a = 10;
    return a;
}
 
void showValue(const int &val){
    // val = 200;
    cout << "val = " << val << endl;
}

int main(){

    
   int a = 10;
   int &b = a;  // 引用的值，a是变量名
   b = 30;
   cout << "a =  :" << a << endl;
   cout << "b =  :" << b << endl;

   int c = 40;
//    &b = c;   这样是不可以的，引用不可以改变 

    int s1 = 10;
    int s2 = 20;
    mySwap01(s1, s2);    //值传递，形参不会修饰实参
    cout << "swap01 s1 = " << s1 << endl;
    cout << "swap01 s2 = " << s2 << endl;
    mySwap02(&s1, &s2);
    cout << "swap02 s1 = " << s1 << endl;
    cout << "swap02 s2 = " << s2 << endl;
    mySwap03(s1, s2);   // 引用传递，形参可以修饰实参
    cout << "swap03 s1 = " << s1 << endl;
    cout << "swap03 s2 = " << s2 << endl;

    int &ref = test02();
    cout << "the value1 of yinyong: " << ref << endl;
    cout << "the value2 of yinyong: " << ref << endl;

    test02() = 10000;   
    cout << "func as left value: " << ref << endl;

    const int & ref2 = 10;  // 引用必须是一段合法的内存空间，加上const之后，编译器将修改代码为：
    // int temp = 10; const int & ref2 = temp;

    int d = 100;
    showValue(d);
    cout << "d = " << d << endl;

    



    return 0;
}