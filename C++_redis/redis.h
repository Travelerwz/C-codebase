#ifndef _REDIS_H_
#define _REDIS_H_

#include<stdio.h>
#include<iostream>
#include<string>
#include<hiredis/hiredis.h>
using namespace std;
class Redis
{
public:
	Redis(){}
	~Redis()
	{
		this->_connect = NULL;
		this->_reply = NULL;
	}
	bool Connect(string host,int port)
	{
		this->_connect = redisConnect(host.c_str(),port);
		if(this->_connect != NULL && this->_connect->err)
		{
			cout<<"connect is error:"<<this->_connect->errstr<<endl;
			return false;
		}
		return true;
	}
	void set(string key,string value)
	{
		redisCommand(this->_connect,"SET %s %s",key.c_str(),value.c_str());
	}
	
	string get(string key)
	{
		this->_reply = (redisReply*)redisCommand(this->_connect,"GET %s",key.c_str());
		string str = this->_reply->str;
		freeReplyObject(this->_reply);
		return str;
	}
private:
	redisContext* _connect;
	redisReply*	_reply;
};

#endif
