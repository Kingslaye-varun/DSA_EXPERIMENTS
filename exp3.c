#include<stdio.h>
#include<stdlib.h>

#define MAX 5

//Queue Structure
struct Queue{
    int arr[MAX];
    int front;
    int rear;
};

//Function to initialize Queue
void initialize(struct Queue *q){
    q->front = -1;
    q->rear = -1;
}

//Check if Queue is Full
int isFull(struct Queue *q){
    return (q->rear == MAX-1);
}

//Check if Queue is Empty
int isEmpty(struct Queue *q){
    return (q->front == -1 || q->front>q->rear);
}

//Function to add Element to the queue
void enqueue(struct Queue *q, int value){
    if(isFull(q)){
        printf("Queue is Full!");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
    printf("Enqueued : %d\n",value);
}

//Function to remove an element from the Queue
int dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty!");
        return -1;
    }
    int value = q->arr[q->front];
    q->front++;

    //Reset queue when all elements are dequeued
    if(q->front > q->rear){
        q->front = -1;
        q->rear = -1;
    }

    printf("Dequeued : %d\n",value);
    return value;
}

//Function to display Queue Elements
void display(struct Queue*q){
    if(isEmpty(q)){
        printf("Queue is Empty!");
        return;
    }
    printf("Queue Elements are : \n");
    for(int i = q->front;i <= q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

//Main Function
int main(){
    struct Queue q;
    initialize(&q);

    int choice,value;
    do{
        printf("\nChoose : \n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to Enqueue : ");
                scanf("%d",&value);
                enqueue(&q,value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice!");
        }
    }
    while(choice != 4);
    return 0;
}
