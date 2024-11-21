#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if the queue is full
int isFull() {
    return (rear == MAX_SIZE - 1);
}

// Function to enqueue an element into the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue overflow. Cannot enqueue %d.\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear] = value;
    printf("%d enqueued into the queue.\n", value);
}

// Function to dequeue an element from the front of the queue
int dequeue() {
    int dequeuedValue;

    if (isEmpty()) {
        printf("Queue underflow. Cannot dequeue from an empty queue.\n");
        return -1; // Signifies an error condition
    }

    dequeuedValue = queue[front];

    if (front == rear) {
        // Reset front and rear to -1 if the last element is dequeued
        front = rear = -1;
    } else {
        front++;
    }

    return dequeuedValue;
}

// Function to display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    
	int i;
    printf("Elements in the queue: ");
    for (i = front; i <= rear; ++i) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(55);
    enqueue(35);
    enqueue(100);

    display();

    printf("Dequeued element: %d\n", dequeue());

    display();

    return 0;
}

