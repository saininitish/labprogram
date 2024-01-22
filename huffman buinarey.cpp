#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        
        int mid = left + (right - left) / 2;

         
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }

        
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
 
    return -1;
}

int main() {
    int arr[] = {10, 35, 40, 45, 50, 55, 60, 65, 70, 100};
    int target = 100;
    int size = sizeof(arr) / sizeof(arr[0]);

     
    int result = binarySearchRecursive(arr, 0, size - 1, target);

     
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
