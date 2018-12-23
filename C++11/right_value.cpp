/*
	*@param
	*@C++11 特性：右值引用
*/

#include<iostream>
using namespace std;


void process_value(int& a)
{
	cout<<"a"<<a<<endl;
}

void process_value(int &&a)
{
	cout<<"a:"<<a<<endl;
}
int main()
{
	int a=0;
	process_value(a);
	process_value(2);
	return 0;
}

//编译：g++ -std=c++11 right_value.cpp -o right_value
