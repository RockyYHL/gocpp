#include <iostream>
using namespace std;

/*
    4.7 多态

    4.7.1 多态的基本概念
        多态是C++面向对象的三大特性之一
        多态分为两类：
            - 静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
            - 动态多态：派生类和虚函数实现运行时多态
        静态多态和动态多态的区别：
         - 静态多态的函数地址早绑定 - 编译阶段确定函数地址
         - 动态多态的函数地址晚绑定 - 运行阶段确定函数地址

        动态多态满足条件：
            1、有继承关系
            2、子类要重写父类的虚函数
        动态多态的使用： 父类的指针或者引用，执行子类的对象
        重写： 函数返回值类型，函数名，参数列表 完全一致称为重写

        有虚函数的的Animal类的结构： 
            虚函数（表）指针
                虚函数表内记录的是虚函数的地址
        当子类重写父类的虚函数，子类中的虚函数表 内部 会替换成 子类的虚函数地址
        当父类的指针或者引用指向子类对象时候，发生多态

    4.7.2 多态的案例--计算机类
        案例描述： 分别利用普通写法和多态技术，设计两个操作数进行运算的计算机类

        多态的优点：
            - 代码组织结构清晰
            - 可读性强
            - 利于前期和后期的扩展以及维护
        不使用多态的话，想要扩展新的功能，需要修改源码
        在真实开发中，提倡 开闭原则
        开闭原则： 对扩展进行开发，对修改进行关闭

    4.7.3 纯虚函数和抽象类
        在多态中，通常父类中虚函数的实现是无意义的，主要都是调用子类重写的内容
        因此可以将虚函数改为纯虚函数
        纯虚函数的语法： virtual 返回值类型 函数名 （参数列表） = 0；
        当类中有了纯虚函数，这个类也称为抽象类
        抽象类特点：
         - 无法实例化对象
         - 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

        多态的目的：
            就是让我们函数的接口更通用化，通过一个父类指针，由于你创建的对象不同，可以调用不同形态的函数

    4.7.4 多态案例二 制作饮品
        案例描述：制作音频的大致流程为：煮水、冲泡、倒入杯中，加入辅料
        利用多态技术实现本案例，提供抽象制作音频基类，提供子类制作咖啡和茶叶

    4.7.5 虚析构和纯虚析构
        （都是为了使用多态时 子类对象中 析构函数调用不到的问题）
        多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用子类的析构代码
        解决方式：将父类中的析构函数改为虚析构或者纯虚析构
        虚析构和纯虚析构共性：
            - 可以解决父类指针释放子类对象
            - 都需要有具体的函数实现
        虚析构和纯虚析构区别：
            - 如果是纯虚析构，该类属于抽象类，无法实例化对象

        总结：
            1.虚析构或纯虚析构都是用来解决通过父类指针释放子类对象
            2.如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
            3.拥有纯虚析构函数的类也属于抽象类

    4.7.8 多态案例三-电脑组装
        案例描述：
            电脑主要组成部件为CPU（用于计算），显卡（用于显示），内存条（用于存储）
            将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如intel厂商和Lenovo厂商
            创建电脑类提供让电脑工作的函数，并且用每个零件工作的接口
            测试时组装三台不同的电脑进行工作

*/

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal is speaking" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat is speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Dog is speaking" << endl;
    }
};

void doSpeak(Animal &animal)
{
    animal.speak();
}

// void doSpeak(Cat &cat){      // 函数重载，静态绑定，编译时绑定
//     cat.speak();
// }

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

void test02()
{
    cout << "sizeof Animal: " << sizeof(Animal) << endl;
}

class Calculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_num1 + m_num2;
        }
        else if (oper == "-")
        {
            return m_num1 - m_num2;
        }
        else if (oper == "*")
        {
            return m_num1 * m_num2;
        }
        else
        {
            return m_num1 / m_num2;
        }
    }

    int m_num1;
    int m_num2;
};

void test03()
{
    Calculator c;
    c.m_num1 = 10;
    c.m_num2 = 10;

    cout << c.m_num1 << "+" << c.m_num2 << "=" << c.getResult("+") << endl;
    cout << c.m_num1 << "-" << c.m_num2 << "=" << c.getResult("-") << endl;
    cout << c.m_num1 << "*" << c.m_num2 << "=" << c.getResult("*") << endl;
    cout << c.m_num1 << "/" << c.m_num2 << "=" << c.getResult("/") << endl;
}

class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }

    int m_num1;
    int m_num2;
};

class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 + m_num2;
    }
};

class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 - m_num2;
    }
};

class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 * m_num2;
    }
};

class ChuCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 / m_num2;
    }
};

void test03_2()
{
    AbstractCalculator *abc = new AddCalculator;
    abc->m_num1 = 10;
    abc->m_num2 = 20;

    cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->getResult() << endl;
    delete abc;

    abc = new SubCalculator;
    abc->m_num1 = 10;
    abc->m_num2 = 20;
    cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getResult() << endl;
    delete abc;

    abc = new MulCalculator;
    abc->m_num1 = 10;
    abc->m_num2 = 20;
    cout << abc->m_num1 << "*" << abc->m_num2 << "=" << abc->getResult() << endl;
    delete abc;

    abc = new ChuCalculator;
    abc->m_num1 = 10;
    abc->m_num2 = 20;
    cout << abc->m_num1 << "/" << abc->m_num2 << "=" << abc->getResult() << endl;
    delete abc;
}

// 纯虚函数和抽象类,只要有一个纯虚函数，这个类就是抽象类，无法实例化对象
class Base
{
public:
    virtual void func() = 0; // 纯虚函数
};

class Son : public Base
{
public:
    virtual void func()
    { // 子类必须重写纯虚函数，否则无法实例化对象
        cout << "Son func diaoyong" << endl;
    }
};

void test04()
{
    // Base b;
    // Son s;
    Base *base = new Son;
    base->func();
    delete base;
}

class AbstractDrinking
{
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSomeThing() = 0;
    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomeThing();
    }
};

class Coffe : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "boil nongfushanquan" << endl;
    }
    virtual void Brew()
    {
        cout << "brew coffe" << endl;
    }
    virtual void PourInCup()
    {
        cout << "pour coffe in cup" << endl;
    }
    virtual void PutSomeThing()
    {
        cout << "put some sugar and milk" << endl;
    }
};

class Tea : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "boil kuangquanshui" << endl;
    }
    virtual void Brew()
    {
        cout << "brew tea" << endl;
    }
    virtual void PourInCup()
    {
        cout << "pour tea in cup" << endl;
    }
    virtual void PutSomeThing()
    {
        cout << "put some lemon" << endl;
    }
};

void doWork(AbstractDrinking *abs)
{
    abs->makeDrink();
    delete abs;
}

void test04_2()
{
    // coffe
    doWork(new Coffe);
    cout << "*********************" << endl;
    doWork(new Tea);
}

class Animal2
{
public:
    Animal2()
    {
        cout << "Animal2 gouzao is using" << endl;
    }
    virtual void speak() = 0;
    // 利用虚析构可以解决父类指针释放子类对象时不干净的问题
    // virtual ~Animal2(){
    //     cout << "Animal2 xigou is using" << endl;
    // }

    virtual ~Animal2() = 0; // 纯虚析构 需要声明也需要实现
};

Animal2::~Animal2()
{
    cout << "chun xuxigou is using" << endl;
}

class Cat2 : public Animal2
{
public:
    Cat2(string name)
    {
        cout << "Cat2 gouzao is using" << endl;
        m_name = new string(name);
    }
    virtual void speak()
    {
        cout << *m_name << " little cat is speaking" << endl;
    }
    string *m_name;

    ~Cat2()
    {
        cout << "Cat2 xigou is using" << endl;
        if (m_name != NULL)
        {
            delete m_name;
            m_name = NULL;
        }
    }
};

void test05()
{
    Animal2 *animal = new Cat2("Tom");
    animal->speak();
    delete animal; // 父类指针在析构的时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄露
}

// 抽象不同零件类
class CPU
{
public:
    virtual void calculate() = 0;
};

class GraphicCard
{
public:
    virtual void display() = 0;
};

class Memory
{
public:
    virtual void storage() = 0;
};

class Computer
{
public:
    Computer(CPU *cpu, GraphicCard *gc, Memory *mem)
    {
        this->m_cpu = cpu;
        this->m_gc = gc;
        this->m_mem = mem;
    }
    void work()
    {
        m_cpu->calculate();
        m_gc->display();
        m_mem->storage();
    }

    virtual ~Computer(){
        if(m_cpu != NULL){
            delete m_cpu;
            m_cpu = NULL;
        }
        if(m_gc != NULL){
            delete m_gc;
            m_gc = NULL;
        }
        if(m_mem != NULL){
            delete m_mem;
            m_mem = NULL;
        }
    }

private:
    CPU *m_cpu;
    GraphicCard *m_gc;
    Memory *m_mem;
};

class IntelCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Intel CPU is working" << endl;
    }
};

class IntelGraphicCard : public GraphicCard
{
public:
    virtual void display()
    {
        cout << "Intel GPU is displaying" << endl;
    }
};

class IntelMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Intel Memory is storaging" << endl;
    }
};

class LenovoCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Lenovo CPU is working" << endl;
    }
};

class LenovoGraphicCard : public GraphicCard
{
public:
    virtual void display()
    {
        cout << "Lenovo GPU is displaying" << endl;
    }
};

class LenovoMemory : public Memory
{
public:
    virtual void storage()
    {
        cout << "Lenovo Memory is storaging" << endl;
    }
};

void test06()
{   
    CPU * intelCPU = new IntelCPU;
    GraphicCard * intelGc = new IntelGraphicCard;
    Memory * intelMem = new IntelMemory;

    Computer * computer1 = new Computer(intelCPU, intelGc, intelMem);
    computer1->work();
    delete computer1;

    CPU * lenovoCPU = new LenovoCPU;
    GraphicCard * lenovoGc = new LenovoGraphicCard;
    Memory * lenovoMem = new LenovoMemory;

    Computer * computer2 = new Computer(lenovoCPU, lenovoGc, lenovoMem);
    computer2->work();
    delete computer2;

    Computer * computer3 = new Computer(new IntelCPU, new LenovoGraphicCard, new IntelMemory);
    computer3->work();
    delete computer3;


}

int main()
{
    // test01();
    // test02();
    // test03();
    // test03_2();
    // test04();
    // test04_2();
    // test05();
    test06();
    return 0;
}