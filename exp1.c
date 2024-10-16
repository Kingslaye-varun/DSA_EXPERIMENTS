#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 5
int st[MAX];
int top = -1;

bool isFull();
bool isEmpty();
void push(int a);
void pop();

int main() {
    int choice,num,i;
    printf("Enter the elements of Stack : \n");
    for(int i = 0;i<MAX;i++){
        printf("Element %d : ",(i+1));
        scanf("%d",&st[i]);
        top = i;
    }
    printf("Enter Function to be performed on the Stack : \n");
    printf("1.Push\n2.Pop\n3.Check Stack Empty\n4.Check Stack Full\n5.Exit\n");
    do{
        printf("\nChoose Operation : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the Number to be pushed : ");
            scanf("%d",&num);
            push(num);
            break;

            case 2:
            pop();
            break;

            case 3:
            if(isEmpty()){
                printf("Stack is Empty");
            }
            else{
                printf("Stack is not Empty");
            }
            break;

            case 4:
            if(isFull()){
                printf("Stack is Full");
            }
            else{
                printf("Stack is not Full");
            }
            break;

            case 5:
            printf("\nExiting the program");
            exit(0);

            default:
            printf("Enter a valid Option");
        }
    }
    while(choice!=5);
    return 0;
}
bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == (MAX - 1);
}

void push(int a){
    if(isFull()){
        printf("Stack is Full");
    }
    else{
        top += 1;
        st[top] = a;
        printf("Pushed %d into the stack\n", a);
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack is Empty");
    }
    else{
        printf("Popped Element : %d",st[top]);
        top -= 1;
    }
}
