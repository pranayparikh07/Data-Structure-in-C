//addition of two numbers using dynamic memmory allocation
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *num1, *num2, *sum;
    num1 = (int*)malloc(sizeof(int));
    num2 = (int*)malloc(sizeof(int));
    sum = (int*)malloc(sizeof(int));
    printf("Enter two number: ");
    scanf("%d %d", num1, num2);
    *sum = *num1 + *num2;
    printf("Sum is: %d", *sum);
    free(num1);
    free(num2);
    free(sum);
    return 0;
}