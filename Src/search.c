#include "search.h"
#include "sorting.h"

/***************************************************************
 * 					Linear Search Complexity
 ***************************************************************
 * 
 * T = 2*C + 5*C*n
 * O(n) = n
 *
 ***************************************************************/

int SEARCHING_linear (int* array, int size, int requiredNum)
{
	int counter;
	int retValue;
	for(counter=0 ; counter<size ; counter++)
	{
		if(array[counter] == requiredNum)
		{
			retValue = counter;
			counter = size+1;
		}
	}

	return retValue;
}


/***************************************************************
 * 					 Binary Search Complexity
 ***************************************************************
 * 
 * T = 5*C + 5*C*log(n)
 * O(n) = log(n)
 *
 ***************************************************************/

int SEARCHING_binary (int* array, int size, int requiredNum)
{

	int retValue=-1;
	int left = 0;
	int right = size-1;
	int middle = (left+right+1)/2;

	if(checkIfSorted(array,size) == NOT_SORTED)
	{
	}
	else
	{
		while(right>=left)
		{
			if(array[middle] == requiredNum)
			{
				retValue = middle;
				left = size+1;
			}
			else if(requiredNum > array[middle])
			{
				left = middle+1;
				middle = (left+right+1)/2;
			}
			else if(requiredNum < array[middle])
			{
				right = middle-1;
				middle = (left+right+1)/2;
			}
		}
	}

	return retValue;

}
