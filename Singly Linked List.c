#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Element %d inserted at the beginning.\n", value);
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Element %d inserted at the end.\n", value);
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Error: List is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    // Check if the node to be deleted is the head
    if (current->data == value) {
        *head = current->next;
        free(current);
        printf("Element %d deleted successfully.\n", value);
        return;
    }

    // Search for the node to be deleted
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    // If the node is found, delete it
    if (current != NULL) {
        previous->next = current->next;
        free(current);
        printf("Element %d deleted successfully.\n", value);
    } else {
        printf("Error: Element %d not found in the list.\n", value);
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free memory allocated for the linked list
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Node* myList = NULL;

    // Insert elements at the beginning
    insertAtBeginning(&myList, 30);
    insertAtBeginning(&myList, 20);
    insertAtBeginning(&myList, 10);

    // Display the linked list
    displayList(myList);

    // Insert elements at the end
    insertAtEnd(&myList, 40);
    insertAtEnd(&myList, 50);

    // Display the linked list
    displayList(myList);

    // Delete a node
    deleteNode(&myList, 20);

    // Display the modified linked list
    displayList(myList);

    // Free the memory allocated for the linked list
    freeList(&myList);

    return 0;
}
