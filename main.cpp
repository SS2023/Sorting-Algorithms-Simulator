#include "Sorting.h"
#include <fstream>
#include <iostream>
#include <ostream>
using namespace std;

// Coded By: Sunny Shah
int main(int argc, char *argv[])
{
	// command line argument is less than 2
	if (argc < 2)
	{
		cout << "Invalid number of command line arguments. Less than 2 command line arguments are provided. Example: ./main (textfile.txt)" << endl;
		exit(1);
	}

	// command line argument is greater than 2
	if (argc > 2)
	{
		cout << "Invalid number of command line arguments. More than 2 command line arguments are provided. Example: ./main (textfile.txt)" << endl;
		exit(1);
	}

	ifstream inputFile(argv[1], ios::in);

	// file cannot be opened
	if (inputFile.fail())
	{
		cout << "The file does not exist. Check file name." << endl;
		exit(1);
	}

	cout << "To generate a random array of your size - Press y\nOR\nTo use your text file in the command line argument - Press x" << endl;

	cout << "Your path: ";
	char path;
	cin >> path;

	if(path == 'x')
	{

		cout << "selection-sort (s)     merge-sort (m)     heap-sort (h)     quick-sort-fp (q)     quick-sort-rp (r)" << endl;

		int size = 10000;
		int values[size];

		// parsing numbers from input file into array
		int value = 0;
		int counter = 0;
		while (inputFile >> value)
		{
			values[counter] = value;
			counter++;
		}

		// user command sequence
		char command;
		cout << "Enter the algorithm: ";
		cin >> command;

		// selection sort
		if (command == 's')
		{
			int selectionSortCounter = SelectionSort(values, size);
			PrintValues(values, size);
        		cout << "\n#Selection-sort comparisons: ";
        		cout << selectionSortCounter << endl;
		}

		// merge sort
		else if (command == 'm')
		{
			long mergeSortCounter = MergeSort(values, 0, size - 1);
			PrintValues(values, size);
			cout << "\n#Merge-sort comparisons: ";
			cout << mergeSortCounter << endl;
		}

		// heap sort
		else if (command == 'h')
		{
			long heapSortCounter = HeapSort(values, size);
			PrintValues(values, size);
        		cout << "\n##Heap-sort comparisons: ";
        		cout << heapSortCounter << endl;
		}

		// quick sort first pivot
		else if (command == 'q')
		{
			int firstPivotCounter = QuickSortFirstPivot(values, 0, size - 1);
			PrintValues(values, size);
			cout << "\n##Quick-sort-fp comparisons: ";
			cout << firstPivotCounter << endl;
		}

		// quick sort random pivot
		else if (command == 'r')
		{
			int randomPivotCounter = QuickSortRandomPivot(values, 0, size - 1);
			PrintValues(values, size);
			cout << "\n#Quick-sort-rp comparisons: ";
			cout << randomPivotCounter << endl;
		}
	}

	else if(path == 'y')
	{
		int size = 0;
		cout << "Enter size of input: ";
		cin >> size;
		
		cout << "selection-sort (s)     merge-sort (m)     heap-sort (h)     quick-sort-fp (q)     quick-sort-rp (r)" << endl;

		int values[size];

		char command;
		cout << "Enter the algorithm: ";
		cin >> command;

		// create random array
		for (int i = 0; i < size; i++)
		{
			// generate a number between 1 and size and add to array
			values[i] = (rand() % (size - 1)) + 1;
		}

		// selection sort
		if (command == 's')
		{
			int selectionSortCounter = SelectionSort(values, size);
			PrintValues(values, size);
        		cout << "\n#Selection-sort comparisons: ";
        		cout << selectionSortCounter << endl;
		}

		// merge sort
		else if (command == 'm')
		{
			long mergeSortCounter = MergeSort(values, 0, size - 1);
			PrintValues(values, size);
			cout << "\n#Merge-sort comparisons: ";
			cout << mergeSortCounter << endl;
		}

		// heap sort
		else if (command == 'h')
		{
			long heapSortCounter = HeapSort(values, size);
			PrintValues(values, size);
        		cout << "\n##Heap-sort comparisons: ";
        		cout << heapSortCounter << endl;
		}

		// quick sort first pivot
		else if (command == 'q')
		{
			int firstPivotCounter = QuickSortFirstPivot(values, 0, size - 1);
			PrintValues(values, size);
			cout << "\n##Quick-sort-fp comparisons: ";
			cout << firstPivotCounter << endl;
		}

		// quick sort random pivot
		else if (command == 'r')
		{
			int randomPivotCounter = QuickSortRandomPivot(values, 0, size - 1);
			PrintValues(values, size);
			cout << "\n#Quick-sort-rp comparisons: ";
			cout << randomPivotCounter << endl;
		}
	}

	else
	{
		cout << "Invalid path. Program ending." << endl;	
	}
}
