/* 				EXP8

Aim : To implement sum of subset problem using backtracking.
Name : Khan Saad Alikhan
Roll no : 22CO24
Academic Year : 2023-2024
Batch : 2
*/

/*
Theory :-
	The Subset Sum problem involves finding all possible subsets 
    of a given set of numbers whose sum equals a specified target 
    sum. It has applications in various domains such as finance, 
    cryptography, and data analysis. The problem is a classic example 
    of a combinatorial optimization problem, and solving it efficiently 
    is essential for many practical tasks.
 */
/* 
Algorithm for Subset Sum Algorithm:
    1. Define a function 'findSubsets' with parameters 'set', 'n', 'sum', 
       'subsetSize', 'total', and 'index':
    2. If 'total' equals 'sum', print the subset and return.
    3. If 'index' is greater than or equal to 'n' or 'total' is greater 
       than 'sum', return (backtrack).
    4. Include the current element in the subset and backtrack:
        1. Set the current element of the subset ('subset[subsetSize]') to 
           the current element of the set ('set[index]').
        2. Recursively call 'findSubsets' with incremented 'subsetSize', 
           increased 'total' by the current element, and incremented 'index'.
    5. Exclude the current element from the subset and backtrack:
        1. Recursively call 'findSubsets' with the same 'subsetSize', 'total', 
           and incremented 'index'.
    6. End function.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Global array to store the subset
int subset[MAX];

// Function to print the subset
void printSubset(int subset[], int subsetSize)
{
    for (int i = 0; i < subsetSize; i++)
        printf("%d ", subset[i]);
    printf("\n");
}

// Function to find all possible subsets with the given sum
void findSubsets(int set[], int n, int sum, int subsetSize, int total, int index)
{
    // If the subset has the desired sum, print it
    if (total == sum) {
        printSubset(subset, subsetSize);
        return;
    }

    // If we have processed all elements or sum becomes negative, backtrack
    if (index >= n || total > sum)
        return;

    // Include the current element and backtrack
    subset[subsetSize] = set[index];
    findSubsets(set, n, sum, subsetSize + 1, total + set[index], index + 1);

    // Exclude the current element and backtrack
    findSubsets(set, n, sum, subsetSize, total, index + 1);
}

int main()
{
    int set[MAX];
    int n, sum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &sum);

    printf("Solution sets:\n");
    findSubsets(set, n, sum, 0, 0, 0);

    return 0;
}
/*
OUTPUT:-
    Enter the number of elements in the set: 5
    Enter the elements of the set:
    12 6 2 4 1
    Enter the target sum: 13
    Solution sets:
    12 1
    6 2 4 1
*/
/*
Time complexity:
    Best Case: 
        It's challenging to define a distinct best-case scenario for 
        the Subset Sum problem due to its nature. However, if the 
        desired sum is found early in the search space, the time 
        complexity can be better.
        
    Average Case: 
        O(2^n)
        The average-case time complexity of the Subset Sum problem 
        solution is O(2^n), where n is the number of elements in the set. 
        This complexity arises due to the exponential growth in the 
        number of possible subsets to explore.
        
    Worst Case: 
        O(2^n)
        The worst-case time complexity of the Subset Sum problem solution 
        is also O(2^n), where n is the number of elements in the set. In 
        the worst case, the algorithm needs to explore all possible subsets, 
        resulting in exponential time complexity.
*/

/*
Conclusion:
    The Subset Sum problem solution exhibits exponential time complexity, 
    making it computationally expensive, especially for larger sets. Although 
    backtracking algorithms like the one used here can efficiently explore 
    solution spaces, the exponential growth in the number of subsets makes 
    it impractical for large sets. Various optimization techniques such as 
    dynamic programming can be employed to improve the performance for specific cases.
*/