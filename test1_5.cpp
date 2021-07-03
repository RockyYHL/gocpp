#include <iostream>
using namespace std;

// 1.宏常量  （定义常量的两种方法）
#define day 7

int main()
{

    /* 
        一维数组的定义方式:
        1. 数据类型 数组名[数组长度];
        2. 数据类型 数组名[数组长度] = {value1, value2 ...};
        3. 数据类型 数组名[ ] = {value1, value2 ...};  

        一维数组名称的用途：
        1.可以统计整个数组在内存中的长度 sizeof(arr)
        2.可以获取数组在内存中的首地址
    */

    // int arr[] = {1, 2, 3, 4, 5};
    // cout << sizeof(arr) << endl;
    // cout << sizeof(arr[2]) << endl;
    // cout << *arr << endl;

    // 实现数组逆置
    // int arr[] = {1, 2, 3, 4, 5};
    // for (int i=0;i<5;i++){
    //     cout << arr[i] << endl;
    // }

    // int temp = 0;
    // int end = sizeof(arr) / sizeof(arr[0]) - 1;
    // for (int i=0;i<end;i++){
    //     temp = arr[i];
    //     arr[i] = arr[end];
    //     arr[end] = temp;
    //     end -= 1;
    // }

    // for (int i=0;i<5;i++){
    //     cout << arr[i] << endl;
    // }

    /*
        冒泡排序:
        1.总共排序轮数： 元素个数 - 1
        2.内层循环对比次数： 元素个数 - 当前轮数 - 1
        3.如果第一个数字比第二个数字大，交换两个数字
    */
    // int arr[] = {4, 2, 8, 0, 6, 9, 1, 5, 3, 10};
    // for(int i=0;i<10-1;i++){
    //     int temp = 0;
    //     for(int j=0;j<10-1-i;j++){
    //         if(arr[j]>arr[j+1]){
    //             temp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = temp;
    //         }
    //     }
    // }
    // for (int i=0;i<10;i++){
    //     cout << arr[i] << endl;
    // }

    /*
        二维数组定义的四种方式：
        1.数据类型 数组名[row][col];
        2.数据类型 数组名[row][col] = {{v1, v2}, {v3, v4}};
        3.数据类型 数组名[row][col] = {v1, v2, v3, v4};
        4.数据类型 数组名[row][col] = {v1, v2, v3, v4};
    */



    return 0;
}