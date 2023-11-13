#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct QueueArray {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void initializeArrayQueue(struct QueueArray *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmptyArrayQueue(struct QueueArray *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFullArrayQueue(struct QueueArray *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueueArrayQueue(struct QueueArray *queue, int value) {
    if (isFullArrayQueue(queue)) {
        printf("Error: Queue is full. Cannot enqueue element.\n");
        return;
    }

    if (isEmptyArrayQueue(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->arr[queue->rear] = value;
    printf("Element %d enqueued into the queue.\n", value);
}

int dequeueArrayQueue(struct QueueArray *queue) {
    if (isEmptyArrayQueue(queue)) {
        printf("Error: Queue is empty. Cannot dequeue element.\n");
        return -1;  // Assuming -1 as an error value, modify as needed
    }

    int dequeuedValue = queue->arr[queue->front];

    if (queue->front == queue->rear) {
        // Last element in the queue
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    printf("Element %d dequeued from the queue.\n", dequeuedValue);
    return dequeuedValue;
}

int frontArrayQueue(struct QueueArray *queue) {
    if (isEmptyArrayQueue(queue)) {
        printf("Error: Queue is empty. Cannot get front element.\n");
        return -1;  // Assuming -1 as an error value, modify as needed
    }

    return queue->arr[queue->front];
}

int main() {
    struct QueueArray myArrayQueue;

    initializeArrayQueue(&myArrayQueue);

    enqueueArrayQueue(&myArrayQueue, 10);
    enqueueArrayQueue(&myArrayQueue, 20);
    enqueueArrayQueue(&myArrayQueue, 30);

    printf("Front element of the array queue: %d\n", frontArrayQueue(&myArrayQueue));

    dequeueArrayQueue(&myArrayQueue);
    dequeueArrayQueue(&myArrayQueue);

    printf("Is the array queue empty? %s\n", isEmptyArrayQueue(&myArrayQueue) ? "Yes" : "No");

    return 0;
}
