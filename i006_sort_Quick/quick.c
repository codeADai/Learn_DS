#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

void quickSort(int arr[], const int start, const int end);
void showArray(const int const arr[], const int size);
const int partition(int arr[], const int start, const int end);
void swap(int * const a, int * const b);

int main(){
    // Set random seed
    srand(time(NULL));

    // Initial unsorted array
    int arr[SIZE];
    for(size_t i=0; i < SIZE; i++)
        arr[i] = rand() % 100;

    showArray(arr, SIZE);
    printf("Doing Quick Sort\n");
    quickSort(arr, 0, SIZE-1);
    showArray(arr, SIZE);

    return 0;
}

void quickSort(int arr[], const int start, const int end){
    if (end > start){
        const int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

const int partition(int arr[], const int start, const int end){
    int i = start - 1;
    int pivot = arr[end];
    
    // Compare pivot value with arr
    for(size_t j=start; j<end; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap pivot element and HigherIdx element
    i++;
    swap(&arr[i], &arr[end]);

    return i;
}

void showArray(const int const arr[], const int size){
    for(size_t i=0; i<size; i++)
        printf("%3d ", arr[i]);
    puts("\n");
}

void swap(int * const a, int * const b){
    if(*a != *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}