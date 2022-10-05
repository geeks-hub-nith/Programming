// C++ program for implementation of
// selection sort
#include <bits/stdc++.h>
using namespace std;

// Swap function
void sp(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int array[], int n)
{
	int i, j, min_ind;

	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++)
	{

		// Find the minimum element in
		// unsorted array
		min_ind = i;
		for (j = i + 1; j < n; j++)
			if (array[j] < array[min_ind])
				min_ind = j;

		// Swap the found minimum element
		// with the first element
		if (min_ind != i)
			sp(&array[min_ind], &array[i]);
	}
}

// Function to print the array
void printArray(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

// Driver program
int main()
{
	int array[] = {39, 8, 16, 22, 15};
	int n = sizeof(array) / sizeof(array[0]);
	selectionSort(array, n);
	cout << "Sorted array: \n";
	printArray(array, n);
	return 0;
}
