#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

//Check if Queue is Full
int isFull(){
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1)){
        return 1;
    }
    return 0;
}

//Check is Queue is empty
int isEmpty(){
    if(front == -1){
        return 1;
    }
    return 0;
}

//Function to enter elements into queue
void enqueue(int value){
    if(isFull()){
        printf("Queue is Full!\n");
    }
    else{
        if(front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Enqueued Value : %d\n",value);
    }
}

//Function to remove an element from the queue
void dequeue(){
    if(isEmpty()){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Dequeued Value : %d\n",queue[front]);
        if(front == rear) //queue has only one element
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

//Function to display the queue elements
void display(){
    if(isEmpty()){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Queue Elements are : ");
        int i = front;
        while(i != rear){
            printf("%d ",queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n",queue[rear]);
    }
}

//Main Function
int main(){
    int choice,value;
    while(1){
        printf("\nChoose :\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to be enqueued : ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
