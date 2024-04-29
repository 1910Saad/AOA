/* 				EXP9

Aim : Implement algorithm to solve n-Queen problem.
Name : Khan Saad Alikhan
Roll no : 22CO24
Academic Year : 2023-2024
Batch : 2
*/

/*
Theory :-
	The N-Queens problem entails placing N chess queens on an 
	N×N chessboard so that no two queens threaten each other, 
	either horizontally, vertically, or diagonally. This puzzle 
	is not only a fascinating challenge but also holds practical 
	relevance in fields like scheduling and optimization. Solving 
	the N-Queens problem typically involves employing backtracking, 
	a technique that systematically explores potential solutions 
	while ensuring that each placement of a queen adheres to the 
	non-attacking constraint. Despite its seemingly simple premise, 
	the problem's complexity lies in efficiently navigating the 
	exponentially growing solution space, particularly as the board 
	size increases.
 */
/* 
Algorithm for N-Queens Algorithm:
	1. queen(int n)
    2.   int k = 1
    3.   a[k] = 0
    4.   while k != 0
    5.     a[k] = a[k] + 1
    6.     while (a[k] <= n) AND NOT place(k)
    7.       a[k]++
    8.     if a[k] <= n
    9.       if k == n
    10.        print_sol(n)
    11.      else
    12.        k++
    13.        a[k] = 0
    14.    else
    15.      k--
    16.  End queen
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[30] , count = 0 ;
int place(int pos)									// for finding the right position
{
	for (int i = 1 ; i < pos ; i++)
	{
		if((a[i] == a[pos]) || ((abs(a[i]-a[pos]) == abs(i-pos))))
		    return 0;
	}
	return 1;
}

//Display Function
void print_sol(int n)							
{
	count++;

	printf("\n\nSolution #%d:\n",count);
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			if(a[i] == j)
			    printf("Q\t");
			else
			    printf("*\t");
		}
		printf("\n");
	}
}

//N-queen Algorithm
void queen(int n)									
{
	int k=1;
	a[k]=0;

	while(k!=0)
	{
		a[k] = a[k]+1 ;
		while((a[k]<=n) && !place(k))
		    a[k]++;
		if(a[k]<=n)
		{
			if(k==n)
			    print_sol(n);
			else
			{
				k++;
				a[k]=0;
			}
		}
		else
		    k--;
	}
}

//Driver Function
int main()
{
	int i,n;
	printf("\nEnter the number of Queens:: ");
	scanf("%d",&n);
	queen(n);
	printf("\nTotal Solutions = %d",count);
	return 0 ;
}
/*
OUTPUT:-

Enter the number of Queens:: 4


Solution #1:
*       Q       *       *
*       *       *       Q
Q       *       *       *
*       *       Q       *


Solution #2:
*       *       Q       *
Q       *       *       *
*       *       *       Q
*       Q       *       *

Total Solutions = 2
*/
/*
Time complexity:
    Best Case: 
        It's challenging to define a distinct best-case scenario for 
		the N-Queens problem due to its nature. However, in certain 
		cases, where the solution is found early in the search space, 
		the time complexity can be better than the worst case.

    Average Case: 
        O(N!)
        The average-case time complexity of the N-Queens problem 
		solution is O(N!), where N is the number of queens. This 
		complexity arises due to the exponential growth in the number 
		of possible configurations to explore.

    Worst Case: 
        O(N!)
        The worst-case time complexity of the N-Queens problem solution 
		is also O(N!), where N is the number of queens. In the worst 
		case, the algorithm needs to explore all possible permutations 
		of queens on the board, resulting in exponential time complexity.
*/
/*
Conclusion:
    The N-Queens problem solution exhibits exponential time complexity, 
	making it computationally expensive, especially for larger values 
	of N. Various optimizations and pruning techniques can be applied 
	to improve the performance, but the fundamental time complexity remains 
	exponential.

*/