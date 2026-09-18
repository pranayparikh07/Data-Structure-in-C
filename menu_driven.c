#include <stdio.h>
void add()
{
    int a, b, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("Sum = %d\n", sum);
}
void sub()
{
    int a, b, diff;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b); 
    diff = a - b;
    printf("Difference = %d\n", diff);
}
int main()
{
    char choice;
    while (1)
    {
        printf("+ for addition\n - for subtraction\n 0 for exit\n Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '+':
            add();
            break;
        case '-':
            sub();
            break;
        case '0':
            printf("Exiting the program\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
