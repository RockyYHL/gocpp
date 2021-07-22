#include <iostream>
using namespace std;

int g_a = 10;
int g_b = 10;
const int g_c_a = 10;

int* func(){     // 形参也会放在栈区
    // b = 100;  

    // int a = 10;

    int * p = new int(10);  // new可以开辟堆区内存，指针本身也是变量，放在栈区，指向的数据放在堆区 
    return p;
}

int* funcDui(){
    //在堆区创建数据，new返回的是该数据类型的指针
    int * p = new int(10);
    return p;
}

void test01(){
    int * p = funcDui();
    cout << *p << endl;
    // 利用delete释放堆区的数据
    delete p;
    cout << *p << endl;
}

void test02(){
    //在堆区开辟数组
    int * arr = new int[10];
    for(int i = 0; i < 10; i++){
        arr[i] = i + 100;     // 可以用[]对数组指针进行索引
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }

    delete[] arr;
    for(int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }
}

int main()
{

    /*
        C++核心编
        
        1. 内存分区模型
            C++程序在执行时，将内存大方向划分为4个区域：
            --代码区：存放函数体的二进制代码，由操作系统进行管理的
            --全局区：存放全局变量和静态变量以及常量
            --栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
            --堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收
            意义： 不同的区域存放数据，赋予不同的生命周期，给我们更大的灵活编程

        1.1 程序运行前
            在程序编译后，生成了exe可执行文件，未执行该程序前分为两个区域
            代码区：
                存放CPU执行的机器指令 
                代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
                代码区是只读的，使其只读的原因是防止程序意外地修改了它的命令
            全局区：
                全局变量和静态变量存放在此
                全局区还包含了常量区，字符串常量和其他常量也存放与此
                该区域的数据在程序结束后由操作系统释放
        1.2 程序运行后
            栈区：
                由编译器自动分配释放，存放函数的参数值，局部变量等
                注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
            堆区：
                由程序员分配释放，若程序员不释放，程序结束时由操作系统回收
                在c++中主要利用new在堆区开辟内存
        1.3 new操作符
            C++中利用new操作符在堆区开辟数据
            堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
            语法： new 数据类型
            利用new创建的数据，会返回该数据对应的类型的指针

            
                
            
    */

    // 普通局部变量
    int a = 10;
    int b = 10;
    // 静态变量
    static int s_a = 10;
    static int s_b = 10;
    // 常量,字符串常量，const修饰的变量
    const int c_a = 10;

    cout << "a address: " << (long long)&a << endl;
    cout << "b address: " << (long long)&b << endl;

    cout << "g_a address: " << (long long)&g_a << endl;
    cout << "g_b address: " << (long long)&g_b << endl;

    cout << "s_a address: " << (long long)&s_a << endl;
    cout << "s_b address: " << (long long)&s_b << endl;

    cout << "string address: " << (long long)&"nihao" <<endl;
    cout << "const local address: " << (long long)&c_a <<endl;
    cout << "const global address: " << (long long)&g_c_a <<endl;


    int * p = func();
    // cout << "the value based local variabal: " << *p << endl;
    // cout << "the value based local variabal: " << *p << endl;
    cout << "the value based new int(10) :" << *p << endl;

    test01();
    test02();



    return 0;
}