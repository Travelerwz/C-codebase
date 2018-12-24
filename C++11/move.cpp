/*
	C++11特性  move函数使用
	可以提高程序的效率，
  编译器区分了左值和右值，对右值调用了转移构造函数和转移赋值操作符。
  节省了资源，提高了程序运行的效率。
*/

#include<iostream>
using namespace std;

template<class T>
void Swap(T &a,T &b)
{
	T tmp = move(a);
	a = move(b);
	b = move(tmp);
}

int main()
{
	int a = 1,b = 3;
	Swap(a,b);
	cout<<"a,b:"<<a<<" "<<b<<endl;
	return 0;
}
