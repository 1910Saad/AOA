/*
                                                    EXP5

Aim : Implement and analyse Quick sort algorithm using D&C technique.
Name : Khan Saad Alikhan
Roll no : 22CO24
Academic Year : 2023-2024
Batch : 2


Theory:- 
    Quick Sort is a widely used sorting algorithm that follows 
    the divide and conquer paradigm. It works by selecting a 
    pivot element from the array and partitioning the other elements
    into two sub-arrays according to whether they are less than or 
    greater than the pivot. The process is recursively applied to 
    the sub-arrays, resulting in a sorted array. Quick Sort is known 
    for its efficiency and is often used in practice.

Algorithm for Quick Sort:-
    1. quickSort(arr, low, high)
    2. if low < high
    3.    partitionIndex = partition(arr, low, high)
    4.    quickSort(arr, low, partitionIndex - 1)
    5.    quickSort(arr, partitionIndex + 1, high)
    6. End quickSort
    7. partition(arr, low, high)
    8.    pivot = arr[low]
    9.    i = low
    10.   j = high
    11.   while i < j
    12.       while arr[i] <= pivot and i <= high - 1
    13.           i++
    14.       while arr[j] > pivot and j >= low + 1
    15.           j--
    16.       if i < j
    17.           swap arr[i] and arr[j]
    18.   swap arr[low] and arr[j]
    19.   return j
    20. End partition
*/
#include <stdio.h> 

// Partition function 
int partition(int arr[], int low, int high) 
{ 
	int pivot = arr[low]; 
	int i = low; 
	int j = high; 

	while (i < j) { 
		while (arr[i] <= pivot && i <= high - 1) { 
			i++; 
		} 
		while (arr[j] > pivot && j >= low + 1) { 
			j--; 
		} 
		if (i < j) { 
			int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
		} 
	} 
	int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
	return j; 
} 

//Function to perform Quicksort
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) { 
		int j = partition(arr, low, high);  
		quickSort(arr, low, j - 1); 
		quickSort(arr, j + 1, high); 
	} 
} 

//Function to Display Array
void display(int arr[], int n){
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//Driver Function
int main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of Array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Original array: \n");
    display(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
/*
Output:-
    Enter the size of the array:
    5
    Enter elements of Array:
    12 6 2 8 1
    Original array:
    12 6 2 8 1
    Sorted array:
    1 2 6 8 12

Time complexity:-
    Best Case:-
        O(n log n)
        The best-case time complexity for Quick Sort occurs when the pivot 
        elements consistently divide the array into balanced partitions, 
        leading to logarithmic behavior.

    Average Case:-
        O(n log n)
        On average, Quick Sort exhibits a time complexity of O(n log n). 
        The partitioning process efficiently reduces the search space, 
        contributing to the algorithm's overall performance.

    Worst Case:- 
        O(n^2)
        The worst-case time complexity arises when the pivot selection consistently 
        leads to unbalanced partitions. In such cases, the algorithm degrades to 
        quadratic time complexity, though this is uncommon in practice.


Conclusion:-
    Quick Sort is a highly efficient sorting algorithm that provides 
    good performance across various scenarios. It exhibits an average-case 
    time complexity of O(n log n), making it suitable for large datasets. 
    The algorithm's divide and conquer approach, coupled with the 
    efficient partitioning process, contributes to its effectiveness 
    in practice. Despite its dependence on the choice of the pivot element, 
    Quick Sort is widely used and is a fundamental sorting algorithm in 
    computer science.
*/