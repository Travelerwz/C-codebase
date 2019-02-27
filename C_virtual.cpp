#include<iostream>
#include<stdio.h>
using namespace std;

typedef void(*FUN)();//重定义一个函数指针类型

//父类
struct Base 
{
    FUN _f;
};

//子类
struct Derived
{
    Base _b;//在子类中定义一个基类的对象即可实现对父类的继承
};


void FunB()
{
    printf("%s\n", "Base::fun()");
}
void FunD()
{
    printf("%s\n", "Derived::fun()");
}

int main()
{
    Base b;//父类对象
    Derived d;//子类对象

    b._f = FunB;//父类对象调用父类同名函数
    d._b._f = FunD;//子类调用子类的同名函数

    Base *pb = &b;//父类指针指向父类对象
    pb->_f();

    pb = (Base *)&d;//让父类指针指向子类的对象,由于类型不匹配所以要进行强转
    pb->_f();
    
    return 0;

}
