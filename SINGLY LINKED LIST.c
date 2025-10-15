/*
======================================================
  Singly Linked List Operations in C
  Author: Piyush Mahajan
  Description:
    This program implements basic operations
    (insertion, deletion, display) on a singly
    linked list using dynamic memory allocation.
======================================================
*/

#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* create();
void Show(struct Node* head);
void InsertAtBeginning(struct Node** head);
void InsertAtEnd(struct Node** head);
void InsertAtIndex(struct Node** head);
void DeleteAtBeginning(struct Node** head);
void DeleteAtEnd(struct Node** head);
void DeleteAtIndex(struct Node** head);
void FreeList(struct Node* head);

// Function to create a new node and take user input
struct Node* create() {
    int n;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter the data: ");
    scanf("%d", &n);
    newnode->data = n;
    newnode->next = NULL;
    return newnode;
}

// Function to display the linked list
void Show(struct Node* ptr) {
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Insert a new node at the beginning
void InsertAtBeginning(struct Node** head) {
    struct Node* newnode = create();
    newnode->next = *head;
    *head = newnode;
    Show(*head);
}

// Insert a new node at the end
void InsertAtEnd(struct Node** head) {
    struct Node* newnode = create();

    if (*head == NULL) {
        *head = newnode;
        Show(*head);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    Show(*head);
}

// Insert a new node at a specific index
void InsertAtIndex(struct Node** head) {
    int n, i = 0;
    printf("Enter the position (starting from 0): ");
    scanf("%d", &n);

    struct Node* newnode = create();

    if (n == 0) {
        newnode->next = *head;
        *head = newnode;
        Show(*head);
        return;
    }

    struct Node* temp = *head;
    while (i < n - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    Show(*head);
}

// Delete the first node of the list
void DeleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    Show(*head);
}

// Delete the last node of the list
void DeleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        Show(*head);
        return;
    }

    struct Node *prev = NULL, *temp = *head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    Show(*head);
}

// Delete a node at a specific index
void DeleteAtIndex(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int n, i = 0;
    printf("Enter the index to delete (starting from 0): ");
    scanf("%d", &n);

    if (n == 0) {
        DeleteAtBeginning(head);
        return;
    }

    struct Node *prev = NULL, *temp = *head;
    while (i < n && temp != NULL) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    Show(*head);
}

// Free the entire list before exiting
void FreeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function with menu-driven interface
int main() {
    struct Node* head = NULL;
    int choice;

    while (1) {
        printf("\n========== LINKED LIST MENU ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Index\n");
        printf("4. Show\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Index\n");
        printf("8. Exit\n");
        printf("======================================\n");
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
                FreeList(head);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
