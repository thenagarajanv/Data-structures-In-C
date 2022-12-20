//Stack in C
#include <stdio.h>
#include <stdlib.h>
#define N 10
int top = -1;
int stack[N];

void push(int x){
    if(top == N-1){
        printf("Stack is Full\n");
    }else{
        stack[++top] = x;
    }
}

void pop(){
    if(top == -1){
        printf("Stack is Empty\n");
    }else{
        int x = stack[top];
        top--;
        printf("Deleted : %d\n",x);
    }
}

void display(){
    for(int i = 0; i < top+1; i++){
        printf("%d -> ",stack[i]);
    }
    printf("End\n");
}
int main(){
    push(3);
    push(1);
    push(9);
    push(4);
    push(5);
    display();
    pop();
    display();
    return 0;
}
