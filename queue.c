#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    struct node *next;
    int num;
};
struct node *head = NULL;
struct node *tail = NULL;
void enqueue(int num){
    struct node *node;
    node = (struct node *)malloc(sizeof(struct node));
    if(head == NULL){
        head = node;
        tail = node;
        node->num = num;
        printf("%d",node->num);
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
    node->num = num;
}
int dequeue(){
    int num;
    if(tail == NULL) return 0;
    num = tail->num;
    tail = tail->prev;
    return num;
}
int main(int argc, char **argv){
    int i=0;
    int num;
    for(i=0; i<100;i++){
        enqueue(i);
    }
    while(1){
        if(tail == NULL)break;
        num = dequeue();
        printf("%d\n",num);
    }
    return 0;
}
