/*
	*@单例模式，饿汉模式
	*@在初始化的时候就实例化，
	*@所以不存在线程不安全的情况
	以空间换时间
*/
#include<iostream>
#include<pthread.h>
using namespace std;


class Singleton1
{
private:
	Singleton1(){}
	
public:
	static Singleton1* p;
	static Singleton1* getinstance();
};

Singleton1* Singleton1::p = new Singleton1();
Singleton1* Singleton1::getinstance()
{
	return p;
}


//懒汉模式，以时间换空间
class Singleton
{
public:
	static Singleton* getinstance();
private:
	Singleton()
	{
		pthread_mutex_init(&mutex,NULL);
	}
	static pthread_mutex_t mutex;
	static Singleton* p;
	
};
pthread_mutex_t Singleton::mutex;
Singleton* Singleton::p = NULL;
Singleton* Singleton::getinstance()
{
	//注意这里要判断两次
	//因为两个可能同时进入p==null
	
	if(p==NULL)
	{
		pthread_mutex_lock(&mutex);
		if(p == NULL)
		{
			p = new Singleton();
			
		}
		pthread_mutex_unlock(&mutex);
	}
	return p;
}
int main()
{	
	Singleton* s1 = Singleton::getinstance();
	Singleton* s2 = Singleton::getinstance();
	if(s1 == s2)
	{
		cout<<"ok"<<endl;
	}
	else
	{
		cout<<"error"<<endl;
	}
	return 0;
}
