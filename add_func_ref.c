//addition of two number in function using reference
#include<stdio.h>
void add(int *a, int *b){  
    
    int sum;
    sum = *a + *b;
    printf("\nThe total is: %d", sum);
}
void main(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    add(&a, &b);
}