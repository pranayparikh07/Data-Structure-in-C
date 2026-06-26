#include<stdio.h>
int main(){
    int a, b;
    char choice;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Enter your choice (+, -, *, /): ");
    scanf(" %c", &choice);
    switch(choice){
        case '+':
            printf("Result: %d\n", a + b);
            break;
        case '-':
            printf("Result: %d\n", a - b);
            break;
        case '*':
            printf("Result: %d\n", a * b);
            break;
        case '/':
            printf("Result: %d\n", a / b);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}