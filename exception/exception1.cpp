#include<iostream>
using namespace std;

int main()
{
	double m, n;
	cin >> m >> n;
	try
	{
		cout<<"before dividing"<<endl;
		if (0 == n)
		{
			//Å×³öintÐÍÒì³£
			throw - 1;
		}
		else
			cout<<m/n<<endl;
		cout<<"after dividing"<<endl;
	}
	catch(double d)
	{
		cout << "catch(double)" <<d<< endl;
	}
	catch (int e)
	{
		cout << "catch(int)"<<e << endl;
	}
	cout << "finished" << endl;

	return 0;
}
