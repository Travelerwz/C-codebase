/** 
 *  @author    wangzhuang
 *  @date   
 *  @note      C++����ָ��ʵ��
 *  @note      V1.0
 */


#include<iostream>
using namespace std;

 //ģ������Ϊ��ԪʱҪ��������
template<class T> class Smart_ptr;

// ���ü�������  ���ڴ洢ָ��ͬһ�����ָ����
template<class T>
class Count
{
private:

	friend class Smart_ptr<T>;//��Ԫ
	int count;//������
	T* ptr;//����ָ��
	
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

//  ����ָ����  
template<class T>
class Smart_ptr
{
public:
//  ��Ա����
	//  ��ͨ���캯��  ��ʼ��������
	Smart_ptr(T* p)
	{
		ptr_num = new Count<T>(p);
	}
	
	//  �������캯��
	Smart_ptr(const Smart_ptr& rhs)
	{
		ptr_num = rhs.ptr_num;
		ptr_num->count++;
	}
	
	//  ��ֵ��������غ���
	Smart_ptr& operator=(Smart_ptr& rhs)
	{
		ptr_num = rhs->ptr_num;
		rhs->ptr_num->count++;
		ptr_num->count--;
		if(0 == ptr_num->count)
			delete ptr_num;
		return *this;
	}
	//  ��������������غ���
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
	Count<T>* ptr_num;//  ���ݳ�Ա
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