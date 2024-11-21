#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#define SIZE 11

typedef struct Data{
    const char *id;
    char *chef;
    char *name;
    int price;
    double ranting;
    struct Data *next;
}Data;

Data *table[SIZE] = {NULL};


Data *createNode(const char* id, char* chef,char* name,  int price, double rating){
    Data *node = (Data*)malloc(sizeof(Data));
    node->id = strdup(id);
    node->name = strdup(name);
    node->chef = strdup(chef);
    node->price = price;
    node->ranting = rating;

    node->next = NULL;
    return node;
}

int hash(const char* id){
    int x = id[0] + id [1] + id[2];
    return x % SIZE;
}

void push(Data *curr, int key){
    if(!table[key]){
        table[key] = curr;
    } else {
        Data *temp = table[key];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = curr;
    }
}

int idUnique(char const *id){
    for(int i = 0;i < SIZE; i++){
        Data *curr = table[i];
        while(curr) {
            if(strcmp(id, curr->id) == 0){
                return 0;
            }
            curr = curr->next;
        }
    }
    return 1;
}

int isEmpty(){
    for(int i = 0; i < SIZE; i++){
        if(table[i] != NULL) return 0;
    }
    puts("No menu yet..\n");
    return 1;
}

int isValid_chef(char *chef){
    if(strcmp(chef + strlen(chef) - 5, "@chef") == 0 && strcmp(chef, "@chef") != 0){
        return 1;
    } else return 0;
}

int isValid_name(char *name){
    int word = 0, i = 0;
    while(name[i] != '\0'){
        while(name[i] == ' ') i++;
        if(name[i] != '\0') word++;
        while(name[i] != '\0' && name[i] != ' ') i++;
        if(word > 2) break;
    }

    if(word == 2)return 1;
    else return 0;
}


void addMenu(){
    char *id = (char*)malloc(4);
    char *chef = (char*)malloc(50);
    char *name = (char*)malloc(50);
    int price, rating;
    puts("");

    do{
        printf("Chef Name: ");
        scanf("%[^\n]", chef);
        getchar();
    } while(isValid_chef(chef) == 0);

    do{
        printf("Menu Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while(isValid_name(name) == 0);

    do{
        printf("Menu Price: ");
        scanf("%d", &price);
        getchar();
    } while(price <= 0);

    do{
        printf("Menu Ranting: ");
        scanf("%d", &rating);
        getchar();
    } while(rating < 0 || rating > 5);

    do{
        sprintf(id, "%03d", rand() % 100);
    } while(!idUnique(id));
    int key = hash(id);
    push(createNode(id, chef, name, price, rating), key);
    puts("Successfully added a menu!\n");
}

void popValue(const char* id, int key){
    Data *curr = table[key];
    if(strcmp(curr->id, id) == 0){
        table[key] = table[key]->next;
        free(curr);
        return;
    }
    while(curr->next != NULL){
        if(strcmp(curr->id, id) == 0){
            if(curr->next == NULL){
                free(curr);
            } else {
                curr->next = curr->next->next;
                free(curr->next);
            }
            curr = curr->next;
        }
        return;
    }
}

void deleteMenu(){
    char *target = (char*)malloc(4);
    do {
        printf("Choose Menu ID to delete: ");
        scanf("%s", target); getchar();
        if(idUnique(target)) puts("Menu doesn't exist...\n");
    } while(idUnique(target));
    popValue(target, hash(target));
    puts("Successfully deleted a menu\n");
}

Data *node(const char* id){
    Data *node = (Data*)malloc(sizeof(Data));
    node = table[hash(id)];
    while(node){
        if(strcmp(node->id, id) == 0){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void update(){
    char *target = (char*)malloc(4);
    do {
        printf("Choose Menu Id to update: ");
        scanf("%s", target); getchar();
        if(idUnique(target)) puts("Menu doesn't exist...\n");
    } while(idUnique(target));
    Data *upt = node(target);

    char *id = (char*)malloc(4);
    char *chef = (char*)malloc(50);
    char *name = (char*)malloc(50);
    int price, rating;
    puts("");

    do{
        printf("Chef Name: ");
        scanf("%[^\n]", chef);
        getchar();
    } while(isValid_chef(chef) == 0);

    do{
        printf("Menu Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while(isValid_name(name) == 0);

    do{
        printf("Menu Price: ");
        scanf("%d", &price);
        getchar();
    } while(price <= 0);

    do{
        printf("Menu Ranting: ");
        scanf("%d", &rating);
        getchar();
    } while(rating < 0 || rating > 5);
    upt->chef = strdup(chef);
    upt->name = strdup(name);
    upt->price = price;
    upt->ranting = rating;
}

void displayMenu(int *menu){
    printf("================================\n");
    printf("SUNIB Restaurant Menu Database\n");
    printf("================================\n");
    printf("1. Add a menu\n");
    printf("2. View all menu\n");
    printf("3. Delete a menu\n");
    printf("4. Update a menu\n");
    printf("5. Exit\n");
    printf(">> ");
    scanf("%d", &*menu);
    getchar();
}

void viewAll(){
    printf("================================\n");
    printf("SUNIB Restaurant Menu Database\n");
    printf("================================\n");
    Data *curr;
    for(int i = 0; i < SIZE; i++){
        curr = table[i];
        while(curr){
            printf("Menu ID: %s\nChef Name: %s\nMenu Name: %s\nMenu Price: %d\nMenu Rating: %.1lf\n", curr->id, curr->chef, curr->name, curr->price, curr->ranting);
            curr = curr->next;
        }
    }
}

int main(){
    srand(time(NULL));
    int menu;
    while(true){
        displayMenu(&menu);
        if(menu == 1){
            addMenu();
        } else if(menu == 2){
            if(!isEmpty()){
                viewAll();
            }
            printf("Press to return to main menu..."); getchar();
            system("cls");
        } else if(menu == 3){
            if(!isEmpty()){
                viewAll();
                deleteMenu();
            }
            printf("Press to return to main menu..."); getchar();
            system("cls");
        } else if (menu == 4) {
            if(!isEmpty()){
                viewAll();
                update();
            }
            printf("Press to return to main menu..."); getchar();
            system("cls");
        }
        else if(menu == 5){
            puts("Program is finished, all database is deleted...");
            break;
        } else {
            puts("Invalid Menu!\n");
        }
    }
}