#include "stdio.h"
#include "stdlib.h"

void PrintArray(int *, size_t);
int Mergesort(int *, size_t, size_t);
void Merge(int *, size_t, size_t, size_t);

int main(int argc, char* argv[]) {
    // File handling -- return if error.
    FILE* fp;
    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Unable to open %s\n", argv[1]);
        return -1;
    }

    /* 
        First line of the file contains the 
        number of integers to be read.
        Read that in and store that size to 
        dynamically allocate memory.
    */
    size_t SIZE;
    fscanf(fp, "%d", &SIZE);

    // Dynamically allocate the memory for the array and initialize
    int* arr = (int*)malloc(SIZE * sizeof(int));
    if (!arr) {
        printf("Unable to allocate memory.\n");
        return -1;
    }

    // Read everything in and store in the array
    int i;
    for (i = 0; i < SIZE; i++)
        fscanf(fp, "%d", &arr[i]);

    // Sort the array and print the result
    Mergesort(arr, 0, SIZE - 1);
    printf("Sorted array:\n");
    PrintArray(arr, SIZE);

    // Clean everything up and terminate
    free(arr);
    fclose(fp);
    return 0;
}

// Utility function to print the array
void PrintArray(int * array, size_t size) {
    int i;
    for (i = 0; i < size; i++) 
        printf("%d:\t%d\n", i, array[i]);
    printf("\n");
}

/*
    Recursively divides the array into
        left half: low --> mid
        right half: mid + 1 --> high
    Uses the array indeces as the markers
*/
int Mergesort(int * arr, size_t low, size_t high) {
    if (low < high) {
        size_t mid = low + (high - low) / 2;
        Mergesort(arr, low, mid);
        Mergesort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

/*
    Merges the two array halves together, done 
    in-place to avoid using more space than needed.
    Merging is done using the "two finger algorithm",
    shifting indeces over if the "right finger" is the next
    element in the array
*/
void Merge(int * arr, size_t low, size_t mid, size_t high) {
    size_t leftPtr = low;
    size_t rightPtr = mid + 1;
    while (leftPtr <= mid && rightPtr <= high) {
        // Simply increment if the left index is okay
        if (arr[leftPtr] <= arr[rightPtr])
            leftPtr++;
        // Shift everything over by one otherwise
        else {
            int val = arr[rightPtr];
            int index;
            for (index = rightPtr; index > leftPtr; index--) {
                arr[index] = arr[index - 1];
            }
            arr[leftPtr] = val;

            // For the next pass..
            leftPtr++;
            mid++;
            rightPtr++;
        }
    }
}