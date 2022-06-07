#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void insertion(int arr[], size_t size);
void show_arr(int const arr[], size_t size);

int main(){
    // Set random seed
    srand(time(NULL));

    // Initial unsorted array
    int arr[SIZE];
    for(size_t i = 0; i < SIZE; i++){
        arr[i] = rand() % 100;
    }

    show_arr(arr, SIZE);

    insertion(arr, SIZE);

    show_arr(arr, SIZE);

    return 0;
}

void insertion(int arr[], size_t size){
    printf("Insertion algo.\n");
    int key = 0;

    // Index of key
    for(size_t i = 1; i < size; i++){
        key = arr[i];

        // Compare each element
        // !! When arr element < Key quit the while
        size_t j = i - 1;
        while(key < arr[j] && j >= 0){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void show_arr(int const arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        printf("%3d", arr[i]);
    }
    puts("\n");
}