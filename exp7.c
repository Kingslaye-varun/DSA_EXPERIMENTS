#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

// Insert at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("Inserted at beginning: %d\n", value);
}

// Insert at the end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("Inserted at end: %d\n", value);
}

// Delete from beginning
void deleteFromBeginning() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = last->next;
    if (last == last->next) {
        free(last);
        last = NULL;
    } else {
        last->next = temp->next;
        free(temp);
    }
    printf("Deleted from beginning.\n");
}

// Delete from end
void deleteFromEnd() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = last->next;
    if (last == last->next) {
        free(last);
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        free(last);
        last = temp;
    }
    printf("Deleted from end.\n");
}

// Display the list
void display() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = last->next;
    printf("Circular Singly Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Delete from Beginning\n4. Delete from End\n5. Display\n6. Exit\n");
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
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
