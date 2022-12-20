
#include <stdio.h>
#include <stdlib.h>

#define N 10
int s1[N];
int s2[N];
int top1 = -1;
int top2 = -1;
int count = 0;

void push1(int x) {
    if (top1 == N - 1) {
        printf("stack is full\n");
    } else {
        s1[++top1] = x;
    }
}

void push2(int x) {
    if (top2 == N - 1) {
        printf("stack is full\n");
    } else {
        s2[++top2] = x;
    }
}

int pop1() {
    return s1[--top1];
}

int pop2() {
    return s2[--top2];
}

void display() {
    for (int i = 0; i <= top1; i++) {
        printf("%d -> ", s1[i]);
    }
    printf("End\n");
}

void enqueue(int x) {
    push1(x);
    count++;
}

void dequeu() {
    int a, b, i;
    if (top1 == -1 && top2 == -1) {
        printf("Stack is Empty");
    } else {
        for (i = 0; i < count; i++) {
            a = pop1();
            push2(a);
        }
        b = pop2();
        printf("Deleted from stack : %d\n", b);
        count--;
        for (i = 0; i < count; i++) {
            a = pop2();
            push1(a);
        }
    }
}

int main() {
    enqueue(2);
    enqueue(6);
    enqueue(4);
    enqueue(12);
    enqueue(21);
    display();
    dequeu();
    dequeu();
    dequeu();
    dequeu();
    dequeu();
    display();
}