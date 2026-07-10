//addition of array elements in function 
#include<stdio.h>
void add(int arr[], int size){  
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    printf("\nThe total is: %d", sum);
}
void main(){
    int arr[5];
    printf("Enter 5 numbers: ");
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }
    add(arr, 5);
}
