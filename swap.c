/*
 * Name: swap.c
 * Purpose: Swap two numbers using only pointers.
 * Exercise for C practice session 10/08/2026.
 */

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x, y;
    printf("Enter two numbers to swap: ");
    scanf("%d %d", &x, &y);

    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y);  
    printf("After swapping: x = %d, y = %d\n", x, y);
    return 0;
}