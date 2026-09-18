#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void insert_front(int value)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = value;
    new_node->next = head;
    head = new_node;

    // If list was empty, new node is also the tail
    if (tail == NULL)
    {
        tail = new_node;
    }
}

void insert_end(int value)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL)   // Linked list is empty
    {
        head = new_node;
        tail = new_node;
    }
    else                 // Linked list already has nodes
    {
        tail->next = new_node;
        tail = new_node;
    }
}
void insert_ascending(int value)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    else if (head == NULL || head->data >=value) // Insert at front if list is empty or value is less than head
    {
        new_node-> data = value;
        new_node -> next = head;
        head = new_node;
        if (tail == NULL) // If list was empty, new node is also the tail
        {
            tail = new_node;
        }
    }
    else
    { struct node *current = head;
        while (current->next != NULL && current->next->data <value)
        {
            current = current->next;
        }
        new_node->data = value;
        new_node->next = current->next;
        current->next=new_node;
        if (new_node->next == NULL) // If new node is inserted at the end, update tail
        {
            tail = new_node;
        }
    }
}
void display()
{
    struct node *current = head;
    if (current == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void main(){
    int choice, value;
    printf("\n1. Insert at front\n2. Insert at end\n3. Insert in ascending order\n4. Display list\n5. Exit\n");
    scanf("%d", &choice);
    while(1){
        switch(choice){
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insert_front(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_end(value);
                break;
            case 3:
                printf("Enter value to insert in ascending order: ");
                scanf("%d", &value);
                insert_ascending(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
