#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 11

typedef struct data{
    char *name;
    char *type;
    int duration;
    struct data *next;
}data;

data *table[SIZE] = {NULL};

data *createNode(char* name, char* type, int duration){
    data *node = (data*)malloc(sizeof(data));
    node->name = strdup(name);
    node->type = strdup(type);
    node->duration = duration;
    node->next = NULL;
    return node;
}

int hash(char* name){
    int sum = 0;
    for(int i = 0;i < strlen(name); i++){
        sum += name[i];
    }
    return sum % SIZE;
}


data *insert(data *curr, int key){
    if(!head[key]){
        table[key] = curr; 
    } else {
        data *temp = table[key];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = curr;
    }
}

void popValue(char* name, int key){
    data *curr = table[key];
    if(strcmp(curr->name, name) == 0){
        table[key] = table[key]->next;
        free(curr);
        return;
    } while (curr->next != NULL){
        if(strcmp(curr->name, name) == 0){
            if(curr->next == NULL){
                free(curr);
            } else {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return;
    }
}

void addMenu(){
    char *name = (char*)malloc(50);
    char *type = (char*)malloc(10);
    int duration;
    puts("");

    do{
        printf("Input Vehicle Name: ");
        scanf("%[^\n]", name); getchar();
    } while(strlen(name) <= 0);

    do {
        printf("Input Vehicle type [SUV,Sedan,Hatchback]: ");
        scanf("%[^\n]", type); getchar();
    } while(strcmp(type, "SUV") != 0 && strcmp(type, "Sedan") != 0 && strcmp(type, "Hatchback") != 0);

    do {
        printf("Input Duration: ");
        scanf("%d", &duration); getchar();
    } while(duration <= 0);
    int key = hash(name);
    insert(createNode(name,type,duration), key);
}

void remove(){
    char *target = (char*)malloc(50);
    do{
        printf("Input Vehicle Name to Deleted: ");
        scanf("%s", target);
    } while(target == NULL);
    popValue(target, hash(target));
    puts("Successfully deleted a menu\n");
}

data *node(char* name){
    data *node = (data*)malloc(sizeof(data));
    node= table[hash(name)];
    while(node){
        if(strcmp(node->name, name) == 0){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void updates(){
    char *target = (char*)malloc(10);
    do{
        printf("Input Vehicle Name to Update: ");
        scanf("%s", target); getchar();
    } while(target == NULL);
    data *upt = node(target);

    char *name = (char*)malloc(50);
    char *type = (char*)malloc(10);
    int duration;
    puts("");

    do {
        printf("Input Duration: ");
        scanf("%d", &duration); getchar();
    } while(duration <= 0);
    
    upt->duration = duration;
    puts("Successfully deleted a menu\n");
}

void viewAll(){
    data *curr;
    for(int i = 0; i < SIZE;i++){
        curr = table[i];
        while(curr){
            printf("Vehicle Name: %s\nVehicle Type: %s\nDuration: %d\n", curr->name,curr->type,curr->duration);
            curr = curr->next;
        }
    }
}

void displayMenu(int *menu){
    printf("\n\n==========================\n");
    printf("     NeLson's Garage\n");
    printf("==========================\n");
    puts("");

    viewAll();
    puts("");

    printf("1. Insert New Vehicle\n");
    printf("2. View All Vehicle\n");
    printf("3. Remove\n");
    printf("4. Update Storage Duration\n");
    printf("5. Exit\n");
    printf(">> ");
    scanf("%d", &*menu);
    getchar();
}

int main(){
    int menu;   
    do{
        displayMenu(&menu);
        if(menu == 1){
            addMenu();
        } else if(menu == 2){
            viewAll();
        } else if(menu == 3){
            remove();
        } else if(menu == 4){
            updates();
        }
    } while (menu != 5);
}