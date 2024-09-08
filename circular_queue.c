#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

typedef struct {
    int items[MAX];
    int front, rear;
} CircularQueue;

// Initialize the circular queue
void initialize(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(CircularQueue* q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Check if the queue is empty
int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

// Add an element to the circular queue
void push(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot push %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Pushed %d to the queue.\n", value);
}

// Remove an element from the circular queue
int pop(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot pop.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {  // Queue has only one element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Popped %d from the queue.\n", value);
    return value;
}

// Display the elements of the circular queue
void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initialize(&q);
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&q, value);
                break;
            case 2:
                pop(&q);
                break;
            case 3:
                display(&q);
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
