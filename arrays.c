#include<stdio.h>

/* Exercise: 
    Create an integer array of five elements.
    Print every element using:
    printf();
    1. without using loops.
    2. Now print the same array using for loop.
    3. Ask the user to enter five numbers, store and print them.

    Write a program that:
    reads 10 numbers
    stores them in an array
    prints:
    largest number
    smallest number
    sum
    average
    reverse of the array

    Rules:
    Use only one array.
    Use a single for loop to process the values after input.
*/
void readElements(int *arr, const int n);
void printElements(int *arr, const int n);
int max(int *arr, const int n);
int min(int *arr, const int n);
int sum(int *arr, const int n);
float average(int *arr, const int n);

void readElements(int *arr, const int n){
    printf("Please Enter the Array elements:\n");
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i);
        scanf("%d", (arr+i));
    }
}
void reverseElements(int *arr, const int n){
    for(int i=n-1; i>=0; i--){
        printf("%d\n", *(arr+i));
    }
}

int sum(int *arr, const int n){
    int total = 0;
    for(int i=0; i<n; i++){
        total += *(arr + i);
    }
    return total;
}

int max(int *arr, const int n){
    int max = *(arr);

    for(int i=0; i<n; i++){
        if(max<*(arr+i)){max = *(arr+i);};
    }
    return max;
}

int min(int *arr, const int n){
    int min = *(arr);

    for(int i=0; i<n; i++){
        if(min>*(arr+i)){min = *(arr+i);};
    }
    return min;
}

float average(int *arr, const int n){
    int total = sum(arr,n);
    float avg = (float)total/n;
    return avg;
}

void arraySum(int *arr, const int n){
    
    printf("Sum of all Array elements is: %d\n", sum(arr,n));

}

void arrayMax(int *arr, const int n){
    printf("The largest element in the Array is: %d\n", max(arr,n));
}
void arrayMin(int *arr, const int n){
    printf("The smallest element in the Array is: %d\n", min(arr,n));
}

void arrayAverage(int *arr, const int n){
    printf("The average of given Array is: %.2f\n", average(arr, n));
}
int main(){
    int arrLen ;
    printf("Enter the length of Array: ");
    scanf("%d", &arrLen);
    int arr[arrLen];

    readElements(arr,arrLen);
    reverseElements(arr, arrLen);
    arraySum(arr,arrLen);
    arrayMax(arr,arrLen);
    arrayMin(arr,arrLen);
    arrayAverage(arr,arrLen);

    return 0;
}