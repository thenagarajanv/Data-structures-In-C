// Circular Queue
#include <stdio.h>
#define N 10
int queue[N];
int front = -1;
int rear = -1;

void cenque(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[front] = x;
    } else if (front == (rear + 1) % N) {
        printf("Queue is Full\n");
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}
void cdeque() {
    if (front == -1 && rear == -1) {
        printf("queue is empty\n");
    } else if (front == rear) {
        front = rear = -1;
    } else {
        printf("Deleted : %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is : ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d \n", queue[rear]);
    }
}

int main() {
    cenque(4);
    cenque(2);
    cenque(1);
    cenque(9);
    display();
    cdeque();
    display();
}

