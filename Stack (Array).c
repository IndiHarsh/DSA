#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct StackArray {
    int arr[MAX_SIZE];
    int top;
};

void initializeArrayStack(struct StackArray *stack) {
    stack->top = -1;
}

int isFullArrayStack(struct StackArray *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmptyArrayStack(struct StackArray *stack) {
    return stack->top == -1;
}

void pushArrayStack(struct StackArray *stack, int value) {
    if (isFullArrayStack(stack)) {
        printf("Error: Stack overflow. Cannot push element.\n");
        return;
    }

    stack->arr[++stack->top] = value;
    printf("Element %d pushed onto the stack.\n", value);
}

int popArrayStack(struct StackArray *stack) {
    if (isEmptyArrayStack(stack)) {
        printf("Error: Stack underflow. Cannot pop element.\n");
        return -1;  // Assuming -1 as an error value, modify as needed
    }

    int poppedValue = stack->arr[stack->top--];
    printf("Element %d popped from the stack.\n", poppedValue);
    return poppedValue;
}

int peekArrayStack(struct StackArray *stack) {
    if (isEmptyArrayStack(stack)) {
        printf("Error: Stack is empty. Cannot peek.\n");
        return -1;  // Assuming -1 as an error value, modify as needed
    }

    return stack->arr[stack->top];
}

int main() {
    struct StackArray myArrayStack;

    initializeArrayStack(&myArrayStack);

    pushArrayStack(&myArrayStack, 10);
    pushArrayStack(&myArrayStack, 20);
    pushArrayStack(&myArrayStack, 30);

    printf("Top element of the array stack: %d\n", peekArrayStack(&myArrayStack));

    popArrayStack(&myArrayStack);
    popArrayStack(&myArrayStack);

    printf("Is the array stack empty? %s\n", isEmptyArrayStack(&myArrayStack) ? "Yes" : "No");

    return 0;
}
