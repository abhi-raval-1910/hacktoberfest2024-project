#include <stdio.h>
#include <math.h>

// Jump Search function
int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n);  // Calculate the optimal jump size
    int prev = 0;

    // Find the block where the target is present
    while (arr[(step < n ? step : n) - 1] < target) {
        prev = step;  // Move to the next block
        step += sqrt(n);
        if (prev >= n) return -1;  // Target is not present in array
    }

    // Perform linear search in the identified block
    for (int i = prev; i < step && i < n; i++) {
        if (arr[i] == target) return i;  // Target found at index i
    }

    return -1;  // Target not found in the array
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    printf("Array: ");
    printArray(arr, n);

    int index = jumpSearch(arr, n, target);

    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
