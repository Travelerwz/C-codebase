/*
*@param  插入排序
*@param  时间复杂度O(n^2)
*/

#include<stdio.h>

void InsertSort(char str[],int len)
{
	int i,j,tmp,curent;
	for(i=1;i<len;i++)
	{
		tmp = i-1;
		curent = str[i];
		//从已排好序中，从后向前比较
		while(tmp>=0 && str[tmp]>curent)
		{
			str[tmp+1] = str[tmp];
			tmp--;
		}
		str[tmp+1] = curent;
	}
}

int main()
{
	int i,len;
	char str[] = {1,9,6,5,8,7,2,4};
	len = sizeof(str);
	InsertSort(str,len);
	for(i=0;i<len;i++)
	{
		printf("%d ",str[i]);
	}
	printf("\n");
	return 0;
}
