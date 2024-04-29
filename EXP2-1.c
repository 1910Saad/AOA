/*
 																EXP2

Aim : Implement and analyse selection sort.
Name : KhanSaad Alikhan
Roll no : 22CO24
Academic Year : 2023-2024
Batch : 2


Theory :- 

Selection Sort is a straightforward sorting algorithm that repeatedly 
selects the smallest (or largest) element from an unsorted list and 
swaps it with the first unsorted element. This process is iteratively 
applied to the remaining unsorted portion until the entire list is sorted.
*/
/*
Algorithm :-

    1.Start
    2.Initialise a variable named min, which will store 0 at the beginning.
    3.Now, run a loop to find the minimum element in the array.
    4.If you find any smaller elements than min, then swap both values.
    5.Now, increment min++ to point to the next element in the array.
    6.Keep repeating until you reach the size of the array or list.
    7.End

*/
#include <stdio.h>
#include <stdlib.h>

//Function to display the array
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//Function to sort the array
void SelectionSort(int array[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(array[j]<array[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			int p = array[i];
			array[i] = array[min];
			array[min] = p;
		}
	}
}

//Driver Function
int main()
{
	int n,i;
	//int arr[]={9,5,1,4,3}
	int array[100];
	printf("Enter the no of elements\n");
	scanf("%d",&n);
	printf("Enter %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Elements Berfore Sorting : \n");
    display(array,n);
    SelectionSort(array,n);
    printf("Elements after sorting : \n");
    display(array,n);
}

/*
Output :-
Enter the no of elements
5
Enter 5 elements
21 88 2 56 1
Elements Berfore Sorting : 
21 88 2 56 1
Elements after sorting :
1 2 21 56 88
*/
/*
Best-case:
    O(n2) 
    best case occurs when the array is already sorted.
    (where n is the number of integers in an array)
Average-case: 
    O(n2) 
    the average case arises when the elements of the 
    array are in a disordered or random order, without
    a clear ascending or descending pattern.
Worst-case: 
    O(n2)
    The worst-case scenario arises when we need to 
    sort an array in ascending order, but the array is 
    initially in descending order.



Conclusion :-
Thus, Selection Sort is a straightforward and intuitive 
sorting algorithm that operates by repeatedly selecting 
the smallest (or largest, depending on the order of sorting) 
element from an unsorted portion and swapping it with 
the first unsorted element.
*/


