#include<iostream>
#include<stack>
using namespace std;

class Stack_Sort
{
public:
	void Sort(stack<int>&st)
	{
		while (!st.empty())
		{
			int cur = st.top();
			st.pop();
			while (!s.empty() && s.top() > cur)
			{
				st.push(s.top());
				s.pop();
			}
			s.push(cur);

		}
		while (!s.empty())
		{
			int cur = s.top();
			st.push(cur);
			s.pop();
		}
	}
private:
	stack<int>s;
};

void Print(stack<int>s)
{
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
}
int main()
{
	stack<int>s;
	s.push(1);
	s.push(3);
	s.push(2);
	Print(s);
	cout << "__________________" << endl;
	Stack_Sort so;
	so.Sort(s);
	Print(s);
	return 0;
}
