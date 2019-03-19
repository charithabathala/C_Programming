#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

void target_sum (int arr[],int arr_size, int sum)
{
	int i,temp=0;
	int S[MAX] = {0}; //intialising hash set to zero 

	for(i=0;i<arr_size;i++)
	{
		temp = sum - arr[i];
		if(temp>=0 && S[temp]==1)
			printf("The pairs %d and %d give the targeted sum %d",arr[i],temp,sum);
		S[arr[i]]=1;
	}

}

int main()
{
	int arr[] = {1,4,45,6,10,-8};
	int sum = 5;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	target_sum(arr,arr_size,sum);
	return 0;

}