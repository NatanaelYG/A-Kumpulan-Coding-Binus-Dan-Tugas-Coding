#include <stdio.h>
#include <stdlib.h>

struct node {
    int valueNode;
    struct node *next;
    struct node *prev;
}*h, *t, *c;

void pushMiddle(int value){
    c= (struct node*) malloc(sizeof(struct node));
    c->valueNode = value;
    c->next = NULL;
    c->prev = NULL;
    if(!h){
        h=t=c;
    } else if(h->valueNode > value){
        c->next = h;
        h->prev = c;
        h = c;
    } else if(t->valueNode < value){
        t->next = c;
        c->prev = t;
        t = c;
    } else {
        struct node *temp;
        temp = h;
        while(value > temp->next->valueNode)
            temp = temp->next;
        c->next = temp->next;
        temp->next->prev = c;
        c->prev = temp;
        temp->next = c;
    }
}


void popHead(){
	if(h == NULL) return;
	struct node *temp = h;
	h = h->next;
	free(temp);
}

void popTail(){
	if (t == NULL) return;
	struct node *temp = h;
	
	while (temp->next->valueNode != t->valueNode){
        temp = temp->next;
        if(temp == NULL)
            break;
    } 
    t = temp;
    struct node *curr;
    curr = temp->next;
    temp->next = NULL;
    free(curr);
}

void popMiddle(int value){
    if (h == NULL) return;

    struct node *temp = h;

    while (temp->valueNode != value){
        temp = temp->next;
        if(temp == NULL)
            break;
    }

    if  (temp == NULL) return;

    if(temp->valueNode == h->valueNode){
        h = h->next;
        h->prev = NULL;
        temp->next = NULL;
        free(temp);
    } 

    else if (temp->valueNode == t->valueNode){
        struct node *temp2 = h;
        while (temp2->next->valueNode != t->valueNode){
            temp2 = temp2->next;
        }
        temp2->next = NULL;
        t = temp2;
        temp2 = temp2->next;
        t->next = NULL;
        free(temp);
    }

    else {
        struct node *temp2 = h;
        while (temp2->next->valueNode != temp->valueNode){
            temp2 = temp2->next;
        }

        //struct node *curr;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
    }
}

void PrintAllNext(){
    struct node *temp = h;
    while (temp != NULL){
        printf("%d ", temp->valueNode);
        temp = temp->next;
    }
    printf("\n");
}

void PrintAllPrev(){
	struct node *temp = t;
	while(temp != NULL){
		printf("%d ", temp->valueNode);
		temp = temp->prev;
	}
	printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    pushMiddle(3);
    pushMiddle(5);
    pushMiddle(9);
    pushMiddle(1);
    PrintAllNext();
    popMiddle(3);
    PrintAllNext();
    
    return 0;
}
