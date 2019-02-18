#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* Strcpy(char* dst,const char* str)
{
	assert(dst !=NULL && str !=NULL);
	
	char* ret = dst;
	while((*dst++ = *str++) != '\0');
	return ret;
}

int main()
{
	char *str = "hello";
	char* dst = (char*)malloc(sizeof(str)+1);
	Strcpy(dst,str);
	printf("%s\n",dst);
	free(dst);
	dst = NULL;
	return 0;
}
