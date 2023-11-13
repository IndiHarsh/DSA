#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
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
        newNode->prev = temp;
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

    // Check if the node to be deleted is the head
    if (current->data == value) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        printf("Element %d deleted successfully.\n", value);
        return;
    }

    // Search for the node to be deleted
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    // If the node is found, delete it
    if (current != NULL) {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
        printf("Element %d deleted successfully.\n", value);
    } else {
        printf("Error: Element %d not found in the list.\n", value);
    }
}

// Function to display the doubly linked list from the head
void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List elements (forward): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to display the doubly linked list in reverse
void displayReverseList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Move to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    printf("Linked List elements (reverse): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Function to free memory allocated for the doubly linked list
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

    // Display the doubly linked list
    displayList(myList);
    displayReverseList(myList);

    // Insert elements at the end
    insertAtEnd(&myList, 40);
    insertAtEnd(&myList, 50);

    // Display the doubly linked list
    displayList(myList);
    displayReverseList(myList);

    // Delete a node
    deleteNode(&myList, 20);

    // Display the modified doubly linked list
    displayList(myList);
    displayReverseList(myList);

    // Free the memory allocated for the doubly linked list
    freeList(&myList);

    return 0;
}
