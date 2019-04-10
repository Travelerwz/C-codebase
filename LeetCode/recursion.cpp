/*
 *递归函数与栈操作逆序一个栈
 */

#include<iostream>
#include<stack>
using namespace std;
void Show(stack<int>s);

class Recur_stack
{
public:
	static int getAndRemove(stack<int>&s)
	{
		int result = s.top();
		s.pop();
		if (s.empty())
		{
			return result;
		}
		else
		{
			int last = getAndRemove(s);
			s.push(result);
			return last;
		}
	}

	static void reverStack(stack<int>&s)
	{
		if (s.empty())
		{
			return;
		}
		int i = getAndRemove(s);
		reverStack(s);
		s.push(i);
	}
};

void Show(stack<int>s)
{
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main()
{
	stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << "befor rever:" << endl;
	Show(s);

	cout << "after rever:" << endl;
	Recur_stack::reverStack(s);
	Show(s);
	return 0;
}
