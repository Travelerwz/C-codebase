/*
*@param 选择排序
*@param  时间复杂度O(n^2)

*/
#include<stdio.h>

void SelectionSort(char str[],int n)
{
	int tmp,i,j,min=0,flag=0;
	for(i=0;i<n;i++)
	{
		min = i;
		//选择最小的
		for(j=i;j<n;j++)
		{
			if(str[j] > str[min])
			{
				min = j;
				flag = 1;
			}
		}
		if(flag == 1)
		{
			tmp = str[i];
			str[i] = str[min];
			str[min] = tmp;
		}
		
	}
}

int main()
{
	int i;
	char str[] = {1,9,6,5,3,8,4,0,6};
	int len = sizeof(str);
	SelectionSort(str,len);
	for(i=0;i<len;i++)
	{
		printf("%d ",str[i]);
	}
	printf("\n");
	return 0;
}
