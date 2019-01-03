#include<iostream>
using namespace std;

class Strategy
{
public:
	virtual void Travel() = 0;
};

class Mobai:public Strategy
{
public:
	void Travel()
	{
		cout<<"Travel is mobai"<<endl;
	}
};

class Car:public Strategy
{
public:
	void Travel()
	{
		cout<<"Travel is Car"<<endl;
	}
};

class Contex
{
public:
	Contex(Strategy* tr)
	{
		op = tr;
	}
	void Get()
	{
		op->Travel();
	}
private:
	//ةº
	Strategy* op;
};


int main()
{
	Mobai* m = new Mobai();
	Car* c = new Car();
	
	Contex* mb = new Contex(m);
	Contex* ca = new Contex(c);
	
	mb->Get();
	ca->Get();
	return 0;
}
