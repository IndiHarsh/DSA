#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent the list
struct List {
    int array[MAX_SIZE];
    int size;
};

// Function to initialize the list
void initializeList(struct List *list) {
    list->size = 0;
}

// Function to display the elements of the list
void displayList(struct List *list) {
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

// Function to insert an element at the end of the list
void insertElement(struct List *list, int value) {
    if (list->size == MAX_SIZE) {
        printf("Error: List is full. Cannot insert element.\n");
        return;
    }

    list->array[list->size++] = value;
    printf("Element %d inserted successfully.\n", value);
}

// Function to delete an element from the list
void deleteElement(struct List *list, int value) {
    if (list->size == 0) {
        printf("Error: List is empty. Cannot delete element.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->array[i] == value) {
            found = 1;

            // Shift elements to fill the gap
            for (int j = i; j < list->size - 1; j++) {
                list->array[j] = list->array[j + 1];
            }

            list->size--;
            printf("Element %d deleted successfully.\n", value);
            break;
        }
    }

    if (!found) {
        printf("Error: Element %d not found in the list.\n", value);
    }
}

int main() {
    struct List myList;

    // Initialize the list
    initializeList(&myList);

    // Insert elements into the list
    insertElement(&myList, 10);
    insertElement(&myList, 20);
    insertElement(&myList, 30);

    // Display the list
    displayList(&myList);

    // Delete an element from the list
    deleteElement(&myList, 20);

    // Display the modified list
    displayList(&myList);

    return 0;
}
