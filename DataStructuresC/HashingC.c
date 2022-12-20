// Linear Probing
#include <stdio.h>
#define table 10
int h[table] = {NULL};
void insert(){
    int key, hkey, index, i;
    printf("Enter hashmap key: \n");
    scanf("%d",&key);
    hkey = key % table;
    for(i = 0;i < table; i++){
        index = (hkey+i*i)%table;
        if(h[index] == NULL){
            h[index] = key;
            break;
        }
    }
    if(table == i){
        printf("Element cannot be inserted\n");
    }
}

void search(){
    int key, hkey, index, i;
    printf("Enter element to be Searched : \n");
    scanf("%d",&key);
    hkey = key % table;
    for(i = 0; i < table; i++){
        index = (hkey+i*i)%table;
        if(h[index] == key){
            printf("Element is Found %d",index);
            break;
        }
    }
    if(i == table){
        printf("Element cannot be inserted\n");
    }
}

void display(){
    int i;
    printf("\nElements in the Hash Table are \n");
    for(i = 0;i < table; i++){
        printf("index = %d\tvalue = %d\n",i,h[i]);
    }
}
int main(){
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
}