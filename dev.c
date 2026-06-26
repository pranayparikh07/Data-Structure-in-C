#include<stdio.h>
int main() {
    int a, b;
    float div;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    if (b !=0) {
        div = (float)a/b;
        printf("Division of %d and %d is: %.2f", a, b, div);
    } else {
        printf("Division by zero is not allowed.");

    }
    return 0;
}