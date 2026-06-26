#include<stdio.h>
int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("%d\n", a++);
    printf("%d\n", b--);
    printf("%d\n", b);
    printf("%d\n", a);
    printf("%d\n", ++a);
    return 0;
}