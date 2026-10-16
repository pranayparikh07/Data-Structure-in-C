
#include <stdio.h>
#include <stdlib.h>

// Define a node of the stack
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Insert an element at the top of the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed to stack\n", value);
}

// Remove the top element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }

    struct Node* temp = top;
    top = top->next;

    printf("Popped %d from stack\n", temp->data);
    free(temp);
}

// Display all elements from top to bottom
void display() {
    struct Node* current = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
