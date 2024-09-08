#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void initializeList(struct Node** head) {
    int values[] = {1, 2, 3, 4, 5};
    struct Node* current = NULL;

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        struct Node* newNode = createNode(values[i]);
        if (*head == NULL) {
            *head = newNode;
            current = *head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
}


void insertBeforeValue(struct Node** head, int newData, int existingData) {
    struct Node* newNode = createNode(newData);
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == existingData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    while (temp != NULL && temp->data != existingData) {
        prev = temp;
        temp = temp->next;
    }    
    if (temp == NULL) {
        printf("Value %d not found in the list. Inserting at the end.\n", existingData);
        if (prev == NULL) {
            *head = newNode;
            return;
        }
        prev->next = newNode;
        return;
    }   
    newNode->next = temp;
    prev->next = newNode;
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

   
    initializeList(&head);

    int choice, data, beforeData;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Before Value\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert into the linked list: ");
                scanf("%d", &data);
                printf("Enter the value before which the data should be inserted: ");
                scanf("%d", &beforeData);
                insertBeforeValue(&head, data, beforeData);
                break;
            case 2:
                printf("Linked List: ");
                display(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
