/* 				                    EXP6

Aim : Implement & analyse algorithm for Knapsack problem using Greedy method.
Name : Khan Saad Alikhan
Roll no : 22CO24
Academic Year : 2023-2024
Batch : 2
*/
/*
 Theory :-
  Fractional Knapsack, also known as continuous knapsack problem, is 
  a variation of the classic 0/1 knapsack problem where fractions of 
  items can be taken. In this problem, the objective is to fill the 
  knapsack with items to maximize the total value without exceeding 
  its capacity. Unlike 0/1 knapsack, where items cannot be divided, 
  Fractional Knapsack allows portions of items to be taken.

  The greedy approach is used to solve Fractional Knapsack by selecting 
  items with the maximum value-to-weight ratio until the knapsack is full. 
  This ensures that the most valuable items are selected first, maximizing 
  the total value of items in the knapsack.
 */
 /*
 Algorithm:-
    1. fillKnapsack()
    2.   while cur_weight > 0
    3.     item = -1
    4.     for i = 0 to no_items - 1
    5.       if used[i] == 0 AND (item == -1 OR (float)value[i] / weight[i] > (float)value[item] / weight[item])
    6.         item = i
    7.     used[item] = 1
    8.     cur_weight -= weight[item]
    9.     total_profit += value[item]
    10.    displaySelectedItems()
    11. End fillKnapsack
 */
#include <stdio.h>

#define MAX_ITEMS 10

int capacity, no_items, cur_weight, item;
int used[MAX_ITEMS];
float total_profit;
int weight[MAX_ITEMS];
int value[MAX_ITEMS];

void getUserInput() {
    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("\nEnter the number of items:\n");
    scanf("%d", &no_items);
}

void getItemsInput() {
    printf("\nEnter the weight and value of %d item:\n", no_items);
    for (int i = 0; i < no_items; i++) {
        printf("Weight[%d]:\t", i);
        scanf("%d", &weight[i]);
        printf("Value[%d]:\t", i);
        scanf("%d", &value[i]);
    }
}

void initialize() {
    for (int i = 0; i < no_items; ++i)
        used[i] = 0;

    cur_weight = capacity;
    total_profit = 0;
}

void displaySelectedItems() {
    if (cur_weight >= 0)
        printf("\nAdded object %d (%d Rs., %dKg) completely in the bag. Space left: %d.\n", item + 1, value[item], weight[item], cur_weight);
    else {
        int item_percent = (int)((1 + (float)cur_weight / weight[item]) * 100);
        printf("\nAdded %d%% (%d Rs., %dKg) of object %d in the bag.\n", item_percent, value[item], weight[item], item + 1);
        total_profit -= value[item];
        total_profit += (1 + (float)cur_weight / weight[item]) * value[item];
    }
}

void fillKnapsack() {
    while (cur_weight > 0) {
        item = -1;
        for (int i = 0; i < no_items; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float)value[i] / weight[i] > (float)value[item] / weight[item])))
                item = i;

        used[item] = 1;
        cur_weight -= weight[item];
        total_profit += value[item];

        displaySelectedItems();
    }
}

void printResults() {
    printf("\nFilled the bag with objects worth %.2f Rs.\n", total_profit);
}

void main() {
    getUserInput();
    getItemsInput();
    initialize();
    fillKnapsack();
    printResults();

}
/*
Output :-
    Enter the capacity of knapsack:
    50

    Enter the number of items:
    5

    Enter the weight and value of 5 item:
    Weight[0]:	10
    Value[0]:	60
    Weight[1]:	20
    Value[1]:	100
    Weight[2]:	30
    Value[2]:	120
    Weight[3]:	40
    Value[3]:	140
    Weight[4]:	50
    Value[4]:	160

    Added object 1 (60 Rs., 10Kg) completely in the bag. Space left: 40.

    Added object 2 (100 Rs., 20Kg) completely in the bag. Space left: 20.

    Added 66% (120 Rs., 30Kg) of object 3 in the bag.

    Filled the bag with objects worth 240.00 Rs.
*/
/*
 Time complexity:-
     Best Case: 
		O(n log n)
        The best-case time complexity occurs when the input items are already 
        sorted based on their value-to-weight ratio. In this case, the sorting 
        step dominates the overall time complexity.

    Average Case: 
     	O(n log n)
        The average-case time complexity is also O(n log n) due to the sorting 
        step and the greedy selection of items.

    Worst Case: 
		O(n log n)
        The worst-case time complexity occurs when the input items are sorted 
        based on their value-to-weight ratio, resulting in a time complexity 
        of O(n log n).
*/
/*
  Conclusion: 
        Fractional Knapsack using the greedy approach has a time complexity of 
        O(n log n) on average, making it efficient for practical purposes. The 
        sorting step dominates the time complexity, and the greedy approach ensures 
        that the most valuable items are selected first, resulting in an optimal 
        solution. Additionally, Fractional Knapsack is more versatile than the 
        0/1 Knapsack as it allows fractional selection of items, providing a 
        more flexible and efficient solution for certain scenarios.
*/