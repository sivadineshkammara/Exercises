/*
*   Name: pointer_lab.c
*   Purpose: Demonstrate pointer usage in C with modifing pointer using **.
*   Exercise for C practice session 10/08/2026.
*/

#include <stdio.h>

void modifyPointer(int **ptr){
    static int value = 42; // Static variable to ensure it persists after function returns
    *ptr = &value; // Modify the pointer to point to the static variable
}

int main(){
    int value;
    printf("Enter a number: ");
    scanf("%d", &value);
    int *ptr = &value;
    printf("Before modification: *ptr = %d\n", *ptr); // Should print 10
    modifyPointer(&ptr);
    printf("After modification: *ptr = %d\n", *ptr); // Should print 42
    return 0;
}