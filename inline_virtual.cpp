#include<iostream>
using namespace std;

class Base
{
public:
	inline virtual void who()
	{
		cout<<"i am Base"<<endl;
	}
	virtual ~Base(){}
};

class Derived:public Base
{
public:
	inline void who()
	{
		cout<<"i am Derived"<<endl;
	}
};

int main()
{
	//此处的虚函数who()，是通过Base对象b来调用，编译期间可以确定
	//所以可以是内联的，单最终取决于编译器
	Base b;
	b.who();
	
	//此处的虚函数是通过指针来调用的，呈现的是多态，需要在编译期间才能确定
	//所以不能是内联
	Base* ptr = new Derived();
	ptr->who();
	
	delete ptr;
	ptr = NULL;
	
	return 0;
}
