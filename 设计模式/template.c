#include<iostream>
using namespace std; 

class TemplateMethod  
{   
public:      

void Template()       
{           

	cout<<"I am templatemethod"<<endl;     
	
}     
virtual void Print() = 0;//声明虚函数  
}; 
class PrimitiveOperation1:public TemplateMethod  //继承父类  
{ 
public:      

	void Print()      
	{          
		cout<<"I am PrimitiveOperation1"<<endl;     
	}  
}; 

class PrimitiveOperation2:public TemplateMethod  //继承父类 
{  
public:      
	void Print()  //重新编写虚函数      
	{          
		cout<<"I am PrimitiveOperation2"<<endl; 
	} 
}; 
int main()  
{      
	TemplateMethod* method1 = new PrimitiveOperation1();   //实例化      
	method1->Print();      
	TemplateMethod* method2 = new PrimitiveOperation2();  //实例化      
	method2->Print();      
	return 0;  
}
