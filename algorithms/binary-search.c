#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int binarySearch(int * arr, int end, int n) {
    int start = 0;
    int mid = (start+end)/2;
    int c = 0;

    while (start <= end) {
        printf("%d\n", c);
        if (arr[mid] == n) return mid;
        if (n < arr[mid]) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
        mid = (start+end)/2;
        c++;
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE] = {2,3,6,8,10,12,18,25,28,30};

    printf("El numero se encuentra en la posicion %d", binarySearch(arr, MAX_SIZE, 9));

    return 0;
}