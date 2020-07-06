#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 11

int main() {
    char str[MAX_SIZE];
    printf("Capture a string: \n");
    scanf("%s", &str);
    printf("\n");

    int lon = 0;
    while(str[lon] != '\0') {
        printf("%c", str[lon]);
        lon++;
    }

    return 0;
}