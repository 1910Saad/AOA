/* 				EXP7

Aim : Implement algorithm for All pair shortest path problem using dynamic programming.
Name : Khan Saad Alikhan
Roll no : 22CO24
Academic Year : 2023-2024
Batch : 2
*/

/*
Theory :
The Floyd Warshall Algorithm is an all pair shortest path algorithm unlike Dijkstra and Bellman Ford
which are single source shortest path algorithms. This algorithm works for both the directed and 
undirected weighted graphs. But, it does not work for the graphs with negative cycles
(where the sum of the edges in a cycle is negative). It follows Dynamic Programming approach to check every
possible path going via every possible node in order to calculate shortest distance between every pair of nodes.
*/

/*
Algorithm :- 

    1. n = no of vertices
    2. A = matrix of dimension n*n
    3. for k = 1 to n
    4.   for i = 1 to n
    5.     for j = 1 to n
    6.       𝐴^𝑘[i, j] = min (𝐴^(𝑘−1)[i, j], 𝐴^(𝑘−1)[i, k] + 𝐴^(𝑘−1)[k, j])
    7. return A

*/

#include <stdio.h>

#define nV 4
#define INF 999

void printMatrix(int matrix[][nV]);
void floydWarshall(int graph[][nV]);

int main()
{
    int graph[nV][nV];

    printf("Enter the adjacency matrix for the graph (%d x %d):\n", nV, nV);
    for (int i = 0; i < nV; i++)
        for (int j = 0; j < nV; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(graph);

    return 0;
}

void printMatrix(int matrix[][nV])
{
    printf("The shortest path distance between every pair of vertices is : \n");
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][nV])
{
    int matrix[nV][nV];

    for (int i = 0; i < nV; i++)
        for (int j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    for (int k = 0; k < nV; k++)
    {
        for (int i = 0; i < nV; i++)
        {
            for (int j = 0; j < nV; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    printMatrix(matrix);
}

/*Output:-
Enter the adjacency matrix for the graph (4 x 4):
0 8 999 1
999 0 1 999
4 999 0 999
999 2 9 0
The shortest path distance between every pair of vertices is :
   0   3   4   1
   5   0   1   6
   4   7   0   5
   7   2   3   0
*/

/*
  Time Complexity: O(V3), where V is the number of vertices in the graph and we run three nested loops each of size V
  Auxiliary Space: O(V2), to create a 2-D matrix in order to store the shortest distance for each pair of nodes.

  Conclusion:- 
  The all-pairs shortest path problem is a graph theory problem that involves finding the shortest path between
  every pair of nodes in a graph. The input is a weighted, directed graph, and the output is an n x n matrix that
  contains the shortest-path weights. 

 */