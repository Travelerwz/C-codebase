#include "redis.h"

int main()
{
	string str = "";
	Redis *r = new Redis();
	if(!r->Connect("127.0.0.1",6379))
	{
		cout<<"connect error"<<endl;
		return 0;
	}
	r->set("www","123");
	str = r->get("www");
	cout<<"get www is :"<<str.c_str()<<endl;
	delete r;
	return 0;
}