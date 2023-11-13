#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node* temp = front;
        printf("Data dequeued is %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}

void display() {
    struct node* temp = front;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int m;
    do {
        printf("1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
        scanf("%d", &m);
        switch (m) {
            case 1:
                int x;
                printf("Enter number to be enqueued: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (m != 4);

    // Free any remaining nodes in the queue
    while (front != NULL) {
        struct node* temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}
