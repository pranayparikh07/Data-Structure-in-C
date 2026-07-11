// Implement Stack using Create, Push, Pop and Display
#include <stdio.h>

void create(int stack[], int size)
{
    printf("Stack of size %d created successfully.\n", size);
}

void push(int stack[], int *top, int max, int value)
{
    if (*top == max - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        (*top)++;
        stack[*top] = value;
        printf("%d pushed to stack\n", value);
    }
}

void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[*top]);
        (*top)--;
    }
}

void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int size, choice, value;
    int top = -1;

    printf("Enter size of stack: ");
    scanf("%d", &size);

    int stack[size];

    create(stack, size);

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(stack, &top, size, value);
            break;

        case 2:
            pop(stack, &top);
            break;

        case 3:
            display(stack, top);
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}