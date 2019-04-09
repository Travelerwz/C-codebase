#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
	void push(int value)
	{
		if (minData.empty())
		{
			minData.push(value);
		}
		else
		{
			if (minData.top() > value)
			{
				minData.push(value);
			}
			else
			{
				minData.push(minData.top());
			}
			Data.push(value);
		}
	}

	void pop()
	{
		Data.pop();
		minData.pop();
	}

	int top()
	{
		return Data.top();
	}

	int Min()
	{
		return minData.top();
	}
private:
	stack<int>Data, minData;
};

int main()
{
	Solution s;
	int value = 5;
	for (int i = 0; i < value; i++)
	{
		s.push(i);
	}
	cout<<"top:"<<s.Min()<<endl;
	return 0;
}
