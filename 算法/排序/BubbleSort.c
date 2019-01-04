/*
*@param 冒泡排序
时间复杂度O(n^2)
*/

#include<stdio.h>

void BubbleSort(char str[],int len)
{
	int i,j,tmp;
	int flag = 1;
	for(i=0;i<len  && flag;i++)
	{
		flag = 0;
		//小心越界
		for(j=len-1;j>i;j++)
		{
			if(str[j]<str[j-1])
			{
				tmp = str[j];
				str[j] = str[j-1];
				str[j-1] = tmp;
				flag = 1;
			}
		}
	}
}

int main()
{
	int i,len;
	char str[] = {1,2,5,9,6,4,3};
	len = sizeof(str);
	BubbleSort(str,len);
	for(i=0;i<len;i++)
	{
		printf("%d ",str);
	}
	printf("\n");
	return 0;
}