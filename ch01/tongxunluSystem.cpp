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
        cout << "full, can not continue" << endl;
        return;
    }
    else
    {
        string name;
        cout << "please input the name:" << endl;
        cin >> name;
        abs->personArray[abs->m_size].name = name;

        int sex = 0;
        while (true)
        {
            cout << "please input the sex:" << endl;
            cout << "1--- male" << endl;
            cout << "2--- female" << endl;
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_size].sex = sex;
                break;
            }
            cout << "wrong input, please input again !" << endl;
        }

        int age = 0;
        while (true)
        {
            cout << "please input the age: " << endl;
            cin >> age;
            if (age > 0)
            {
                // cout << abs->m_size << endl;
                abs->personArray[abs->m_size].age = age;
                break;
            }
            else
            {
                cout << "wrong input, please input again !" << endl;
                continue;
            }
        }
        string phone = "";
        cout << "please input the phone number:" << endl;
        cin >> phone;
        abs->personArray[abs->m_size].phone = phone;

        string address = "";
        cout << "please input the address:" << endl;
        cin >> address;
        abs->personArray[abs->m_size].address = address;

        abs->m_size++;
        cout << "add person successfully" << endl;
        system("pause");
        // system("cls");   //清屏(windows下可用)
    }
}

void showPerson(Addressbooks *abs)
{
    if (abs->m_size == 0)
    {
        cout << "empty" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_size; i++)
        {
            cout << "name " << abs->personArray[i].name << "\t";
            cout << "sex " << (abs->personArray[i].sex == 1 ? "male" : "female") << "\t";
            cout << "age " << abs->personArray[i].age << "\t";
            cout << "phone number " << abs->personArray[i].phone << "\t";
            cout << "address " << abs->personArray[i].address << endl;
        }
    }
}

void showMenu()
{
    cout << "***************************" << endl;
    cout << "******* 1. add person *******" << endl;
    cout << "******* 2. show persons *******" << endl;
    cout << "******* 3. delete person *******" << endl;
    cout << "******* 4. find person *******" << endl;
    cout << "******* 5. vertify person *******" << endl;
    cout << "******* 6. clean out *******" << endl;
    cout << "******* 0. quit *******" << endl;
    cout << "***************************" << endl;
}

int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_size; i++)
    {
        if (abs->personArray[i].name == name)
        {
            return i;
        }
        // else
        // {
        //     return -1;
        // }
    }
    return -1;
}

void deletePerson(Addressbooks * abs){
    cout << "please input the name you want to delete:" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1){
        for(int i = 0; i<abs->m_size-1; i++){
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_size--;
        cout << "delte succesfully" << endl;
    }
    else{
        cout << "no thi person" << endl;
    }
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
        {
            // cout << "please input the name you want to delete: " << endl;
            // string n;
            // cin >> n;
            // if (isExist(&abs, n) == -1){
            //     cout << "查无此人" << endl;
            // }
            // else{
            //     cout << "找到此人" << endl;
            // }
            deletePerson(&abs);
            break;
        }
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            cout << "welcome to next !" << endl;
            // system("pause");
            return 0;

        default:
            break;
        }
    }

    return 0;
}