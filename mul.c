#include <stdio.h>

int main()
{
    int a, b, c;
    float mul;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    mul = a * b * c;

    printf("The product is: %.2f", mul);

    return 0;
}