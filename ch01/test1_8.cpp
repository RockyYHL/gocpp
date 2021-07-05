#include <iostream>
using namespace std;
#include "/home/yhl/yhl/gocpp/include/swap.h"

// 学生结构体
struct Student
{
    string name;
    int age;
    int score;
} s3;

struct Student2
{
    string name;
    int score;
};

struct teacher
{
    string name;
    int age;
    int id;
    struct Student stu;
};

struct teacher2
{
    string name;
    struct Student2 stu[3];
};

void printStudent1(struct Student s)
{
    s.age = 99;
    cout << s.age << s.name << s.score << endl;
}

void printStudent2(const struct Student *p)
{
    // p->age = 99;
    cout << p->age << p->name << p->score << endl;
}

void setTeacherAndStudent(struct teacher2 tArray[], int len)
{
    string nameSeed = "ABCDE";
    for(int i = 0; i < len; i++){
        tArray[i].name = "Teacher_";
        tArray[i].name += nameSeed[i];

        string stuSeed = "ABC";
        for(int j = 0; j < 3; j++){
            tArray[i].stu[j].name = "Student_";
            tArray[i].stu[j].name += stuSeed[j];
            tArray[i].stu[j].score = 90 + j * 2;
        }
    }
}

void printInfo(struct teacher2 tArray[], int len){
    for(int i = 0; i < len; i++){
        cout << "第"<< i+1 << "个老师姓名： " << tArray[i].name << endl;
        for(int j = 0; j < 3; j++){
            cout << "\t第" << j+1 << "个学生的姓名： " << tArray[i].stu[j].name \
            << "  成绩：" << tArray[i].stu[j].score << endl;
        }
    }
}

int main()
{
    /*
        1.结构体的基本概念
            结构体属于用户自定义的数据类型，允许用户存储不同的数据类型
        2.结构体定义和使用
            语法：struct name {member list};
            通过结构体创建变量的三种方式：
                1）struct name 变量名
                2）struct name 变量名={v1, v2, ...}
                3)定义结构体时顺便创建变量
            用 . 来访问数据
        3.结构体数组
            作用：将自定义的结构体放入到数组中方便维护
            语法：struct name 数组名[元素个数] = {{}， {}，...}
        4.结构体指针
            作用：通过指针访问结构体中的成员
            利用操作符 -> 可以通过结构体指针访问结构体属性
        5.结构体嵌套结构体
            作用：结构体中的成员可以是另一个结构体
            例如：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体
        6.结构体做函数参数
            作用：将结构体作为参数向函数中传递
            传递方式有两种：
                地址传递
                值传递
            如果不想修改主函数中的数据，用值传递，反之用地址传递
        7.结构体中const使用场景
            作用：用const来防止函数体中的误操作
            将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本出来
        8.结构体案例
git同步和拉取的区别
    */

    // s3.age = 10;
    // s3.name = "zhangsan";
    // s3.score = 100;
    // cout << s3.age << s3.name << s3.score << endl;

    // 结构体数组
    // struct Student stuArray[] = {
    //     {"zhanfsan", 18, 100},
    //     {"lisi", 32, 43},
    //     {"wangwu", 34, 54}

    // };
    // for(int i=0; i<3; i++){
    //     cout << stuArray[i].age << stuArray[i].name << stuArray[i].score << endl;
    // }

    // struct Student s = {"yanghuanli", 26, 100};
    // struct Student * p = &s;
    // cout << p->age << p->name << p->score << endl;

    // struct teacher t;
    // t.name = "你爹";
    // t.age = 20;
    // t.id = 1;
    // t.stu.name = "小王八";
    // t.stu.age = 12;
    // t.stu.score = 59;

    // printStudent1(s);
    // cout << s.age << endl;
    // printStudent2(&s);
    // cout << s.age << endl;

    // struct Student s = {"你爹", 26, 100};
    // printStudent1(s);
    // struct Student s2 = {"你爹", 26, 100};
    // printStudent2(&s2);

    struct teacher2 teachers[3];
    setTeacherAndStudent(teachers, 3);
    printInfo(teachers, 3);

    

    return 0;
}