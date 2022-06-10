# Quick Sort

## Process
1. pivot <- Partition(start, end)
2. QuickSort(start, pivot - 1)
3. QUickSort(pivot + 1, end)

## Hint
* Partition function.
    * Variable 
        * Integer i mean the last index of small than pivot array position.
        * Integer i mean how many numbers of element small than pivot.
        * Pivot is the end element of array.
        * Pivot needs to change with i in the end of function.

    * Algorithm
        * Pivot bigger than element i add 1.

        * Case 1. Pivot is the smallest value in array.
            -> At the end of function i need to add 1, because the pivot is the smallest in array. (Line 49)
        * Case 2. Pivot is the largest value in array.
            -> Variable will add i until front of pivot position then Case 1. statment will add 1 again.
        * Case 3. not Case 1. and Case 2. (Normal)

    * After changing the position of pivot and i, the pivot position is the correct position in the sorted problem.(Line 32)
    