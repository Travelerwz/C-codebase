#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main()
{
	vector<int>res;
	set<int>s;
	res.push_back(1);
	res.push_back(1);
	res.push_back(2);
	for(int i=0;i<res.size();i++)
	{
		s.insert(res[i]);
	}

	set<int>::iterator it = s.begin();
	for(;it!=s.end();it++)
	{
		cout<<*it<<endl;
	}
	return 0;
}
