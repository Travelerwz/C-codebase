/** 
 *  @author    wangzhuang
 *  @date   
 *  @note      C++智能指针实现
 *  @note      V1.0
 */


#include<iostream>
using namespace std;

 //模板类作为友元时要先有声明
template<class T> class Smart_ptr;

// 引用计数器类  用于存储指向同一对象的指针数
template<class T>
class Count
{
private:

	friend class Smart_ptr<T>;//友元
	int count;//计数器
	T* ptr;//对象指针
	
	Count(T* p)
	{
		ptr = p;
		count = 1;
	}
	
	~Count()
	{
		delete ptr;
	}
	
};

//  智能指针类  
template<class T>
class Smart_ptr
{
public:
//  成员函数
	//  普通构造函数  初始化计数类
	Smart_ptr(T* p)
	{
		ptr_num = new Count<T>(p);
	}
	
	//  拷贝构造函数
	Smart_ptr(const Smart_ptr& rhs)
	{
		ptr_num = rhs.ptr_num;
		ptr_num->count++;
	}
	
	//  赋值运算符重载函数
	Smart_ptr& operator=(Smart_ptr& rhs)
	{
		ptr_num = rhs->ptr_num;
		rhs->ptr_num->count++;
		ptr_num->count--;
		if(0 == ptr_num->count)
			delete ptr_num;
		return *this;
	}
	//  解引用运算符重载函数
	T& operator *()
	{
		return *(ptr_num->count);
	}
	~Smart_ptr()
	{
		ptr_num->count--;
		if(0 == ptr_num->count)
			delete ptr_num;
		else
			cout<<"ptr_num not zero :"<<ptr_num->count<<endl;
	}
private:
	Count<T>* ptr_num;//  数据成员
};
int main()
{
	int *p = new int(20);
	{
		Smart_ptr<int>res(p);
		{
			Smart_ptr<int>ptr(res);
			{
				Smart_ptr<int>ppp(ptr);
			}
		}
	}
	cout<<"*p:"<<*p<<endl;
	return 0;
}