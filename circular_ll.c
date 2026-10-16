#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
 
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL){
        head = newNode;
        tail = newNode;
        newNode->next = head; // Point to itself to make it circular
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head; // Maintain circular link
    }
}

void insertBeforePosition(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position <= 1 || head == NULL) {
        // Insert at the beginning
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Point to itself to make it circular
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head; // Maintain circular link
        }
        return;
    }

    struct Node* current = head;
    int count = 1;

    while (count < position - 1 && current->next != head) {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    current->next = newNode;

    if (current == tail) {
        tail = newNode; // Update tail if inserted at the end
    }
}

void deleteFirstNode() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    if (head == tail) {
        // Only one node in the list
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        tail->next = head; // Maintain circular link
    }

    free(temp);
}       

void deleteAfterPosition(int position) {
    if (head == NULL || head->next == head) {
        printf("List is empty or has only one node.\n");
        return;
    }

    struct Node* current = head;
    int count = 1;

    while (count < position && current->next != head) {
        current = current->next;
        count++;
    }

    if (current->next == head) {
        printf("No node exists after the specified position.\n");
        return;
    }

    struct Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;

    if (nodeToDelete == tail) {
        tail = current; // Update tail if the deleted node was the tail
    }

    free(nodeToDelete);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(back to head)\n");
}

void main(){
    int choice, value, position;
    printf("1. Insert at end\n 2. Insert before position\n 3.Delete First Node\n 4. Delete after specified position\n 5. Display List\n 6. Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert before: ");
                scanf("%d", &position);
                insertBeforePosition(value, position);
                break;
            case 3:
                deleteFirstNode();
                break;
            case 4:
                printf("Enter position after which to delete: ");
                scanf("%d", &position);
                deleteAfterPosition(position);
                break;
            case 5:
                displayList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}