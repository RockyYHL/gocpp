// 自己通用的数组类
#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        cout << "MyArray youcan gouzao " << endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pAddress = new T[this->m_capacity];
        cout << this->pAddress << endl;
    }

    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        cout << "MyArray kaobei gouzao " << endl;
        // cout << this->pAddress << endl;
        // // this->m_capacity = 0;
        // if (this->pAddress != NULL)
        // {
        //     cout << this->pAddress << endl;
        //     delete[] this->pAddress;           // 拷贝构造函数是 对象不存在，且用别的对象来初始化，就是拷贝构造函数 对象存在，用别的对象来给它赋值，就是赋值函数。
        //     cout << "222 " << endl;
        //     this->pAddress = NULL;
        //     this->m_capacity = 0;
        //     this->m_size = 0;
        //     cout << "333 " << endl;
        // }
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // this->pAddress = arr.pAddress;        浅拷贝
        this->pAddress = new T[arr.m_capacity];
        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // operator= 防止浅拷贝
    MyArray &operator=(const MyArray &arr)
    {
        cout << "MyArray operator= " << endl;
        // 先判断原来的堆区是否有数据，如果有先释放
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // this->pAddress = arr.pAddress;        浅拷贝
        this->pAddress = new T[arr.m_capacity];
        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    // 尾插法
    void push_back(const T & val){
        if(this->m_size == this->m_capacity){
            return;
        }
        this->pAddress[this->m_size] = val;
        this->m_size++;
    }

    // 尾删法
    void pop_back(){
        // 用户访问不到最后一个元素，即为尾删
        if(this->m_size == 0){
            return;
        }
        this->m_size--;
    }

    // 通过下标方式获取数组元素
    T& operator[](int index){
        return this->pAddress[index];
    }

    // 返回数组的容量
    int getCapacity(){
        return this->m_capacity;
    }

    // 返回数组的大小
    int getSize(){
        return this->m_size;
    }

    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            cout << "MyArray xigou " << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T *pAddress; // 指针指向堆区开辟的真实数组

    int m_capacity; // 数组容量

    int m_size;
};