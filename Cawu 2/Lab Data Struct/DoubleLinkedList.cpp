#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Menu{
    char name[100];
    char type[100];
    int price;
    Menu *next, *prev;
};

Menu *createMenu(const char *name, const char *type, const int price){
    Menu *menu = (Menu*)malloc(sizeof(Menu));
    strcpy(menu->name, name);
    strcpy(menu->type, type);
    menu->price = price;
    menu->next = menu->prev = NULL;
    return menu;
}

void pushHead(Menu **head, Menu **tail, Menu *menu){
    if(!*head){
        *head = *tail = menu;
        return;
    }
    menu->next = *head;
    (*head)->prev = menu;
    *head = menu;
}

void pushTail(Menu **head, Menu **tail, Menu *menu){
    if(!*head){
        *head = *tail = menu;
        return;
    } 
    menu->prev = *tail;
    (*tail)->next = menu;
    *tail = menu;
}

void pushValue(Menu **head, Menu **tail, Menu *menu){
    if(!*head || strcmp(menu->name, (*head)->name) < 0){
        pushHead(head, tail, menu);
    } else if(strcmp(menu->name, (*head)->name) >= 0){
        pushHead(head, tail, menu);
        return;
    }
    Menu *temp = *head;
    while(strcmp(menu->name, temp->name) >= 0){
        temp = temp->next;
    }
    temp->prev->next = menu;
    menu->prev = temp->prev;
    menu->next = temp;
    temp->prev = menu;
}

void popHead(Menu **head, Menu **tail){
    if(*head == *tail){
        free(*head);
        *head =  *tail = NULL;
        return;
    }
    Menu *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
    temp = NULL;

    // *head = (*head)->next;
    // free((*head)->prev);
    // (*head)->prev = NULL;
}

void popTail(Menu **head, Menu **tail){
    if(*head == *tail){
        free(*head);
        *head =  *tail = NULL;
        return;
    }
    *tail = (*tail)->prev;
    free((*tail)->next);
    (*tail)->next = NULL;
}

void popValue(Menu **head, Menu **tail, const char *name){
    if(!*head){
        return;
    } 
    else if(strcmp((*head)->name, name) == 0){
        popHead(head, tail);
        return;
    } else if(strcmp((*tail)->name, name) == 0){
        popTail(head,tail);
        return;
    }
    Menu *temp = *head;
    while(temp != *tail && strcmp(temp->name, name) != 0){
        temp = temp->next;
    } 
    if(temp == *tail){
        printf("%s not found\n", name);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    temp = NULL;
}

void view(Menu *head){
    Menu *ptr = head;
    int no = 1;
    while(ptr){
        printf("%d. %-20s %-10s %d\n",no++, ptr->name,ptr->type,ptr->price);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

int main(){
    Menu *head = NULL, *tail = NULL;

    pushTail(&head, &tail, createMenu("Sate", "Food", 9000));
    pushHead(&head, &tail, createMenu("Indomie", "Food", 2000));
    pushHead(&head, &tail, createMenu("Bakso", "Food", 10000));
    pushValue(&head, &tail, createMenu("Es Doger", "Drink", 7000));
    pushTail(&head, &tail, createMenu("Es Jeruk", "Drink", 5000));
    
    view(head);
    printf("\nAfter PopHead\n");
    popHead(&head,&tail);
    view(head);
    printf("\nAfter PopTail\n");
    popTail(&head,&tail);
    view(head);
    printf("\nAfter popValue\n");
    popValue(&head,&tail,"Bakso");
    view(head);
    


    return 0;
}