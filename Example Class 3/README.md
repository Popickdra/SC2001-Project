Unbounded Knapsack
Given unlimited supplies of n types of objects, how do we maximise the profit while adhering to the capacity of the knapsack?

Data Structures used:
Weight - Array of weights for each object type
Profit - Array of profits for each object type
LookUp - Hashmap to denote the max profits of the objects at a certain capacity

Recursive Definition:
P(C) = max(maxProfit, profit[i] + recursive_knapsack(C-weight[i])
Only happens when weight[i] is less than C

Max Profit:
(a) 21
(b) 16
