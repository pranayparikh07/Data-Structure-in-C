#include<stdio.h>
int main(){
    int a, b, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int *p, *q;
    p = &a;
    q = &b;
    sum = *p + *q;
    printf("\nThe sum is: %d\n", sum);
    return 0;

}