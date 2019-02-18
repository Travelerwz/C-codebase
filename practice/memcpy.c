#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* Memcpy(char* dst,const char* str,int n)
{
	assert(dst!=NULL && str !=NULL);
	
	char* ret = dst;
	//三种情况
	//1.正常,没有发生重叠
	//2.dst地址大于str
	//3.dst地址小于str
	//1和3是一样的，2是特殊，发生重叠的
	
	if(dst > str && dst < str+n-1)
	{
		dst = dst+n-1;
		str = str+n-1;
		
		while(n--);
		{
			*dst-- = *str--;
		}
	}
	else
	{
		while(n--)
		{
			*dst++ = *str++;
		}
	}
	return ret;
}

int main()
{
	char* str = "hello";
	char* dst = (char*)malloc(sizeof(str)+1);
	Memcpy(dst,str,3);
	printf("%s\n",dst);
	return 0;
}
