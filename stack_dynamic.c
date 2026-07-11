
#include<stdio.h>
#include<stdlib.h>

int *stack = NULL;
int top = -1, max = 0;

// create function
void create()
{
    if(stack != NULL)
    {
        free(stack);
    }

    printf("Enter size of stack: ");
    scanf("%d", &max);

    stack = (int *)malloc(max * sizeof(int));

    if(stack == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    top = -1;
    printf("Stack Created Successfully.\n");
}

// Push Operation
void push(int value)
{
    if(stack == NULL)
    {
        printf("Create the stack first.\n");
        return;
    }

    if(top == max - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Pop Operation
void pop()
{
    if(stack == NULL)
    {
        printf("Create the stack first.\n");
        return;
    }

    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Display Operation
void display()
{
    if(stack == NULL)
    {
        printf("Create the stack first.\n");
        return;
    }

    if(top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack Elements:\n");

        for(int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. Create Stack\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 3:
                pop();
                break;

            case 4:
                display();
                break;

            case 5:
                free(stack);
                printf("Program Terminated.\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}