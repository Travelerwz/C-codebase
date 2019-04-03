#include<iostream>
using namespace std;

class Base
{
public:
	virtual void fun() {}
};

class Derived :public Base
{
public:
	void Print() {}
};

void PrintObj(Base& b)
{
	try
	{
		Derived& rd = dynamic_cast<Derived&>(b);
		rd.Print();
	}
	catch (bad_cast& e)
	{
		cout << e.what()<<endl;
	}
}
int main()
{
	Base b;
	PrintObj(b);
	return 0;
}
