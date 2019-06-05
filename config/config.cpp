#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/*函数名称 getConfig（）
函数功能：获取配置文件中的标题下指定的字段
参数1：string title 大标题[***]
参数2：string cfgname 大标题下指定配置字段
返回值：配置文件ini中相应的大标题下的配置字段cfgname的值
*/
string getConfig(string title,string cfgName)
{
	const char* File = "config.ini";
	ifstream inifile(File);
	if (!inifile.is_open())
	{
		cerr << "could not open" <<File<< endl;
		inifile.clear();
		exit(-1);
	}
	string strtmp, strtitle, strcfgname, returnValue;
	int flag = 0;
	while (getline(inifile, strtmp, '\n'))
	{
		cout << "strtmp:"<< strtmp <<endl;
		if (strtmp.substr(0, 1) == "#")
			continue;
		if (0 == flag)
		{
			if (strtmp.find(title) != string::npos)
			{
				cout << "find title:"<< title<< endl;
				if (strtmp.substr(0, 1) == "[")
				{
					if (strtmp.find("]") == string::npos)//缺失“]”，退出
					{
						break;
					}
					strtitle = strtmp.substr(1);
					strtitle = strtitle.erase(strtitle.find("]"));
					if (strtitle == title)
					{
						//找到大标题设置标志位1
						flag = 1;
						continue;
					}
				}
			}
		}
		if (1 == flag)
		{
			if (strtmp.substr(0, 1) == "[")//说明当前大标题对应的配置字段搜索完毕，结束搜索
				break;
			if (strtmp.find(cfgName) != string::npos)
			{
				if (strtmp.find("=") == string::npos)
				{
					//缺失“=”
					break;
				}
				strcfgname = strtmp;
				strcfgname = strcfgname.erase(strcfgname.find("="));
				{
					if (strcfgname == cfgName)
					{
						returnValue = strtmp.substr(strtmp.find("=")+1);
						return returnValue;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	cout << "配置文件错误：没找到"<<title<<"对应配置项"<<cfgName<< endl;
	exit(-1);
}
int main()
{
	string FrontAddr = getConfig("config","FrontAddr");
	cout << "FrontAddr:" << FrontAddr << endl;
	system("pause");
	return 0;
}
