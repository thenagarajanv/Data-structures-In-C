//Singly Circular Lnkedlist
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;
node *tail = NULL;


void insertAtBegin(int x){
    node *n = (node*) malloc(sizeof (node));
    n->next = NULL;
    n->data = x;
    if(head == NULL){
        head = tail = n;
    }else{
        n->next = head;
        head = n;
        tail->next = head;
    }
}

void insertAtEnd(int x){
    node *n = (node*) malloc(sizeof(node));
    n->data = x;
    n->next = NULL;
    if(head == NULL){
        head = tail = n;
        n->next = n;
    }else{
        tail->next = n;
        tail = n;
        n->next = head;
    }
}

void insertAtPos(int x, int pos){
    int i = 0;
    node *t, *ihead;
    node *n = (node*) malloc(sizeof(node));
    n->next = NULL;
    n->data = x;
    if(pos == 0){
        insertAtBegin(x);
    }else{
        for(i = 1, ihead = head; ihead != NULL && i < pos-1; i++,ihead = ihead->next){
            if(ihead->next == head){
                insertAtEnd(x);
            }
            t = ihead->next;
            ihead->next = n;
            n->next = t;
        }
    }
}

void deleteBegin(){
    if(head == NULL){
        printf("No element\n");
    }else if(head == tail){
        head = tail = NULL;
    }else{
        node *t = head;
        head = head->next;
        tail->next = head;
        free(t);
    }
}

void deleteEnd(){
    node *current, *prev;
    current = tail->next;
    if(tail == 0){
        printf("NO element\n");
    }else if(current->next == current){
        tail = 0;
        free(current);
    }else{
        while(current->next != tail->next){
            prev = current;
            current = current->next;
        }
        prev->next = tail->next;
        tail = prev;
        free(current);
    }
}
void display(){
    node *temp;
    temp = tail->next;
    while(temp->next != tail->next){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("%d -> End\n", temp->data);
}

void deletePos(int pos){
    node *current, *nextnode;
    int i = 1;
    current = tail->next;
    if(tail == 0){
        printf("invalid position\n");
    }else if(pos == 1){
        deleteBegin();
    }else{
        while(i < pos-1){
            current = current->next;
            i++;
        }
        nextnode = current->next;
        current->next = nextnode->next;
        free(nextnode);
    }
}
int getlength(){
    int size = 1;
    node * temp = head;
    while(temp->next != tail->next){
        size++;
        temp = temp->next;
    }
    return size;
}
int main(){
    insertAtBegin(1);
    insertAtBegin(2);
    insertAtBegin(3);
    insertAtEnd(4);
    insertAtEnd(5);
    display();
    deleteEnd();
    display();
    deleteBegin();
    display();
    printf("Size of the linkedlist is : %d\n",getlength());
    deletePos(4);
    display();
    return 0;
}
//Doubly LinkedList

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head = NULL;
node *tail = NULL;

void insertBegin(int x){
    node* n = (node*) malloc(sizeof (node));
    n->next = NULL;
    n->prev = NULL;
    n->data = x;
    if(head == NULL){
        head = tail = n;
    }else{
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void insertEnd(int x){
    node *n = (node*) malloc(sizeof(node));
    n->prev = NULL;
    n->next = NULL;
    n->data = x;
    if(head == NULL){
        head = tail = n;
    }else{
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

void insertPos(int x, int pos){
    node *n = (node*) malloc(sizeof(node));
    n->prev = NULL;
    n->next = NULL;
    n->data = x;
    int i = 1;
    if(pos == 1){
        insertBegin(x);
    }else{
        node *temp = head;
        while(i < pos-1){
            temp = temp->next;
            i++;
        }
        n->prev = temp;
        n->next = temp->next;
        temp->next = n;
        n->next->prev = n;
    }
}

void display(){
    node *t = head;
    while(t->next != NULL){
        printf("%d -> ",t->data);
        t = t->next;
    }
    printf("%d -> End",t->data);
}
int main() {
    insertBegin(2);
    insertBegin(4);
    insertBegin(8);
    insertEnd(32);
    insertEnd(12);
    insertEnd(92);
    insertPos(23, 5);
    display();
}
