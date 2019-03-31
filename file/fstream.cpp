#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char data[100];
    //写模式打开文件
    ofstream outfile;
    outfile.open("111.xml",ios::app);
    cout<<"open file,input data:"<<endl;
    cin.getline(data,100);
    outfile<<data<<endl;
    outfile.close();

    //只读方式打开文件
    ifstream infile;
    infile.open("111.xml");
    cout<<"read data:"<<endl;
    infile>>data;
    cout<<data<<endl;

    return 0;
}
