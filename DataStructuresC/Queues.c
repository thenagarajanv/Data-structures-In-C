// Basic Queues
#include <stdio.h>
#include <stdlib.h>

#define N 10
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int x) {
    if (rear == N - 1) {
        printf("Queue is Full\n");
    } else if (rear == -1 && front == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        queue[++rear] = x;
    }
}
void dequeue() {
    if (front == rear) {
        front = rear = -1;
    } else if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        int y = queue[front];
        front++;
        printf("Deleted : %d\n", y);
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d -> ", queue[i]);
        }
        printf(" End\n");
    }
}

int main() {
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}

