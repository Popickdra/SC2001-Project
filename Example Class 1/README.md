Merge Insertion Sort
Hybrid Sorting algorithm
At a pre-specified depth n, the array will divide until each divided array is size n. 
Then, insertion sort will be called to sort the smaller arrays.
Lastly, merge will be called to sort the smaller sorted arrays into the main sorted array

Insertion Sort:
Compares and sorts until the inserted element is greater than the element before it
Best Case: O(n)
Average Case: O(n^2)
Worst Case: O(n^2)

Merge Sort:
Divides the array until one element is left in the array, it then conquers by merging smaller sorted arrays together
Best Case: O(nlogn)
Average Case: O(nlogn)
Worst Case: O(nlogn)

Merge Insertion Sort:
Assuming average case in insertion sort
Best Case: O(n + nlog(n/s))
Average Case: O(sn + nlog(n/s))
Worst Case: O(sn + nlog(n/s))
