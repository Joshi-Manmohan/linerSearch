#include <stdio.h>
#include <math.h>

void jumpSort(int arr[], int n) {
    int jump = (int)sqrt(n);  // Determine the jump size
    int prev = 0;

    // Finding the block where the element is present
    while (prev < n && arr[prev] < arr[0]) {
        prev += jump;
    }

    // Performing a linear search in the block
    for (int i = prev - jump; i < n && i < prev; i++) {
        if (arr[i] > arr[0]) {
            // Swap the elements if found
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            break;
        }
    }

    // Sorting the remaining elements
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Insertion sort for the rest of the array
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 34, 7, 23, 32, 5, 62 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    jumpSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
