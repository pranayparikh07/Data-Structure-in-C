#include <stdio.h>

#define MAX 10

struct Deque {
    char items[MAX];
    int front;
    int rear;
};

// Insert at rear
void insertRear(struct Deque *dq, char item) {
    if (dq->rear == MAX - 1) {
        printf("Deque is full\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
    }

    dq->rear++;
    dq->items[dq->rear] = item;
}

// Delete from rear
char deleteRear(struct Deque *dq) {
    char item;

    if (dq->front == -1 || dq->front > dq->rear) {
        printf("Deque is empty\n");
        return '\0';
    }

    item = dq->items[dq->rear];
    dq->rear--;

    if (dq->rear < dq->front) {
        dq->front = -1;
        dq->rear = -1;
    }

    return item;
}

// Display deque
void display(struct Deque *dq) {
    int i;

    if (dq->front == -1) {
        printf("Empty");
        return;
    }

    for (i = dq->front; i <= dq->rear; i++) {
        printf("%c", dq->items[i]);

        if (i < dq->rear)
            printf(", ");
    }
}

// Get price
int getPrice(char item) {
    switch (item) {
        case 'a': return 5;
        case 'b': return 10;
        case 'c': return 7;
        case 'd': return 6;
        case 'e': return 8;
        case 'f': return 10;
        default: return 0;
    }
}

// Calculate total bill
int totalBill(struct Deque *dq) {
    int total = 0;
    int i;

    for (i = dq->front; i <= dq->rear; i++) {
        total += getPrice(dq->items[i]);
    }

    return total;
}

int main() {
    struct Deque dq;

    dq.front = -1;
    dq.rear = -1;

    // Step 1: Put a
    insertRear(&dq, 'a');
    printf("Step 1: ");
    display(&dq);
    printf("\n");

    // Step 2: Put b
    insertRear(&dq, 'b');
    printf("Step 2: ");
    display(&dq);
    printf("\n");

    // Step 3: Remove b
    deleteRear(&dq);
    printf("Step 3: ");
    display(&dq);
    printf("\n");

    // Step 4: Put c
    insertRear(&dq, 'c');
    printf("Step 4: ");
    display(&dq);
    printf("\n");

    // Step 5: Put d
    insertRear(&dq, 'd');
    printf("Step 5: ");
    display(&dq);
    printf("\n");

    // Step 6: Remove d
    deleteRear(&dq);
    printf("Step 6: ");
    display(&dq);
    printf("\n");

    // Step 7: Put e
    insertRear(&dq, 'e');
    printf("Step 7: ");
    display(&dq);
    printf("\n");

    // Step 8: Put f
    insertRear(&dq, 'f');
    printf("Step 8: ");
    display(&dq);
    printf("\n");

    // Final bill
    printf("\nFinal Bill (FIFO Order): ");
    display(&dq);

    printf("\nTotal Bill Amount: Rs. %d\n", totalBill(&dq));

    return 0;
}