#include <stdio.h>
//C 语言没有类，但可以用结构体充当一个类
//与类不同，结构体只能定义变量，不能够定义函数，可以通过函数指针的方法来实现其功能 
//定义“类 ”的成员变量以及方法 
typedef struct Person{
	char name;
	int age;
	void (*Print)(struct Person this);
}Person; 
 
//定义函数功能 
void Print(struct Person this)
{
	printf("name:%c\n",this.name);
	printf("age:%d\n",this.age);
} 
 
//定义“类 ”的构造函数
//与面向对象不同，C语言的“类”的 构造函数不能放在“类”中，只能放在“类”外
//构造函数主要完成 变量的初始化，以及函数指针的赋值 
NewPerson(Person *this){
	this->name = 'A';
	this->age = 18;
	this->Print = Print;
} 
 
//主函数调用 
int main(){
	Person person;
	NewPerson(&person);
	person.Print(person);
	return 0;
} 
