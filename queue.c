#include<stdio.h>
#define size 10
int queue[size];
int rear, front =-1;

void enqueue(int value){
    if(front==-1){
        front = rear = 0;
    }
    else if(rear==size-1){
        printf("Queue is full\n");
        return;
    }
    else{
        rear++;
    }
    queue[rear] = value;
}

int dequeue(){
    if(front==-1){
        printf("\nQueue Underflow\n");
        return -1;
    }
    else
    {
        int value = queue[front];
        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
        return value;
    }
}

void display(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

void main(){
    int choice, value;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if(value > 0){
                 printf("Deleted element is %d\n",value);   
                }
                
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}