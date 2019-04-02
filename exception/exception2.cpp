#include<iostream>
#include<string>
using namespace std;

class CExeption
{
public:
	string msg;
	CExeption(string s)
	{
		msg = s;
	}
};

double Divide(double x,double y)
{
	if (0 == y)
	{
		throw CExeption("divide by zero");
	}

	cout << "ok" << endl;
	return x / y;
}

int ConTex(int salary)
{
	try
	{
		if (salary < 0)
		{
			throw - 1;
		}

	}
	catch (int)
	{
		cout << "salay is less than zero" << endl;
	}
	cout << "ending....." << endl;
}

int main()
{
	double f = 1.5;
	try
	{
		ConTex(-1);
		Divide(1,0);
	}
	catch(CExeption e)
	{
		cout<<"cexeption:"<<e.msg<<endl;
	}
	cout <<"finished"<< endl;
	return 0;
}
