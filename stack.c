//implement push and pop in stack
#include<stdio.h>
#include<stdlib.h>

int *stack = NULL;
int top = -1, max = 0;
void push (int value){
    if (top == max -1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }

}
void pop (){
    if (top == -1){
        printf("Stack Underflow\n");
    }
    else{
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}
void display (){
    if (top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main(void){
    int choice, value;

    printf("Enter maximum stack size: ");
    if (scanf("%d", &max) != 1 || max <= 0){
        printf("Invalid size. Exiting.\n");
        return 1;
    }

    stack = (int *)malloc(max * sizeof(int));
    if (stack == NULL){
        perror("malloc");
        return 1;
    }

    while (1){
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1){
            /* clear invalid input */
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input\n");
            continue;
        }
        switch (choice){
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &value) != 1){
                    int c; while ((c = getchar()) != '\n' && c != EOF);
                    printf("Invalid input\n");
                    break;
                }
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                free(stack);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}