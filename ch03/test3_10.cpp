#include <iostream>
using namespace std;
#include <vector>
#include <map>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

/*
    3.10 案例-员工分组
    3.10.1 案例描述
        - 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在哪个部门工作
        - 员工信息有： 姓名  工资组成； 部门分为： 策划，美术，研发
        - 随机给10名员工分配部门和工资
        - 通过multimap进行信息的插入，key（部门编号）value（员工）
        - 分部门显示员工信息
    
    3.10.2 实现步骤
        1.创建10名员工，放到vector中
        2.遍历vector容器，取出每个员工，进行随机分组
        3.分组后，将员工部门编号为key，具体员工作为value，放入到multimap容器中
        4.分部门显示员工信息
*/

class Worker
{
public:
    string name;
    int salary;
};

void createWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.name = "worker";
        worker.name += nameSeed[i];
        worker.salary = rand() % 10000 + 10000; // 10000~19999
        v.push_back(worker);
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 随机产生部门编号
        int depId = rand() % 3;
        m.insert(make_pair(depId, *it));
    }
}

void showWorkerGroup(multimap<int, Worker> &m)
{
    cout << "CEHUA department info: " << endl;
    
}

int main()
{
    vector<Worker> vWorker;
    createWorker(vWorker);

    // 测试
    for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    {
        cout << "name: " << it->name << "\tsalary: " << it->salary << endl;
    }

    // 员工分组
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    // 分组显示员工
    showWorkerGroup(mWorker);
}