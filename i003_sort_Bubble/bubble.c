#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void bubble_sort(int arr[], size_t size);
void show_array(const int arr[], size_t size);

int main(){
    // Set random seed
    srand(time(NULL));

    // Inital array
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        arr[i] = rand() % 100;
    }

    show_array(arr, SIZE);

    bubble_sort(arr, SIZE);

    show_array(arr, SIZE);

    return 0;
}

void bubble_sort(int arr[], size_t size){
    puts("Doing Bubble Sort");
    int hold = 0;
    // STEP
    for(int i = 1; i < size; i++){

        //loop each
        for(int t = 0; t < size - i; t++){ // size - i (!!)
            if(arr[t] > arr[t+1]){
                hold = arr[t];
                arr[t] = arr[t+1];
                arr[t+1] = hold;
            }
        }
    }
}

void show_array(const int arr[], size_t size){
    for(int i = 0; i < size; i++){
        printf("%3u", arr[i]);
    }
    puts("");
}