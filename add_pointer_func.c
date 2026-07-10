//c program to perform sum of two numbers using function using pointer
#include<stdio.h>
void add(int *a, int *b){
    int sum;
    sum = *a + *b;
    printf("\nThe total is: %d", sum);
}
void main(){
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    add(&x, &y);
}