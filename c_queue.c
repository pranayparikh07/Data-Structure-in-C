#include <stdio.h>

#define size 4

int queue[size];
int rear = -1, front = -1;

void enqueue(int value)
{
    if ((rear + 1) % size == front)
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = queue[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    return value;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % size;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            value = dequeue();

            if (value != -1)
            {
                printf("Deleted element is %d\n", value);
            }
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}