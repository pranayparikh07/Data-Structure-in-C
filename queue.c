#include <stdio.h>
#define size 5

int queue[size];
int front = -1;
int rear = -1;
int max = 5;
void enqueue (int data);
void dequeue();
void display();
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

   return 0;
}

// Function to insert an element
void enqueue(int data)
{
    if (rear == max - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = data;

        printf("%d inserted into the queue.\n", data);
    }
}

// Function to delete an element
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("%d deleted from the queue.\n", queue[front]);

        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}           

// Function to display the queue
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}
