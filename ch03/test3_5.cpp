#include <iostream>
using namespace std;
#include <stack>

/*
    3.5 stack
    3.5.1
        概念：stack是一种先进后出(first in last out, FILO)的数据结构，它只有一个出口
        栈中只有栈顶的元素才可以被外界使用，因此栈中不允许有遍历行为
        栈容器 符合先进后出

    3.5.2 stack常用接口
        功能描述：栈容器常用的对外接口(就这么几个)

*/

void test01()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // 只要栈不为空，查看栈顶，并且执行出栈操作
    while(!s.empty()){
        cout << "ele in top: " << s.top() << endl;

        // 出栈
        s.pop();
    }

    cout << "stack size is : " << s.size() << endl;

}

int main()
{

    test01();
    return 0;
}