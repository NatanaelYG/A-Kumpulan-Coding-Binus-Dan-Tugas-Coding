#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List {
    char title[35];
    char singer[35];
    char type[10];
    int height;
    struct List *left, *right;
} Node;

Node *root = NULL;

Node *createNode(char *title, char *singer, char *type) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->title, title);
    strcpy(newNode->singer, singer);
    strcpy(newNode->type, type);
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node *root) {
    return (root) ? root->height : 0;
}

int getBf(Node *root) {
    return (root) ? getHeight(root->left) - getHeight(root->right) : 0;
}

void updateHeight(Node *root) {
    root->height = findMax(getHeight(root->left), getHeight(root->right)) + 1;
}

Node *leftRotate(Node *root) {
    Node *right = root->right;
    Node *rightleft = right->left;

    root->right = rightleft;
    right->left = root;

    updateHeight(root);
    updateHeight(right);

    return right;
}

Node *rightRotate(Node *root) {
    Node *left = root->left;
    Node *leftright = left->right;

    root->left = leftright;
    left->right = root;

    updateHeight(root);
    updateHeight(left);

    return left;
}

Node *balancing(Node *root) {
    if (!root) return NULL;

    updateHeight(root);

    int bf = getBf(root);

    if (bf > 1) {
        if (getBf(root->left) < 0) root->left = leftRotate(root->left);
        root = rightRotate(root);
    } else if (bf < -1) {
        if (getBf(root->right) > 0) root->right = rightRotate(root->right);
        root = leftRotate(root);
    }

    return root;
}

Node *insertion(char *title, char *singer, char *type, Node *root) {
    if (!root) return createNode(title, singer, type);
    else if (strcmp(title, root->title) < 0) root->left = insertion(title, singer, type, root->left);
    else if (strcmp(title, root->title) > 0) root->right = insertion(title, singer, type, root->right);
    return balancing(root);
}

void printList(Node *root) {
    if (root) {
        printf("%-35s | %-35s | %-10s\n", root->title, root->singer, root->type);
        printList(root->left);
        printList(root->right);
    }
}

Node *searching(char *title, Node *root) {
    if (!root) return NULL;
    else if (strcmp(title, root->title) < 0) return searching(title, root->left);
    else if (strcmp(title, root->title) > 0) return searching(title, root->right);
    return root;
}

Node *deletion(char *title, Node *root) {
    if (!root) return NULL;
    if (strcmp(title, root->title) < 0) root->left = deletion(title, root->left);
    else if (strcmp(title, root->title) > 0) root->right = deletion(title, root->right);
    else {
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        } else if (!root->left) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Node *temp = root->left;
            free(root);
            return temp;
        } else {
            Node *temp = root->left;
            while (temp->right) temp = temp->right;
            strcpy(root->title, temp->title);
            strcpy(root->singer, temp->singer);
            strcpy(root->type, temp->type);
            root->left = deletion(temp->title, root->left);
        }
    }
    return balancing(root);
}

bool checkTitle(char *title) {
    int len = strlen(title);
    return len >= 3 && len <= 35;
}

bool checkSinger(char *singer) {
    int len = strlen(singer);
    return len >= 3 && len <= 35;
}

void addList() {
    char title[35];
    do {
        printf("Input Title: ");
        scanf("%[^\n]", title);
        getchar();
    } while (!checkTitle(title));

    char singer[35];
    do {
        printf("Input Singer: ");
        scanf("%[^\n]", singer);
        getchar();
    } while (!checkSinger(singer));

    char type[10];
    do {
        printf("Input Type [pop, jazz, rock]: ");
        scanf("%[^\n]", type);
        getchar();
    } while (!(strcmp(type, "pop") == 0 || strcmp(type, "jazz") == 0 || strcmp(type, "rock") == 0));

    root = insertion(title, singer, type, root);
}

void deleteMenu() {
    printList(root);
    char title[35];
    printf("Input Title to Delete: ");
    scanf("%[^\n]", title);
    getchar();
    root = deletion(title, root);
}

void mainMenu() {
    while (true) {
        int choice;

        do {
            printf("Music List (printed in preorder)\n");
            printf("================================\n");
            printf("No. | Title                         | Singer                   | Type \n");
            printList(root);
            printf("\nMenu\n");
            printf("1. Add Data\n");
            printf("2. Delete Data\n");
            printf("3. Exit\n");
            printf("Input choice: ");
            scanf("%d", &choice);
            getchar();
        } while (choice < 1 || choice > 3);

        if (choice == 1) {
            addList();
        } else if (choice == 2) {
            deleteMenu();
        } else if (choice == 3) {
            break;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
