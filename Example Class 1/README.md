Merge Insertion Sort</br>
Hybrid Sorting algorithm</br>
At a pre-specified depth n, the array will divide until each divided array is size n.</br>
Then, insertion sort will be called to sort the smaller arrays.</br>
Lastly, merge will be called to sort the smaller sorted arrays into the main sorted array

Insertion Sort:</br>
Compares and sorts until the inserted element is greater than the element before it</br>
Best Case: O(n)</br>
Average Case: O(n^2)</br>
Worst Case: O(n^2)

Merge Sort:</br>
Divides the array until one element is left in the array, it then conquers by merging smaller sorted arrays together</br>
Best Case: O(nlogn)</br>
Average Case: O(nlogn)</br>
Worst Case: O(nlogn)

Merge Insertion Sort:</br>
Assuming average case in insertion sort</br>
Best Case: O(n + nlog(n/s))</br>
Average Case: O(sn + nlog(n/s))</br>
Worst Case: O(sn + nlog(n/s))
