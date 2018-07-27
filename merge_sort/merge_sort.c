#include <stdio.h>
#include <stdlib.h>

int merge_sort(int*, int);
int merge(int*, int*, int*, int);

int merge_sort(int *data, int data_sz) {
    int *left = NULL, *right = NULL;
    int middle;

    // Recursion exit condition 
    if (data_sz == 1) {
        return 0;
    }

    middle = data_sz / 2;

    // Allocate memory for each half of array
    if (!(left = malloc(sizeof(int)*middle))) {
        printf("malloc() error");
        return -1;
    }
    if (!(right = malloc(sizeof(int)*(data_sz - middle)))) {
        printf("malloc() error");
        return -1;
    }
   
    // Copy array halves to left and right
    for (int i = 0; i < middle; i++) {
        left[i] = data[i];
    }
    for (int i = 0; i+middle < data_sz; i++) {
        right[i] = data[i+middle];
    }

    // Recursive implementation for each half of array
    if (merge_sort(left, middle)) {
        printf("Left merge error\n");
        return -1;
    }
    if (merge_sort(right, data_sz-middle)) {
        printf("Right merge error\n");
        return -1;
    }
    if (merge(data, left, right, data_sz)) {
        printf("Merge error\n");
        return -1;
    } 
    
    // Free allocated memory
    free(right);
    free(left);

    return 0;
}

int merge(int *data, int *left, int *right, int data_sz) {
    int i = 0, j = 0, k = 0;
    int middle = data_sz/2;
    int llen = middle, rlen = data_sz-middle;

    while ( (i < llen) && (j < rlen) ) {
        if (left[i] < right[j]) {
            data[k] = left[i];
            i++;
        }
        else {
            data[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < llen) {
        data[k] = left[i];
        i++;
        k++;
    }
    
    while (j < rlen) {
        data[k] = right[j];
        j++;
        k++;
    }

    return 0;
}

int main() {
    int SIZE = 10;
    int *data;
    int arr[10] = {1,5,7,12,14,0,25,9,20, 3};
    
    data = &arr[0];

    for (int i = 0; i < SIZE; i++) {
        data[i] = arr[i];
    }

    printf("Original array:");
    for (int i = 0; i < SIZE; i++) {
        printf(" %d", data[i]);
    }
    printf("\n");

    if ((merge_sort(data, SIZE))) {
        printf("Error. Stopping.");
    }

    printf("Sorted data:");
    for (int i = 0; i < SIZE; i++) {
        printf(" %d", data[i]);
    }
    printf("\n");
}
