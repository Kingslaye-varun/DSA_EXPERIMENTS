#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

//Function to insert a node at the beginning
void insertAtBeginning(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted at beginning : %d\n",value);
}

//Function to delete a node from the beginning
void deleteFromBeginning(){
    if(head == NULL){
        printf("List Empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted from beginning : %d\n",temp->data);
    free(temp);
}

//Function to insert a node at the end
void insertAtEnd(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted at end : %d\n",value);
}

//Function to delete a node from the end
void deleteFromEnd(){
    if(head == NULL){
        printf("List Empty!\n");
        return;
    }
    struct Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    printf("Deleted from end : %d\n",temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

//Function to insert a element from a specific position
void insertAtPosition(int value, int pos){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1){
        newNode->next = head;
        head = newNode;
    }
    else{
        struct Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++){
            temp = temp->next;
        }
        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else{
            printf("Position out of range\n");
            free(newNode);
            return;
        }
    }
    printf("Inserted at position %d: %d\n", pos, value);
}

// Function to delete a node from a specific position
void deleteFromPosition(int pos) {
    if (head == NULL) {
        printf("List Empty!\n");
        return;
    }

    struct Node* temp = head;
    if (pos == 1) {
        head = head->next;
        printf("Deleted from position %d: %d\n", pos, temp->data);
        free(temp);
        return;
    }

    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        struct Node* delNode = temp->next;
        temp->next = temp->next->next;
        printf("Deleted from position %d: %d\n", pos, delNode->data);
        free(delNode);
    } else {
        printf("Position out of range\n");
    }
}

// Function to display the list
void displayList() {
    if (head == NULL) {
        printf("List Empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Main Function
int main() {
    int choice, value, position;

    while (1) {
        printf("\nChoose:\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n");
        printf("7. Display\n8. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 7:
                displayList();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
