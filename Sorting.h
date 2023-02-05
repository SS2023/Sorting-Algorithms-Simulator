#ifndef SORTING_H
#define SORTING_H

void Swap(int* a, int* b);
int SplitRandomPivot(int values [ ], int first, int last);
int RandomPivot(int values [ ], int first, int last);
int SplitFirstPivot(int values [ ], int first, int last);
void PrintValues(int values [ ], int size);
int MinIndex(int values [ ], int start, int end);
int SelectionSort(int values [ ], int numValues);
long MergeSort(int values [ ], int first, int last);
long Merge(int values [ ], int leftFirst, int leftLast, int rightFirst, int rightLast);
int QuickSortFirstPivot(int values [ ], int first, int last);
int QuickSortRandomPivot(int values [ ], int first, int last);
long HeapSort(int values [ ], int numValues);
void ReheapDown(int values [ ], int root, int bottom);

#endif
