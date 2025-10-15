/*
======================================================
  Doubly Linked List Operations in C
  Author: Piyush Mahajan
  Description:
    This program implements basic operations
    (insertion, deletion, display) on a doubly
    linked list using dynamic memory allocation.
======================================================
*/

#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node
struct Node {
    int data;
    struct Node *prev, *next;
};

// Function to create a new node
struct Node* create() {
    int n;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

    if (!newnode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter the data: ");
    scanf("%d", &n);

    newnode->data = n;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Function to display the linked list
void Show(struct Node* ptr) {
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Current List:\n");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Insert node at the end
void InsertAtEnd(struct Node** head) {
    struct Node* newnode = create();

    if (*head == NULL) {
        *head = newnode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    Show(*head);
}

// Insert node at the beginning
void InsertAtBeginning(struct Node** head) {
    struct Node* newnode = create();

    newnode->next = *head;
    if (*head != NULL)
        (*head)->prev = newnode;

    *head = newnode;
    Show(*head);
}

// Insert node at a specific index (0-based)
void InsertAtIndex(struct Node** head) {
    int n, i = 0;
    printf("Enter the position at which you wish to insert: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (n == 0) {
        InsertAtBeginning(head);
        return;
    }

    struct Node* newnode = create();
    struct Node* temp = *head;

    while (temp != NULL && i < n - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    Show(*head);
}

// Delete node from beginning
void DeleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
    Show(*head);
}

// Delete node from end
void DeleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
    } else {
        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        free(temp);
    }

    Show(*head);
}

// Delete node at a specific index (0-based)
void DeleteAtIndex(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int n, i = 0;
    printf("Enter the index at which you wish to delete: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid index.\n");
        return;
    }

    struct Node* temp = *head;

    if (n == 0) {
        DeleteAtBeginning(head);
        return;
    }

    while (temp != NULL && i < n) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Index out of range.\n");
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    Show(*head);
}

// Main function with menu
int main() {
    struct Node* head = NULL;
    int choice;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Index\n");
        printf("4. Show List\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Index\n");
        printf("8. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                InsertAtBeginning(&head);
                break;
            case 2: 
                InsertAtEnd(&head); 
                break;
            case 3: 
                InsertAtIndex(&head); 
                break;
            case 4: 
                Show(head); 
                break;
            case 5: 
                DeleteAtBeginning(&head); 
                break;
            case 6: 
                DeleteAtEnd(&head); 
                break;
            case 7: 
                DeleteAtIndex(&head); 
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
