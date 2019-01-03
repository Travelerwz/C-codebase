#include<iostream>
using namespace std;

class Product
{
public:
	virtual void show() = 0;
};

class ProductA:public Product
{
public:
	void show()
	{
		cout<<"ProductA"<<endl;
	}
};

class ProductB:public Product
{
public:
	void show()
	{
		cout<<"ProductB"<<endl;
	}
};

class Factory
{
public:
	virtual Product* create() = 0;
};

class Factory_A:public Factory
{
public:
	Product* create()
	{
		return new ProductA();
	}
};

class Factory_B:public Factory
{
public:
	Product* create()
	{
		return new ProductB();
	}
};

int main()
{
	Factory_A* fa = new Factory_A();
	Factory_B* fb = new Factory_B();
	fa->create()->show();
	fb->create()->show();
	return 0;
}
