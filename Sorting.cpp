#include "Sorting.h"
#include <cstddef>
#include <iostream>
#include <array>

using namespace std;

// Coded By: Sunny Shah

// Resource: https://www.geeksforgeeks.org/quick-sort/
// Swap function
void Swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int randomPivotCounter = 0;	// counts the number of comparisons in quick sort rp

// takes last element as pivot
int SplitRandomPivot(int values[], int first, int last)
{
	int pivot = values[last];
	int i = (first - 1);

	for (int z = first; z < last; z++)
	{
		randomPivotCounter++;

		if (values[z] <= pivot)
		{
			i++;
			Swap(&values[i], &values[z]);
		}
	}

	Swap(&values[i + 1], &values[last]);
	return (i + 1);
}

// Resource: https://www.geeksforgeeks.org/quicksort-using-random-pivoting/
// random pivot is created and swapped with the last element
int RandomPivot(int values[], int first, int last)
{
	srand(time(NULL));
	int random = first + rand() % (last - first);
	Swap(&values[random], &values[last]);

	return SplitRandomPivot(values, first, last);
}

int firstPivotCounter = 0;

int SplitFirstPivot(int values[], int first, int last)
{
	int pivot = values[last];
	int i = (first - 1);

	for (int z = first; z < last; z++)
	{
		firstPivotCounter++;

		if (values[z] < pivot)
		{
			i++;
			Swap(&values[i], &values[z]);
		}
	}

	Swap(&values[i + 1], &values[last]);
	return (i + 1);
}

// Resource: https://www.geeksforgeeks.org/quick-sort/
// prints the array
void PrintValues(int values[], int size)
{
	int i;
	for (i = 1; i < size; i++)
	{
		cout << values[i] << " ";
	}
	cout << "" << endl;
}

long selectionSortCounter = 0;	//counts the number of comparisons in selection sort

// returns the index of the min element
int MinIndex(int values[], int start, int end)
{
	int indexOfMin = start;

	for (int index = start + 1; index <= end; index++)
	{
		if (values[index] < values[indexOfMin])
			indexOfMin = index;

		selectionSortCounter++;
	}
	return indexOfMin;
}

// selection sort
// returns the number of comparisons in MinIndex
int SelectionSort(int values[], int numValues)
{
	int endIndex = numValues - 1;

	for (int current = 0; current < endIndex; current++)
		Swap(&values[current], &values[MinIndex(values, current, endIndex)]);

	return selectionSortCounter;
}

long mergeSortCounter = 0;	//counts the number of comparisons in merge sort
int size = 10000;
int values[10000];

// merge sort
// returns the number of comparison in Merge
long MergeSort(int values[], int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		MergeSort(values, first, middle);
		MergeSort(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}

	return mergeSortCounter;
}

// returns the number of comparisons in merge sort
long Merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
	int tempArray[rightLast + 1];
	int index = leftFirst;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{
		if (values[leftFirst] < values[rightFirst])
		{
			tempArray[index] = values[leftFirst];
			leftFirst++;
		}

		else
		{
			tempArray[index] = values[rightFirst];
			rightFirst++;
		}

		index++;
		mergeSortCounter++;
	}

	while (leftFirst <= leftLast)
	{
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}

	while (rightFirst <= rightLast)
	{
		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}

	for (index = saveFirst; index <= rightLast; index++)
		values[index] = tempArray[index];

	return mergeSortCounter;
}

// returns the number of comparisons in quick sort fp
int QuickSortFirstPivot(int values[], int first, int last)
{
	if (first < last)
	{
		int splitPoint;
		splitPoint = SplitFirstPivot(values, first, last);
		QuickSortFirstPivot(values, first, splitPoint - 1);
		QuickSortFirstPivot(values, splitPoint + 1, last);
	}

	return firstPivotCounter;
}

// returns the number of comparisons in quick sort rp
int QuickSortRandomPivot(int values[], int first, int last)
{
	if (first < last)
	{
		int splitPoint;
		splitPoint = RandomPivot(values, first, last);
		QuickSortRandomPivot(values, first, splitPoint - 1);
		QuickSortRandomPivot(values, splitPoint + 1, last);
	}

	return randomPivotCounter;
}

long heapSortCounter = 0;	//counts the number of comparisons in heap sort

// returns the number of comparisons in heap sort
long HeapSort(int values[], int numValues)
{
	int index;

	for (index = numValues / 2 - 1; index >= 0; index--)
		ReheapDown(values, index, numValues - 1);

	for (index = numValues - 1; index >= 1; index--)
	{
		Swap(&values[0], &values[index]);
		ReheapDown(values, 0, index - 1);
	}

	return heapSortCounter;
}

// healper function for heap sort.
void ReheapDown(int values[], int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom)
	{
		heapSortCounter++;

		if (leftChild == bottom)
		{
			maxChild = leftChild;
		}

		else
		{
			if (values[leftChild] <= values[rightChild])
			{
				maxChild = rightChild;
			}

			else
				maxChild = leftChild;
		}

		if (values[root] < values[maxChild])
		{
			heapSortCounter++;
			Swap(&values[root], &values[maxChild]);
			ReheapDown(values, maxChild, bottom);
		}
	}
}
