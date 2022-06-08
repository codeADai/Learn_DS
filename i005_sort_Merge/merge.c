#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void mergeSort(int * const arr, size_t start, size_t end);
void merge(int * const arr, size_t start, size_t end, size_t mid);
void showArray(const int * const arr, size_t size, size_t start);

int main(){
    // Set random seed
    srand(time(NULL));

    // Inital array
    int arr[SIZE];
    for(size_t i=0; i<SIZE; i++){
        arr[i] = rand() % 100;
    }

    showArray(arr, SIZE, 0);
    printf("Doing Merge Sort\n");
    mergeSort(arr, 0, SIZE-1);
    showArray(arr, SIZE, 0);

    return 0;
}

void mergeSort(int * const arr, size_t start, size_t end){
    if(end > start){
        size_t mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, end, mid);
    }
}

void merge(int * const arr, size_t start, size_t end, size_t mid){
    int rSize = end - mid;
    int lSize = mid - start + 1;
    // Create array to store unsorted sub-array
    int *l_arr = malloc(sizeof(int) * lSize);
    int *r_arr = malloc(sizeof(int) * rSize);

    // Put unsorted array to created array
    for(size_t i=0; i<lSize; i++){
        l_arr[i] = arr[start + i];
    }
    for(size_t i=0; i<rSize; i++){
        r_arr[i] = arr[mid + i + 1];
    }
    // Sort
    // Index of original unsorted array
    int r = 0, l = 0;
    for(size_t i=start; i<=end; i++){

        // Compare value and fill in
        // !! Below statement is important to set boundaries for sub-array
        // or try is [method](https://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html)
        if(l == lSize || (l_arr[l] >= r_arr[r] && r < rSize)){
            arr[i] = r_arr[r];
            r++;
        }
        else{
            arr[i] = l_arr[l];
            l++;
        }
    }
}

void showArray(const int * const arr, size_t size, size_t start){
    for(size_t i=start; i<size; i++){
        printf("%3d", arr[i]);
    }
    puts("\n");
}