#include <iostream>
using namespace std;

/*
    C++提高编程
        本阶段主要对C++泛型编程和STL技术做详细讲解，探讨C++更深层次的使用

    1 模板
    1.1 模板的概念
        模板就是建立通用的模板，大大提高复用性

        模板的特点：
        - 模板不可以直接使用，它只是一个框架
        - 模板的通用并不是万能的

    1.2函数模板
        - C++另一种编程思想成为 泛型编程，主要利用的技术就是模板
        - C++提供两种模板机制：函数模板 和 类模板

        1.2.1函数模板语法
            函数模板作用：
            建立一个通用函数，其函数返回值类型和形参可以不具体制定，用一个虚拟的类型来代表

            语法：
                template<typename T>
                函数声明或定义
            解释：
                template -- 声明创建模板
                typename -- 表名其后面的符号是一种数据类型，可以用class代替
                T -- 通用的数据类型，名称可以替换，通常为大写字母

            总结：
             - 函数模板利用关键字 template
             - 使用函数模板有两种方式：自动类型推导、显示指定类型
             - 模板的目的是为了提高复用性，将类型参数化

        1.2.2函数模板注意事项
            注意事项：
                - 自动类型推导，必须导出一致的数据类型T，才可以使用
                - 模板必须要确定出T的数据类型，才可以使用
            
        1.2.3函数模板案例
            案例描述：
                - 利用模板封装一个排序的函数，可以对不同数据类型数组进行排序
                - 排序规则从大到小，排序算法为选择排序
                - 分别利用char数组和int数组进行测试

        1.2.4普通函数与函数模板的区别
            普通函数与函数模板的区别：(会不会发生隐式类型转换)
                - 普通函数调用时可以发生自动类型转换（隐式类型转换）
                - 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
                - 如果利用显示指定类型的方式，可以发生隐式类型转换

        1.2.5普通函数与模板函数调用规则
            调用规则如下：
                1.如果函数模板和普通模板都可以实现，优先调用普通函数
                2.可以通过空模板参数列表来强制调用函数模板
                3.函数模板也可以发生重载
                4.如果函数模板可以产生更好的匹配，优先调用函数模板

            总结：既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性

        1.2.5模板的局限性
            局限性：模板的通用性并不是万能的

            如果T的数据类型传入的是像Person这样的自定义数据，也无法正常运行
            因此为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板

            总结：
                - 利用具体化的模板，可以解决自定义类型的通用化
                - 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板




*/

// 交换两个整型函数
void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//交换两个浮点型函数
void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

//函数模板
template <typename T> // 声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用的数据类型, typename可以替换成class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{

    /*
        两种方法使用模板交换(类型参数化)
        1.自动类型推导
        2.显示制定类型

    */

    int a = 20;
    int b = 10;
    // swapInt(a, b);
    // mySwap(a, b);
    mySwap<int>(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    double c = 1.1;
    double d = 2.2;
    // swapDouble(c, d);
    mySwap(c, d);

    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    char e = 'e';
    char f = 'f';
    // swapDouble(c, d);
    mySwap(e, f);

    cout << "e = " << e << endl;
    cout << "f = " << f << endl;
}

template <class T>
void mysort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; // 认定最大值的下标
        for (int j = i + 1; j < len; j++)
        {
            // 认定的最大值 比 遍历出的数值 要小， 说明 j下标的元素才是真正的最大值
            if (arr[max] < arr[j])
            {
                max = j; // 更新最大值下标
            }
        }

        if (max != i)
        {
            mySwap(arr[max], arr[i]);
        }
    }
}

template <class T>
void printArr(T arr[], int len)
{
    cout << *arr << endl;
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test02()
{
    // 测试char数组
    char charArr[] = "gfadcbe";
    int len = sizeof(charArr) / sizeof(char);
    // cout << "len of char[]: " << len << endl;

    int intArr[] = {5, 3, 2, 6, 1, 4};
    int intlen = sizeof(intArr) / sizeof(int);

    // mysort(charArr, len);
    // printArr(charArr, len);

    mysort(intArr, intlen);
    printArr(intArr, intlen);
}

int myAdd01(int a, int b)
{
    return a + b;
}

template <class T>
T myAdd02(T a, T b)
{
    return a + b;
}

void test03()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    cout << myAdd02<int>(a, c) << endl;
}

void myPrint(int a, int b);
// void myPrint(int a, int b){
//     cout << "putong function" << endl;
// }

template <class T>
void myPrint(T a, T b)
{
    cout << "template function" << endl;
}

template <class T>
void myPrint(T a, T b, T c)
{
    cout << "chongzai template function" << endl;
}

void test04()
{
    int a = 10;
    int b = 10;
    int c = 10;
    // myPrint<>(a, b);     //通过空模板参数列表，强制调用函数模板
    // myPrint(a, b, c);
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);
}

template <class T>
bool myCompare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class Person
{
public:

    Person(string name, int age){
        this->m_name = name;
        this->m_age = age;
    }

    string m_name;
    int m_age;
};

template <> bool myCompare(Person &a, Person &b)
{
    if (a.m_age == b.m_age && a.m_name == a.m_name)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void test05()
{
    int a = 3;
    int b = 5;

    bool ret = myCompare(a, b);

    if (ret)
    {
        cout << "a == b" << endl;
    }
    else
    {
        cout << "a != b" << endl;
    }

    Person p1("Tom", 10);
    Person p2("Tom", 10);

    bool ret2 = myCompare(p1, p1);

    if (ret2)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }

}

int main()
{

    // test01();
    // test02();
    // test03();
    // test04();
    test05();

    return 0;
}