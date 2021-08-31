#include <iostream>
#include <string>
using namespace std;

/*
    3 STL常用容器

        3.1.1 String基本概念
            本质： string是C++风格的字符串，而string本质上是一个类

            string和char*区别：
                - char * 是一个指针
                - string 是一个类，类内部封装了 char*,管理这个字符串，是一个 char* 型的容器

            特点： 
                string 类内部封装了很多成员方法
                例如： 查找find， 拷贝copy， 删除delete， 替换replace， 插入intert
                string 管理 char* 所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

        3.1.2 string构造函数
            构造函数原型：
                - string();           // 创建一个空的字符串 例如： string str;
                  string(const char* s);   // 使用字符串初始化
                - string(const string& str);   // 使用一个string对象初始化另一个string对象
                - string(int n, char c);       // 使用n个字符c初始化

                总结： string的多种构造方式没有可比性，灵活使用即可

        3.1.3 string赋值操作
            功能描述： 给string字符串进行赋值
        
        3.1.4 string字符串拼接
            功能描述：实现在字符串末尾进行拼接字符串
        
        3.1.5 string查找和替换
            功能描述：
                - 查找： 查找指定字符串是否存在
                - 替换： 在指定的位置替换字符串

        3.1.6 string字符串比较
            功能描述：
                - 字符串之间比较
            比较方式：
                - 字符串比较是按字符的ASCII码进行对比
                = 返回0
                > 返回1
                < 返回-1

        3.1.7 string字符存取
            string中单个字符存取方式有两种

        3.1.8 string插入和删除
            功能描述：
                对string字符串进行插入和删除的操作

        3.1.9 string子串
            功能描述：
                从字符串中截取想要的子串
        
        
*/

// string 构造函数
void test01()
{
    string s1;
    const char *str = " nihao ";
    string s2(str);

    cout << "s2 = " << s2 << endl;
}

void test02()
{
    string str;
    str.assign("hello C++");
    cout << "str = " << str << endl;

    string str2;
    str2.assign("hello c++", 5);
    cout << "str2 = " << str2 << endl;

    string str3;
    str3.assign(str2);
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("w", 10);
    cout << "str4 = " << str4 << endl;
}

void test03()
{
    string str = "wo";
    str += " love playing games";
    cout << "cout = " << str << endl;

    string str2 = "wangzherongyao cf";
    str2 = str + str2;
    cout << "cout = " << str2 << endl;

    string str3;
    str3 = str2.append("mlgb");
    cout << "cout = " << str3 << endl;

    string str4;
    str4 = str2.append("mlgb", 2);
    cout << "cout = " << str4 << endl;

    string str5;
    str5.append(str, 0, 7);
    cout << "cout = " << str5 << endl;
}

void test04()
{
    string str1 = "abcdef";
    int pos = str1.find("de");

    cout << "pos = " << pos << endl; // 第一次出现的位置

    int pos2 = str1.find("ya");

    cout << "pos2 = " << pos2 << endl; // -1

    int pos3 = str1.rfind("e");

    cout << "pos3 = " << pos3 << endl; // rfind 从右往左

    str1.replace(0, 2, "fuck");
    cout << "str1 = " << str1 << endl;  // 从 0 开始，替换 2 个字符

}

void test05(){
    string str1 = "yang";
    string str2 = "huanli";

    int r = str1.compare(str2);
    cout << r << endl;
}

void test06(){
    string str = "adafsasdf";

    for(int i = 0; i < str.size(); i++){
        cout << str[i] << endl;
    }

    for(int i = 0; i < str.size(); i++){
        cout << str.at(i) << endl;
    }
    
}

void test07(){
    string str = "hello";
    str.insert(2, "111");           // 在第 2 个位置开始
    cout << str << endl;

    str.erase(2, 3);
    cout << str << endl;

    string str2 = "zhangsan@sina.com";
    int index = str2.find("@");
    string username = str2.substr(0, index);   // 从 0 开始，截取 4 个
    cout << username << endl;

}

int main()
{

    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    test07();
    return 0;
}