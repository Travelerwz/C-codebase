/*
 *注意：1.栈1向栈2中压数据，必须一次性压完
		2.当栈2不为空的时候，不能压入数据
*/
#include<iostream>
#include<stack>
using namespace std;

class Queue_stack
{
public:
	void Push(int value)
	{
		stack1.push(value);

	}

	int Pop()
	{
		int a = 0;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				a = stack1.top();
				stack2.push(a);
				stack1.pop();
			}
		}
		a = stack2.top();
		stack2.pop();
		return a;
	}
private:
	stack<int>stack1, stack2;
};

int main()
{
	Queue_stack s;
	for (int i = 0; i < 5; i++)
	{
		s.Push(i);
	}
	cout << "top:"<<s.Pop() << endl;
	return 0;
}
