#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void select_sort(int * const arr, size_t size);
void show_array(const int * const arr, size_t size);

int main(){
    // Set random seed
    srand(time(NULL));

    // Initial array
    int arr[SIZE];
    for(size_t i = 0;i < SIZE; i++){
        arr[i] = rand() % 100;
    }

    show_array(arr, SIZE);

    select_sort(arr, SIZE);

    show_array(arr, SIZE);

    return 0;
}

void show_array(const int * const arr, size_t size){
    for(size_t i = 0;i < size; i++){
        printf("%3d", arr[i]);
    }
    puts("");
}

void select_sort(int * const arr, size_t size){
    printf("Doing Selection Sort\n");
    int min_idx, i;

    for(size_t j = 0;j < size; j++){
        min_idx = j;

        // Get min
        for(i = j + 1;i < size; i++){
            if(arr[i] < arr[min_idx]){
                min_idx = i;
            }
        }

        // Swap
        if(min_idx != j){
            int hold = arr[j];
            arr[j] = arr[min_idx];
            arr[min_idx] = hold;
        }
    }
    
}