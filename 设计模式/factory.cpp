#include<iostream>
using namespace std;

class Operator
{
public:
	int value1;
	int value2;
	virtual int GetResult() = 0;
};

class ADD:public Operator
{
	int GetResult()
	{
		return value1+value2;
	}
};

class SUB:public Operator
{
public:
	int GetResult()
	{
		return value1-value2;
	}
};

class Factory
{
public:
	static Operator* Create(char ch);
};

Operator* Factory::Create(char ch)
{
	Operator* oper;
	switch(ch)
	{
		case'-':
			oper = new SUB();
			break;
		case'+':
			oper = new ADD();
			break;
		default:
			oper = new ADD();
			break;
	}
	return oper;
}

int main()
{
	int a = 2;
	int b = 3;
	Operator* op = Factory::Create('+');
	op->value1 = a;
	op->value2 = b;
	cout<<op->GetResult();
	return 0;
}
