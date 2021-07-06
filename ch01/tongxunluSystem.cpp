#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

#define MAX 1000

struct Person
{
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

struct Addressbooks
{
    struct Person personArray[MAX];
    int m_size;
};

void addPerson(Addressbooks *abs)
{
    if (abs->m_size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_size].name = name;

        int sex = 0;
        while (true)
        {
            cout << "请输入性别：" << endl;
            cout << "1---男" << endl;
            cout << "2---女" << endl;
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_size].sex = sex;
                break;
            }
            cout << "输入有误，请重新输入！" << endl;
        }

        int age = 0;
        while (true)
        {
            cout << "请输入年龄：" << endl;
            cin >> age;
            if (age > 0)
            {
                // cout << abs->m_size << endl;
                abs->personArray[abs->m_size].age = age;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入！" << endl;
                continue;
            }
        }
        string phone = "";
        cout << "请输入电话：" << endl;
        cin >> phone;
        abs->personArray[abs->m_size].phone = phone;

        string address = "";
        cout << "请输入家庭住址：" << endl;
        cin >> address;
        abs->personArray[abs->m_size].address = address;

        abs->m_size++;
        cout << "添加用户成功！" << endl;
        // system("pause");
        // system("cls");   //清屏(windows下可用)
    }
}

void showPerson(Addressbooks * abs){
    if(abs->m_size == 0){
        cout << "当前记录为空" << endl;
    }
    else{
        for(int i = 0; i < abs->m_size; i++){
            cout << "姓名： " << abs->personArray[i].name << "\t";
            cout << "性别： " << (abs->personArray[i].sex == 1 ? "男":"女") << "\t";
            cout << "年龄： " << abs->personArray[i].age <<"\t";
            cout << "电话： " << abs->personArray[i].phone <<"\t";
            cout << "地址： " << abs->personArray[i].address <<endl;
        }
    }
}

void showMenu()
{
    cout << "***************************" << endl;
    cout << "******* 1、添加联系人 *******" << endl;
    cout << "******* 2、显示联系人 *******" << endl;
    cout << "******* 3、删除联系人 *******" << endl;
    cout << "******* 4、查找联系人 *******" << endl;
    cout << "******* 5、修改联系人 *******" << endl;
    cout << "******* 6、清空联系人 *******" << endl;
    cout << "******* 0、退出通讯录 *******" << endl;
    cout << "***************************" << endl;
}

int main()
{
    Addressbooks abs;
    abs.m_size = 0;

    int select = 0;
    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:
            /* code */
            addPerson(&abs);
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            cout << "退出通讯录，欢迎下次使用！" << endl;
            // system("pause");
            return 0;

        default:
            break;
        }
    }

    return 0;
}