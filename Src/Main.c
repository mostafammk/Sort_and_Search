#include "search.h"
#include <stdio.h>

#include "sorting.h"


int main(void)
{
	int arr[] = {5,4,7,8,3,1,8,0,1};
	int arr3[] = {5,4,7,8,3,1,8,0,1};
	int arr4[] = {5,4,7,8,3,1,8,0,1};
	int arr2[] = {2,4,5,6,7,9,10,40};
	printf("%d\n",SEARCHING_linear(arr,9,0));
	printf("%d\n",SEARCHING_binary(arr,9,8));
	printf("%d\n",SEARCHING_binary(arr2,8,10));

	SORTING_selection(arr,9);

	for(int i=0 ; i<9 ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	SORTING_bubble(arr3,9);
	for(int i=0 ; i<9 ; i++)
	{
		printf("%d ",arr3[i]);
	}

	SORTING_merge(arr4,9);
	printf("\n");
	for(int i=0 ; i<9 ; i++)
	{
		printf("%d ",arr3[i]);
	}
}
