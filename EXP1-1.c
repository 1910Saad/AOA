/* 				EXP1

Aim : Implement and analyse insertion sort.
Name : Khan Saad Alikhan
Roll no : 22CO24
Academic Year : 2023-2024
Batch : 2
*/

/*
Theory : 
Insertion sort is a simple sorting algorithm that works similar 
to the way you sort playing cards in your hands. The array is virtually 
split into a sorted and an unsorted part. Values from the unsorted part are 
picked and placed at the correct position in the sorted part.
*/
/*
Algorithm :- 

    1.Declare an array of size, n.
    2.Provide the n inputs such that the array (named arr) is unsorted.
    3.Run a loop, with i from 0 to n-1
    4.Assign arr[i] as key and i-1 as j
    5.While j >= 0 and arr[j+1] > arr[j] is True
        i.arr[j+1] = arr[j]
        ii.Increment j = j + 1
    6.Assign key at a[j+1]

*/
#include<stdio.h>

//Function to display the array
void display(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
		}
	printf("\n");
}

//Function to do the insertion sort 
void insertion(int arr[],int n){
	int j,temp,i;                                                       
	for(i=1;i<n;i++){
		temp = arr[i];
		j = i - 1;
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];                                 
			--j;
			}
		arr[j+1]=temp;
		}	
}

//Driver function
int main(){
		int arr[100],n,i;
		printf("Enter Number of Elements:\n");
		scanf("%d",&n);
		printf("Enter %d Numbers:\n",n);
		printf("Enter array elements :\n");
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		printf("Unsorted list : ");
		display(arr,n);
		insertion(arr,n);
		printf("Sorted list : ");
		display(arr,n);
		return 0;
}

/*Output:-
Enter Number of Elements:
4
Enter 4 Numbers:
Enter array elements :
12 24 88 11 
Unsorted list : 12 24 88 11 
Sorted list : 11 12 24 88
*/
/*
 Time complexity:-
     Best Case: 
		O(n)
        The best-case time complexity for Insertion Sort occurs when the 
        input array is already sorted.

    Average Case: 
     	O(n^2)
        On average, Insertion Sort exhibits a time complexity of O(n^2). 
        This occurs when the input array is in random order, and the 
        algorithm needs to perform multiple comparisons and swaps.

    Worst Case: 
		O(n^2)
        The worst-case time complexity arises when the input array is in 
        reverse order or sorted in descending order.

  Conclusion:- 
  Insertion Sort is a simple sorting algorithm with a time complexity of 
  O(n^2) in the average and worst cases. While it is not as efficient as 
  more advanced algorithms on large datasets, it has advantages such as 
  simplicity and ease of implementation, making it suitable for small 
  datasets or partially sorted data.
 */