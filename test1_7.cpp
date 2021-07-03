#include <iostream>
using namespace std;

void swap02(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int * arr, int len){
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    /*
        1.定义指针
            定义语法： 数据类型 * 指针变量名
        2.使用指针
            可以通过解引用的方式来找到指针指向的内存：指针前加*,找到指针指向内存中的数据
        3.指针所占内存空间
            在32位系统下占4个字节，64位系统下占8个字节,不管是什么数据类型
        4.空指针和野指针
            空指针：指针变量指向内存中编号为0的空间
            用途：初始化指针变量
            注意：空指针指向的内存是不可以访问的
            0~255之间的内存编号是系统占用的，因此不可以访问
            野指针：指针变量指向非法的内存空间
            在程序中，应该尽量避免使用野指针
            空指针和野指针都不是我们申请的空间，因此不要访问
        5.const修饰指针
        `   const修饰指针有三种情况：
                1）const修饰指针 --常量指针
                const int *p = &a;
                特点：指针的指向可以修改，但是指针指向的值不可以修改
                2）const修饰常量 --指针常量
                int * const p = &a
                特点：指针指向不可以修改，但是指针指向的值可以修改
                3）const即修饰指针，又修饰常量
                const int * const p = &a
                特点：指针的指向和指针指向的值都不可以修改
        6.指针和数组
            作用：利用指针访问数组中的元素
        7.指针和函数
            作用：利用指针作函数参数，可以修改实参的值
        8.指针、数组、函数
            案例描述：封装一个函数，利用冒泡排序，实现对整型数组的升序排列
        
        
    */

    // int a = 10;
    // int *p;
    // p = &a;
    // cout << "a的地址为：" << &a << endl;
    // cout << "a的地址为：" << p << endl;
    // cout << "a的值为：" << a << endl;
    // cout << "a的值为：" << *p <<a endl;
    // cout << "p占的内存空间大小：" << sizeof(p) << endl;

    // int * p = NULL;
    // cout << "*p: " << *p << endl;

    // int * p = (int *)0x1100;
    // cout << *p << endl;

    // int arr[] = {1, 3, 4, 5, 5, 6, 7};
    // int * p = arr;
    // cout << *p << endl;
    // ++p;
    // cout << *p << endl;

    // int a = 10;
    // int b = 20;
    // swap02(&a, &b);
    // cout << "a= " << a << endl;
    // cout << "b= " << b << endl;

    int arr[] = {4, 8, 9, 1, 5, 6, 7, 2, 3};
    bubbleSort(arr, 9);
    for(int i=0; i<9; i++){
        cout << arr[i] << endl;
    }


    return 0;
}