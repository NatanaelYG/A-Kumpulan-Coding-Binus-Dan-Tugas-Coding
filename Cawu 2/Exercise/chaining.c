#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    long long int *tlp;
    char *name;
    char *email;
    struct Node *next;
} Node;

int hash(long long int tlp) {    
    int hash = 0;
    int i;
    long long int squared = tlp*tlp;

    char *noTel;
    sprintf(noTel, "%lld", squared);

    char *hashString;

    int len = strlen(noTel);
    return hash % MAX;
}

Node *createNode(const char *tlp, char *name, char *email) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->tlp = strdup(tlp);
    newNode->name = strdup(name);
    newNode->email = strdup(email);
    newNode->next;
    return newNode;
}

void insert(Node ht[], const char *tlp, char *name, char *email) {
    int index = hash(tlp);
    int original_index = index;

    while (ht[index].next != NULL) {
        index = (index + 1) % MAX;

        if (index == original_index) {
            fprintf(stderr, "Hash table is full\n");
            exit(1);
        }
    }
    Node *newNode = createNode(tlp, name, email);
    ht[index] = *newNode;
}

int search(Node ht[], const char *tlp) {
    int index = hash(tlp);
    int original_index = index;

    while (ht[index].next != NULL) {
        if (strcmp(ht[index].tlp, tlp) == 0) {
            if (ht[index].tlp != NULL) {
                printf("Data Found!\n");
                printf("Number: %s\n", ht[index].tlp);
                printf("Name: %s\n", ht[index].name);
                printf("Email: %s\n", ht[index].email);
                printf("Index in Hash Table: %d\n", index);
                printf("\n");
                return 0;
            } else {
                printf("Data has been deleted\n");
                return -1;
            }
        }
        index = (index + 1) % MAX;

        if (index == original_index || ht[index].next == NULL) {
            printf("Key not found\n");
            return -1;
        }
    }
    printf("Key not found\n");
    return -1;
}

void printAll(Node ht[]){
    for(int i = 0; i < MAX; i++){
        if(ht[i].next != NULL){
            printf("Telepon: %s\n", ht[i].tlp);
            printf("Name: %s\n", ht[i].name);
            printf("Email: %s\n", ht[i].email);
            printf("Index in Hash Table: %d\n", i);
            printf("\n");
        }
    }
}

void delete(Node ht[], const char *tlp) {
    int index = hash(tlp);
    int original_index = index;

    while (ht[index].next != NULL) {
        if (strcmp(ht[index].tlp, tlp) == 0) {
            free(ht[index].tlp);
            free(ht[index].name);
            free(ht[index].email);
            ht[index].tlp = NULL;
            ht[index].name = NULL;
            ht[index].email = NULL;
            ht[index].next = NULL;
            printf("Deletion success\n");

            int next_index = (index + 1) % MAX;
            while (ht[next_index].next != NULL && hash(ht[next_index].tlp) != original_index) {
                ht[index] = ht[next_index];

                ht[next_index].tlp = NULL;
                ht[next_index].name = NULL;
                ht[next_index].email = NULL;
                ht[next_index].next = NULL;

                index = next_index;
                next_index = (next_index + 1) % MAX;
            }
            return;
        }
        index = (index + 1) % MAX;

        if (index == original_index || ht[index].next == NULL) {
            printf("Key not found for deletion\n");
            return;
        }
    }

    printf("Key not found for deletion\n");
}

int main() {
    Node ht[MAX] = {0}; //inisialisasi hash table dengan tipe data Node (struct yg kita buat diatas)

    insert(ht, "0877737233", "Donald", "donald@email.com");
    insert(ht, "0882730287", "Luffy", "luffy@email.com");
    insert(ht, "08843340287", "Aslan", "aslan@email.com");
    search(ht, "0877737233");
    search(ht, "08843340287");
    search(ht, "0882730287");
    printf("\n");
    printf("\n");
    delete(ht, "08843340287");
    printf("\n");
    printAll(ht);

    return 0;
}
