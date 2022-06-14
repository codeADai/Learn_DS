#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void countSort(int arr[], size_t size);
int maxArray(const int arr[], size_t size);
void showArray(const int arr[], const int size);

int main(){
    // Set random seed
    srand(time(NULL));

    // Initialize unsorted array
    int arr[SIZE];
    for(size_t i = 0; i < SIZE; i++)
        arr[i] = rand() % 100;

    showArray(arr, SIZE);

    countSort(arr, SIZE);

    showArray(arr, SIZE);

    return 0;
}

void countSort(int arr[], size_t size){
    // Find the max value of array
    int max = maxArray(arr, size);
    // Create size of the max value add one of array
    int *countArrPtr = calloc(max+1, sizeof(int));  // !!

    // Count occurrences of value of array
    for(size_t i = 0; i < size; i++)
        *(countArrPtr + arr[i]) += 1;

    // Store cumulative sum of the elements of the count array
    for(size_t i = 1; i <= max; i++){
        *(countArrPtr + i) += *(countArrPtr + (i - 1));
    }

    // Sort
    int *sorted = calloc(size, sizeof(int));
    for(int i = size-1; i >= 0; i--){
        // int idx = *(countArrPtr + arr[i]) - 1;
        // sorted[idx] = arr[i];
        sorted[*(countArrPtr + arr[i]) - 1] = arr[i];
        *(countArrPtr + arr[i]) -= 1; // !! Repeat value of element, reduce the index of element
    }

    // Copy
    for(size_t i = 0; i < size; i++)
        arr[i] = sorted[i];

    free(countArrPtr);
    free(sorted);
}

int maxArray(const int arr[], size_t size){
    int max = arr[0];
    for(size_t i = 1; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void showArray(const int arr[], const int size){
    for(size_t i = 0; i < size; i++)
        printf("%3d ", arr[i]);

    puts("\n");
}