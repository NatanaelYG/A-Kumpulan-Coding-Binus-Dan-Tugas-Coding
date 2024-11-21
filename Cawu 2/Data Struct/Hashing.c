#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

// Buat penampung Data
typedef struct {
    char *key;
    char *name;
    char *number;
    char *email;
    int filled; //indikasi array index-i  udah terisi
} Node;

// Fungsi hash dengan metode Mid square dan Division
int hash(const char *key) {
    int hash = 0;
    int i;
    for (i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % MAX;
}

// Fungsi untuk membuat node baru
Node *createNode(const char *key, char *name, char *number, char *email) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->name = strdup(name);
    newNode->number = strdup(number);
    newNode->email = strdup(email);
    newNode->filled = 1;
    return newNode;
}

// Fungsi untuk menambah data ke hash table
void insert(Node ht[], const char *key, char *name, char *number, char *email) {
    int index = hash(key);
    int original_index = index;

    while (ht[index].filled == 1) { //ngecek apakah ada variable filled
        //index += 1
        index = (index + 1) % MAX;

        if (index == original_index) {
            fprintf(stderr, "Hash table is full\n");
            exit(1);
        }
    }

    Node *newNode = createNode(key, name, number, email);
    ht[index] = *newNode;
}

// Fungsi untuk mencari data berdasarkan key
int search(Node ht[], const char *key) {
    int index = hash(key);
    int original_index = index;

    while (ht[index].filled == 1) {
        if (strcmp(ht[index].key, key) == 0) {
            if (ht[index].key != NULL) {
                printf("Data Found!\n");
                printf("Name: %s\n", ht[index].name);
                printf("Number: %s\n", ht[index].number);
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

        if (index == original_index || ht[index].filled == 0) {
            printf("Key not found\n");
            return -1;
        }
    }
    printf("Key not found\n");
    return -1;
}

// Fungsi untuk menghapus data berdasarkan key
void delete(Node ht[], const char *key) {
    int index = hash(key);
    int original_index = index;

    while (ht[index].filled == 1) {
        if (strcmp(ht[index].key, key) == 0) {
            free(ht[index].key);
            free(ht[index].name);
            free(ht[index].number);
            free(ht[index].email);
            ht[index].key = NULL;
            ht[index].name = NULL;
            ht[index].number = NULL;
            ht[index].email = NULL;
            ht[index].filled = 0;
            printf("Deletion success\n");

            int next_index = (index + 1) % MAX;
            while (ht[next_index].filled == 1 && hash(ht[next_index].key) != original_index) {
                ht[index] = ht[next_index];

                ht[next_index].key = NULL;
                ht[next_index].name = NULL;
                ht[next_index].number = NULL;
                ht[next_index].email = NULL;
                ht[next_index].filled = 0;

                index = next_index;
                next_index = (next_index + 1) % MAX;
            }
            return;
        }
        index = (index + 1) % MAX;

        if (index == original_index || ht[index].filled == 0) {
            printf("Key not found for deletion\n");
            return;
        }
    }

    printf("Key not found for deletion\n");
}

int main() {
    Node ht[MAX] = {0}; //inisialisasi hash table dengan tipe data Node (struct yg kita buat diatas)

    insert(ht, "magic", "Donald", "0877737233", "donald@email.com");
    insert(ht, "makro", "Luffy", "0882730287", "luffy@email.com");
    insert(ht, "distro", "Aslan", "08843340287", "aslan@email.com");
    search(ht, "magic");
    search(ht, "makro");
    search(ht, "distro");
    delete(ht, "magic");
    search(ht, "magic");

    return 0;
}

