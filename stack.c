//implement push and pop in stack
#include<stdio.h>
int stack [5], top = -1, max = 5;
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
void main(){
    int choice, value;
    while (1){
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}