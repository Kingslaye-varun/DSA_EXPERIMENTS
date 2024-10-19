#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed: %d\n", value);
}

// Pop function
void pop() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
}

// Display function
void displayStack() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Node structure for queue
struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct QueueNode *front = NULL, *rear = NULL;

// Enqueue function
void enqueue(int value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Dequeue function
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct QueueNode* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

// Display function
void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct QueueNode* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, stackOrQueue;

    printf("Choose:\n1. Stack\n2. Queue\n");
    scanf("%d", &stackOrQueue);

    if (stackOrQueue == 1) {
        // Stack operations
        while (1) {
            printf("\n1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(value);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    displayStack();
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Invalid choice!\n");
            }
        }
    } else if (stackOrQueue == 2) {
        // Queue operations
        while (1) {
            printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    displayQueue();
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Invalid choice!\n");
            }
        }
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

