#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void max_heapify(int *arr, int n);
void swap(int *arr, int a, int b);
void heap_sort(int *arr, int n);
void printarray(int *arr, int n);

void main() {
    int sample[] = {4,5,12,3, 23, 51, 89, 100, 5,7,10,13,17,2,9, 33, 56, 2, 0, 88};
    int *arr = &sample[0];
    
    printf("Original array:");
    printarray(arr, SIZE);

    heap_sort(arr, SIZE);

    printf("Sorted array:");
    printarray(arr, SIZE);
}

void heap_sort(int *arr, int n) {

    while(n) {
        max_heapify(arr, n);
        swap(arr, 0, n-1);
        n--;
    }
}

void max_heapify(int *arr, int n) {
    // Left child = 2*i + 1
    // Right child = 2*i + 2
    for (int i = n/2 - 1; i>=0; i--) {
        // Case 1: only 1 child
        if ((2*i + 2) > (n - 1)) {
            // If child > parent, then swap
            if (arr[i] < arr[2*i + 1]) {
                swap(arr, i, 2*i + 1);
            }
        }
        // Case 2: two children
        else {
            // If a child > parent, swap largest child
            if ((arr[i]<arr[2*i+1]) || (arr[i]<arr[2*i+2])) {
                int si = (arr[2*i+1] > arr[2*i+2]) ? 2*i+1 : 2*i+2;
                swap(arr, i, si);
            }
        }
    }
}

void swap(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printarray(int *arr, int n) {
    for (int i = 0; i<n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
