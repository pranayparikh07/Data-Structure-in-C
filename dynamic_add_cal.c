//addition of two number usinf calloc
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *num1, *num2, *sum, *sub;
    num1 = (int*)calloc(1, sizeof(int));
    num2 = (int*)calloc(1, sizeof(int));
    sum = (int*)calloc(1, sizeof(int));
    sub = (int*)calloc(1, sizeof(int));
    printf("Enter two numbers: ");
    scanf("%d %d", num1, num2);
    *sum = *num1 + *num2;
    *sub = *num1 - *num2;
    printf("Sum of %d and %d is: %d", *num1, *num2, *sum);
     printf("\n%d", *sub);
    free(num1);
    free(num2);
    free(sum);
    free(sub);
    printf("\n%d", *sum);
    printf("\n%d", *sub);
    return 0;
}