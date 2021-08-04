#include <iostream>
#include <fstream>
using namespace std;

/*
    5 文件操作

        程序运行时产生的数据都属于临时数据，程序一旦运行结束否会被修改
        通过文件可以将数据持久化
        C++中对文件操作需要包含头文件 <fstream>

        文件类型分为两种：
            1. 文本文件 - 文件以文本的ASCII码形式存储在计算机中
            2. 二进制文件 - 文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

        操作文件的三大类：
            1. ofstream 写操作
            2. ifstream 读操作
            3. fstream 读写操作

    5.1 文本文件

        5.1.1 写文件

        写文件步骤如下：
            1.包含头文件
                #include <fstream>
            2.创建流对象
                ofstream ofs;
            3.打开文件
                ofs.open("文件路径"， 打开方式)；
            4.写数据
                ofs << "写入的数据";
            5.关闭文件
                ofs.close();

        文件打开方式（表格）：
            打开方式                                                   解释
            ios::in                                             为读文件而打开文件
            ios::out                                            为写文件而打开文件
            ios::ate                                            初始位置：文件尾
            ios::app                                            追加方式写文件
            ios::trunc                                          如果文件中存在先删除，在创建
            ios::binary                                         二进制方式

        注意： 文件打开方式可以配合使用，利用 | 操作符

    5.1.2 读文件
        读文件与写文件步骤相似，但是读取方式相对于比较多

        读文件步骤如下：
            1.包含头文件
                #include <fstream>
            2.创建流对象
                    ifstream ifs;
            3.打开文件并判断文件是否打开成功
                ifs.open("文件路径"， 打开方式);
            4.读数据
                四种方式读数据
                    1.
                        char buf[1024] = {0};
                        while(ifs >> buf){
                            cout << buf << endl;
                        }
                    2.
                        char buf[1024] = {0};
                        while(ifs.getline(buf, 1024)){
                            cout << buf << endl;
                        }
                    3.
                        string buf;
                        while(getline(ifs, buf)){
                            cout << buf << endl;
                        }
                    4.
                        char c;
                        while((c = ifs.get()) != EOF){
                            cout << c ;
                        }
            5.关闭文件
                ifs.close();
    5.2 二进制文件

    以二进制的形式对文件进行读写操作
    打开方式要指定为 ios::binary

    5.2.1 写文件
        二进制方式写文件主要利用流对象调用成员函数 write
        函数原型： ostream& write(const char *buffer, int len);
        参数解释：字符指针buffer指向内存中一段存储空间，len是读写的字节数

        总结： 文件输出流对象 可以通过write函数，以二进制方式写数据
    5.2.2 读文件
        二进制方式读文件主要利用流对象调用成员read
        函数原型： istream& read(char *buffer, int len);
        参数解释： 字符指针buffer指向内存中一段空间，len是读写的字符数
*/

void test01()
{
    ofstream ofs;

    ofs.open("test.txt", ios::out);
    ofs << "name: zhangsan" << endl;
    ofs << "sex: male" << endl;
    ofs << "age: 18" << endl;

    ofs.close();
}

void test02()
{
    ifstream ifs;

    ifs.open("test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "file open failed" << endl;
        return;
    }
    // char buf[1024] = {0};
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }
    // char buf[1024] = {0};
    // while (ifs.getline(buf, 1024))
    // {
    //     cout << buf << endl;
    // }
    string buf;
    while (getline(ifs, buf))
    {
        cout << buf << endl;
    }
    // char c;
    // while ((c = ifs.get()) != EOF)
    // {
    //     cout << c;
    // }
}

class Person
{
public:
    // Person(char name, int age)
    // {
    //     m_name = name;
    //     m_age = age;
    // }
    char m_name[64];
    int m_age;
};

void test03()
{
    ofstream ofs;
    ofs.open("person.txt", ios::out | ios::binary);
    Person p = {"zhangsan", 18};
    ofs.write((const char *)&p, sizeof(Person));
    ofs.close();
}

void test04()
{
    ifstream ifs;
    ifs.open("person.txt", ios::in | ios::binary);
    if (!ifs.is_open()){
        cout << "read file failed" << endl;
        return;
    }
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "name: " << p.m_name << " age: " << p.m_age << endl;

    ifs.close();
}

int main()
{

    // test01();
    // test02();
    // test03();
    test04();
    return 0;
}