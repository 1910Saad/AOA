/* 				EXP3

Aim : Implement & analyse merge using D&C technique.
Name : Khan Saad Alikhan
Roll no : 22CO24
Academic Year : 2023-2024
Batch : 2
*/

/*
 Theory :-
  Merge Sort is a Divide and Conquer algorithm. It divides the input 
  array into two halves, calls itself for the two halves, and then 
  it merges the two sorted halves. The merge() function is used for 
  merging two halves. The merge(arr, lb, mid, ub) is a key process that 
  assumes that arr[lb.mid] and arr[mid+1..ub] are sorted and merges the 
  two sorted sub-arrays into one. 
 */
 /*
  Algorithm for Merge sort:-
  1. Merge_sort(arr,beg,end)
  2. if beg < end
  3. set_mid = (beg+end)/2
  4. Merge_sort(arr,beg,end)
  5. Merge-sort(arr,mid+1,end)
  6. Merge(arr,beg,mid,end)
  7. End Merge_sort 
  */

#include <stdio.h>

void merge(int a[], int lb, int ub) {
    int i, j, k, mid;
    int b[100];

    mid = (lb + ub) / 2;
    i = lb;
    j = mid + 1;
    k = lb;

    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k] = a[i]; 
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        while (j <= ub) {
            b[k] = a[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for (k = lb; k <= ub; k++) {
        a[k] = b[k];
    }
}

void merge_sort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        merge_sort(a, lb, mid);
        merge_sort(a, mid + 1, ub);
        merge(a, lb, ub);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    int a[100];
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Elements Before Sorting : \n");
    display(a, n);
    merge_sort(a, 0, n - 1);
    printf("Elements after sorting : \n");
    display(a, n);
    return 0;
}
/*
 Output:-
Enter the number of elements
5
Enter 5 elements
12 66 2 90 5
Elements Before Sorting : 
12 66 2 90 5 
Elements after sorting : 
2 5 12 66 90 


 */
/*
 Time complexity:-
     Best Case: 
		O(n log n)
        The best-case time complexity occurs when the input is already sorted 

    Average Case: 
     	O(n log n)

    Worst Case: 
		O(n log n)
        The worst-case time complexity arises when the input array 
        is in reverse order or has a random order. 
 */
 /*
  Conclusion:- 
  Merge Sort is a versatile and reliable sorting algorithm with a 
  consistent time complexity of O(n log n) across best, average, and 
  worst-case scenarios. Its stability, predictable performance, and 
  efficient divide-and-conquer approach make it a popular choice in 
  various applications. Despite its additional memory requirements, 
  Merge Sort's ability to handle diverse input conditions makes it a 
  dependable sorting algorithm for both small and large datasets.
  */
