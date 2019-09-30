#include "sorting.h"

static void SORTING_mergeBack(int* leftArray, int leftSize, int* rightArray, int rightSize, int* Array, int size);



int checkIfSorted(int* arr,int size)
{
	int retValue = SORTED;
	int counter;
	for(counter=0 ; counter<size-1 ; counter++)
	{
		if(arr[counter] > arr[counter+1])
		{
			retValue = NOT_SORTED;
			counter = size+1;
		}
	}
	return retValue;
}

void swapTwoIntegers(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/***************************************************************
 * 					 Selection Sort Complexity
 ***************************************************************
 * 
 * T = C + n*(2c+5*n+C)
 * O(n) = n^2
 *
 ***************************************************************/

void SORTING_selection(int* array, int size)
{
	int counterI;
	int counterJ;
	int minIndx;
	int flag = 0;

	for(counterI=0 ; counterI < size ; counterI++)
	{
		minIndx = counterI;

		for(counterJ= counterI+1 ; counterJ < size; counterJ++)
		{
			if(array[counterJ]<array[minIndx])
			{
				minIndx = counterJ;
				flag = 1;
			}
		}
		if(flag)
		{
			swapTwoIntegers(&array[counterI],&array[minIndx]);
			flag=0;
		}
		else
		{
			counterI=size+1;
		}

	}

}

/***************************************************************
 * 					 Bubble Sort Complexity
 ***************************************************************
 * 
 * T = C + n*(c+6*n)
 * O(n) = n^2
 *
 ***************************************************************/

void SORTING_bubble(int* array, int size)
{
	int counterI;
	int counterJ;

	for(counterI=0 ; counterI< size-1; counterI++)
	{
		for(counterJ = 0 ; counterJ < size-counterI-1 ; counterJ++)
		{
			if(array[counterJ] > array[counterJ+1])
			{
				swapTwoIntegers(&array[counterJ],&array[counterJ+1]);
			}
		}
	}

}

void SORTING_mergeBack(int* leftArray, int leftSize, int* rightArray, int rightSize, int* Array, int size)
{
	int leftCounter=0, rightCounter=0, ArrayCounter=0;

	while ((leftCounter<leftSize)&&(rightCounter<rightSize))
	{
		if(leftArray[leftCounter] <= rightArray[rightCounter])
		{
			Array[ArrayCounter] = leftArray[leftCounter];
			leftCounter++;
		}
		else
		{
			Array[ArrayCounter] = rightArray[leftCounter];
			rightCounter++;
		}
		ArrayCounter++;
	}
	while(leftCounter<leftSize)
	{
		Array[ArrayCounter] = leftArray[leftCounter];
		leftCounter++;
		ArrayCounter++;
	}
	while(rightCounter<rightSize)
	{
		Array[ArrayCounter] = rightArray[leftCounter];
		rightCounter++;
		ArrayCounter++;
	}
}

/***************************************************************
 * 					 Merge Sort Complexity
 ***************************************************************
 * 
 * O(n) = n*log(n)
 *
 ***************************************************************/


void SORTING_merge(int* array, int size)
{
	int middle = size/2;
	int left_Indx=0;
	int left_size=middle;
	int right_Indx=middle;
	int right_size=size-middle;

	int leftArray[left_size];
	int rightArray[right_size];

	if(size<2)
	{
	}
	else
	{

		SORTING_merge(leftArray,left_size);
		SORTING_merge(rightArray,right_size);
		SORTING_mergeBack(leftArray,left_size,rightArray,right_size,array,size);
	}
}
