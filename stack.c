#include <stdio.h>
#define max 3

int stack[max], top = -1;

void push(int value) {
    if (top == max - 1) {
        printf("Stack Overflow\n");
    }
    else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;  
    }
    else {
        int poppedValue = stack[top];
        printf("%d popped from stack\n", poppedValue);
        top--;
        return poppedValue;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack elements are:\n");

        for (int i = 0; i <= top; i++) {
            printf("| %d |\n", stack[i]);
        }
    }
}

int peep(int location) {
    if (location < 1 || location > top + 1) {
        printf("Invalid location\n");
        return -1;
    }
    else {
        int value = stack[location - 1];
        printf("Element: %d\n", value);
        return value;
    }
}

void change(int location, int value) {
    if (location < 1 || location > top + 1)
        printf("Invalid location\n");
    else {
        stack[location - 1] = value;
        printf("Value changed successfully\n");
    }
}

int main() {
    int choice, value, location;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Peep\n5. Change\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter the value: ");
                scanf("%d", &value); push(value); break;


            case 2: {
                int poppedValue = pop();
                if(poppedValue == -1) { printf("Stack Underflow\n"); }
                else { printf("Returned value: %d\n", poppedValue); }
                break;
            }

            case 3:
                display();
                break;

            case 4:
                printf("Enter the location to peep: ");
                scanf("%d", &location);
                if(peep(location) == -1) { printf("Invalid location\n"); }
                else { printf("Returned value: %d\n", peep(location)); }
                
                break;

            case 5:
                printf("Enter Location to change: "); scanf("%d", &location);

                printf("Enter new value: "); scanf("%d", &value);

                change(location, value);   
                break;

            case 6:
                printf("Exiting....");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}