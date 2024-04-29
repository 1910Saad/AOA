/*
                                                    EXP4

Aim : Implement and analyse binary search algorithm using D&C technique.
Name : Khan Saad Alikhan
Roll no : 22CO24
Academic Year : 2023-2024
Batch : 2


Theory :- 
    Binary search is a classic search algorithm that works on a sorted array.
    It repeatedly divides the search space in half until the target element 
    is found or the subarray is empty. The mid-point comparison helps eliminate 
    half of the remaining elements at each step, making it an efficient algorithm.

Algorithm for Binary Search:-
    1. binary_search(arr, x, low, high)
    2. if low > high
    3.     return -1
    4. else
    5.     mid = (low + high) / 2
    6.     if x == arr[mid]
    7.         return mid
    8.     else if x > arr[mid]
    9.         return binary_search(arr, x, mid + 1, high)
    10.    else
    11.        return binary_search(arr, x, low, mid - 1)
    12. End binary_search
*/
#include<stdio.h>

//Function to search element
int binary_search(int arr[], int x, int low, int high) {
    //If element not found
    if (low > high) {
        return -1;
    } else {
        //Calculating the mid of array
        int mid = (low + high) / 2;
        //If the element is on mid
        if (x == arr[mid]) {
            return mid; 
        //If element is greater then mid
        } else if (x > arr[mid]) {
            //we set low to mid+1
            return binary_search(arr, x, mid + 1, high);
        //If element is smaller than mid
        } else {
            //we set high to mid-1
            return binary_search(arr, x, low, mid - 1);
        }
    }
}

//Function to display the array
void display(int arr[], int n){
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//Driver Function
int main() {
    int n, x;
    printf("Enter Array Size: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
	printf("Original Array: ");
	display(arr, n);
    printf("Enter the element to search: \n");
    scanf("%d", &x);

    int result = binary_search(arr, x, 0, n - 1);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}
/*
Output:- 
    Enter Array Size:
    5
    Enter Array elements:
    12 34 45 67 89
    Original Array: 12 34 45 67 89
    Enter the element to search:
    12
    Element found at index 0.

Time complexity:-
    Best Case:- 
		O(1)
        The best-case time complexity for Binary Search occurs when the 
        target element is found at the middle of the array in the first comparison.

    Average Case:-
        O(log n)
        On average, Binary Search exhibits a time complexity of O(log n). 
        This is because at each step, the search space is halved, leading to a logarithmic 
        behavior.

    Worst Case:- 
		O(log n)
        The worst-case time complexity arises when the target element is either 
        not present in the array or located at the last comparison. In such cases, 
        Binary Search still has a time complexity of O(log n), making it more efficient 
        than linear search for large datasets.

Conclusion:-
    Binary search is a highly efficient algorithm for searching in a sorted 
    array. It provides a fast solution by halving the search space at each 
    step. This implementation allows users to input the array and the target 
    element, displaying the original array and informing whether the element 
    is found and at which index.
*/