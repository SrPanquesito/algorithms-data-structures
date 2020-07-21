#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int binarySearchRecursive(int * arr, int start, int end, int n) {
    if (start == end) return -1;
    int mid = start + (end-start)/2;
    if (n == arr[mid]) return mid;
    if (n < arr[mid]) return binarySearchRecursive(arr, start, mid-1, n);
    if (n > arr[mid]) return binarySearchRecursive(arr, mid+1, end, n);
}

int binarySearch(int * arr, int end, int n) {
    int start = 0, mid = 0;

    while (start <= end) {
        mid = start + (end-start)/2;
        if (arr[mid] == n) return mid;
        if (n < arr[mid]) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE] = {2,3,6,8,10,12,18,25,28,30};

    printf("\nEl numero se encuentra en la posicion %d\n", binarySearch(arr, MAX_SIZE, 9));
    
    printf("\nEl numero se encuentra en la posicion %d\n", binarySearchRecursive(arr, 0, MAX_SIZE, 2));

    return 0;
}