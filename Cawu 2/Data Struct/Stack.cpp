#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return (top == -1);
}

// Function to check if the stack is full
int isFull() {
    return (top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack overflow. Cannot push %d.\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed to the stack.\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1; // Signifies an error condition
    }
    return stack[top--];
}

// Function to display the elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements in the stack: ");
    for (int i = 0; i <= top; ++i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
	printf("\n");
    display();

    printf("Popped element: %d\n", pop());

    display();

    return 0;
}

