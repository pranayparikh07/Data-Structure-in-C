#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;                 
    }
    
    printf("Enter value to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Value inserted successfully!\n");
}

void delete() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);
    
    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Value deleted successfully!\n");
        return;
    }
    
    struct Node* curr = head;
    while (curr->next != NULL && curr->next->data != value) {
        curr = curr->next;
    }
    
    if (curr->next == NULL) {
        printf("Value not found!\n");
        return;
    }
    
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    printf("Value deleted successfully!\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Linked List Menu ===\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
