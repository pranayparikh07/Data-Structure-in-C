#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
struct Node* tail = NULL;

void insertAtFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    } else {
        tail = newNode; // If the list was empty, set tail to the new node
    }

    head = newNode;
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL) {
        tail->next = newNode;
    } else {
        head = newNode; // If the list was empty, set head to the new node
    }

    tail = newNode;
}

void deleteLastNode() {
    if(tail==NULL) {
        printf("List is empty.");
        return;
    }
    else {
        struct Node* temp = tail;
        tail = tail -> prev;
        if(tail != NULL) {
            tail ->  next = NULL;
        }
        else {
            head = NULL; // If the list becomes empty, set head to NULL
        }
        free(temp);
    }
}

void deleteBeforePosition(int position) {
    if (position <= 1 || head == NULL || head->next == NULL) {
        printf("No node exists before the specified position.\n");
        return;
    }

    struct Node* current = head;
    int count = 1;

    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->prev == NULL) {
        printf("No node exists before the specified position.\n");
        return;
    }

    struct Node* nodeToDelete = current->prev;

    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = current;
    } else {
        head = current; // If the deleted node was the head, update head
    }
    current->prev = nodeToDelete->prev;

    free(nodeToDelete);
}
void displayList() {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void main() {
    int choice, value, position;
   
        printf("\n1. Insert at front\n2. Insert at end\n3. Delete last node\n4. Delete before position\n5. Display list\n6. Exit\n");
         while (1) {
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter value to insert at front: ");
                    scanf("%d", &value);
                    insertAtFront(value);
                    break;
                case 2:
                    printf("Enter value to insert at end: ");
                    scanf("%d", &value);
                    insertAtEnd(value);
                    break;
                case 3:
                    deleteLastNode();
                    break;
                case 4:
                    printf("Enter position before which to delete: ");
                    scanf("%d", &position);
                    deleteBeforePosition(position);
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