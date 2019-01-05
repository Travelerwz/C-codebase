/*
*@param  快速排序
*@param  时间复杂度O(nlog2n)
*/
#include<stdio.h>

void quickSort(char str[],int start,int end)
{
	if(start < end)
	{
		int i=start,j=end,tmp=str[start];
		while(i<j)
		{
			//从右向左选择出比tmp小的
			while(i<j && tmp<=str[j])
			{
				j--;
			}
			if(tmp > str[j])
			{
				str[i] = str[j];
				i++;
			}
			
			//从左向右选出比tmp大的
			while(i<j && tmp>=str[i])
			{
				i++;
			}
			if(tmp < str[i])
			{
				str[j] = str[i];
				j--;
			}
		}
		str[i] = tmp;
		quickSort(str,0,start-1);
		quickSort(str,start+1,end);
	}

}

int main()
{
	int i,len;
	char str[] = {1,6,9,5};
	len = sizeof(str);
	quickSort(str,0,len-1);
	for(i=0;i<len;i++)
	{
		printf("%d ",str[i]);
	}
	printf("\n");
	return 0;
}
