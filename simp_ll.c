/*(d) Delete a first node of the linked list.
(e) Delete a node before specified position.
(f) Delete a node after specified position.*/
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
void delete_first(){
    struct node *tmp = head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    } 
    if(head==tail){
        head=tail=NULL;
    }
    else{
        head=head->next;
    }
    free(tmp);
}

void delete_before(int position)
{
    if (head == NULL || position <= 1)
    {
        printf("No node exists before the specified position\n");
        return;
    }

    if (position == 2)
    {
        struct node *tmp = head;
        head = head->next;
        free(tmp);
        return;
    }

    struct node *prev = head;
    struct node *current = head->next;
    int count = 2;

    while (current->next != NULL && count < position - 1)
    {
        prev = current;
        current = current->next;
        count++;
    }

    if (count != position - 1)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = current;
    if (prev == tail)
        tail = current;
    free(prev);
}

void delete_after(int position)
{
    if(head==NULL || position <= 0)
    {
        printf("Invalid position or list is empty\n");
        return;
    }

    struct node *current = head;
    int count = 1;
    while(current != NULL && count < position)
    {
        current = current->next;
        count++;
    }

    if(current == NULL || current->next == NULL)
    {
        printf("No node exists after the specified position\n");
        return;
    }

    struct node *tmp = current->next;
    current->next = tmp->next;
    if (tmp == tail)
        tail = current;
    free(tmp);
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
int main(void){
    int choice, value;
    printf("\n1. Insert at front\n2. Insert at end\n3. Insert in ascending order\n4. Display list\n5. Delete First Node\n6. Delete Node before Specified Position\n7. Delete Node after Specified Position\n 8. Exit\n");
   
    while(1){
        printf("\nEnter your choice: "); 
        scanf("%d", &choice);
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
                delete_first();
                break;
            case 6:
                printf("Enter position before which to delete: ");
                scanf("%d", &value);
                delete_before(value);
                break;
            case 7:
                printf("Enter position after which to delete: ");
                scanf("%d", &value);
                delete_after(value);
                break;
            case 8:
                printf("Exiting...\n");
                while (head != NULL)
                    delete_first();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
