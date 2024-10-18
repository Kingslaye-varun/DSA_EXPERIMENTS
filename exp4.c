#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

//Check if Queue is Full
int isFull(){
    if((front == 0 && rear = SIZE -1)) || (front == rear + 1){
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


}
