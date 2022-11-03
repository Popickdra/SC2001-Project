# Unbounded Knapsack</br>
Given unlimited supplies of n types of objects, how do we maximise the profit while adhering to the capacity of the knapsack?</br>

Data Structures used:</br>
Weight - Array of weights for each object type</br>
Profit - Array of profits for each object type</br>
LookUp - Hashmap to denote the max profits of the objects at a certain capacity</br>

Recursive Definition:</br>
P(C) = max(maxProfit, profit[i] + recursive_knapsack(C-weight[i])</br>
Only happens when weight[i] is less than C</br>

Max Profit:</br>
(a) 21</br>
(b) 16</br>
