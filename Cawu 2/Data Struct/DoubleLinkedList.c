#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int valueNode;
    struct tnode *next;
    struct tnode *prev;
}*h,*t,*c;

void pushHead(int value)
{
    c = (struct tnode*) malloc(sizeof(struct tnode));
    c->valueNode = value;
    c->next = NULL;
    c->prev = NULL;
    if(!h){
        h=t=c;
    }else{
        c->next = h;
        h->prev = c;
        h = c;
    }
}

void pushTail(int value){
    c = (struct tnode*) malloc(sizeof(struct tnode));
    c->valueNode = value;
    c->next = NULL;
    c->prev = NULL;
    if(!h){
        h=t=c;
    }
    else{
        t->next = c;
        c->prev = t;
        t=c;
    }
}

void pushMiddle(int value){
    c = (struct tnode*) malloc(sizeof(struct tnode));
    c->valueNode = value;
    c->next = NULL;
    c->prev = NULL;
    if(!h){
        h=t=c;
    }
    else if (h->valueNode > value){
        c->next = h;
        h->prev = c;
        h = c;
    }
    else if (t->valueNode < value){
        t->next = c;
        c->prev = t;
        t=c;
    }
    else{
        struct tnode *temp;
        temp = h;
        while(value > temp->next->valueNode)
            temp=temp->next;
        c->next = temp->next;
        temp->next->prev = c;
        c->prev = temp;
        temp->next = c;
    }
}

void PrintallNext(){
    struct tnode *temp = h;
    while (temp!=NULL){
        printf("%d ", temp->valueNode);
        temp=temp->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    pushMiddle(1);
    pushMiddle(4);
    pushMiddle(2);
    pushMiddle(3);
    pushMiddle(6);
    pushMiddle(5);
    
    return 0;
}
