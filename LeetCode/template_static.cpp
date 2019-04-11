/*
	*类模板静态函数使用/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<typename T>
class Foo
{
public:
	static size_t count()
	{
		return ctr;
	}
	void addctr()
	{
		ctr++;
	}
	void subctr()
	{
		ctr--;
	}
private:
	static size_t ctr;
};

template<typename T>
size_t Foo<T>::ctr = 0;

int main()
{
	Foo<int> fi;
	cout << "fi.count" <<fi.count()<< endl;
	fi.addctr();
	Foo<int> fi2;
	fi2.addctr();
	cout << "fi2.count" << fi2.count() << endl;
	cout << "Foo<int>::count"<<Foo<int>::count()<<endl;
	return 0;
}
