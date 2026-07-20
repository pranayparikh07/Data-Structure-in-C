// Implementation of Linked List (Insertion at Beginning)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void begin();
void display();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== Linked List Menu =====");
        printf("\n1. Insert at Beginning");
        printf("\n2. Display");
        printf("\n3. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                begin();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("\nExiting Program...\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

void begin()
{
    struct node *ptr;
    int value;

    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("\nMemory Allocation Failed!\n");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &value);

    ptr->data = value;
    ptr->next = head;
    head = ptr;

    printf("\nNode inserted at the beginning.\n");
}

void display()
{
    struct node *temp = head;

    if (temp == NULL)
    {
        printf("\nLinked List is Empty.\n");
        return;
    }

    printf("\nLinked List:\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}