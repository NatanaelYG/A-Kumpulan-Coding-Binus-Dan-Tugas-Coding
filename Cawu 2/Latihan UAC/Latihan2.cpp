#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Bar {
    double key;
    char name[50];
    char type[50];
    int quantity;
    struct Bar *left, *right;
    int height;
} Node;

Node *root = NULL;

Node *newBar(char *name, char *type, int quantity) {
    Node *bar = (Node *)malloc(sizeof(Node));
    strcpy(bar->name, name);
    strcpy(bar->type, type);
    bar->quantity = quantity;
    bar->left = bar->right = NULL;
    bar->height = 1;
    
    return bar;
}

int height(Node *root) {
    if (!root) {
        return 0;
    }
    return root->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getBalance(Node *root) {
    if (!root) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *checkBalance(Node *root) {
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);

    // Left left
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left right
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right right
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right left
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *insert(Node *root, char *name, char *type, int quantity) {
    if (!root) {
        return newBar(name, type, quantity);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, type, quantity);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, type, quantity);
    } else {
        return root;
    }

    return checkBalance(root);
}

int findKey(char *name) {
    int len = strlen(name);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += name[i];
    }
    return ((sum + 122) * 3) % 100;
}

bool checkName(char *name) {
    int len = strlen(name);
    return len >= 3 && len <= 40;
}

bool checkType(char *type) {
    int len = strlen(type);
    return len >= 3 && len <= 40;
}

bool checkQuantity(int quantity) {
    return quantity > 0;
}

void addBar() {
    char name[50];
    do {
        printf("Input Item Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while (!checkName(name));

    char type[50];
    do {
        printf("Input Item Type: ");
        scanf("%[^\n]", type);
        getchar();
    } while (!checkType(type));

    int quantity;
    do {
        printf("Input Quantity: ");
        scanf("%d", &quantity);
        getchar();
    } while (!checkQuantity(quantity));

    root = insert(root, name, type, quantity);
}

void printBar(Node *root) {
    if (root) {
        printBar(root->left);
        printf("%d  %s         %s            %d\n", findKey(root->name), root->name, root->type, root->quantity);
        printBar(root->right);
    }
}

Node *search(Node *root, char name[]) {
    if (!root) return NULL;
    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    }
    if (strcmp(name, root->name) > 0) {
        return search(root->right, name);
    }
    return root;
}

void request(Node *root) {
    char name[50];
    int quantity;
    printBar(root);
    printf("Name want to request: ");
    scanf("%[^\n]", name);
    getchar();
    
    Node *key = search(root, name);
    if (!key) {
        printf("Item not found\n");
        return;
    }

    printf("How much want to request: ");
    scanf("%d", &quantity);
    getchar();

    if (key->quantity < quantity) {
        printf("Insufficient quantity\n");
    } else {
        key->quantity -= quantity;
    }
}

void addStock(Node *root) {
    char name[50];
    int quantity;
    printBar(root);
    printf("Name want to add stock: ");
    scanf("%[^\n]", name);
    getchar();
    
    Node *key = search(root, name);
    if (!key) {
        printf("Item not found\n");
        return;
    }

    printf("How much want to add: ");
    scanf("%d", &quantity);
    getchar();

    key->quantity += quantity;
}

Node *del(Node *root, char name[]) {
    if (!root) return NULL;
    if (strcmp(name, root->name) < 0) root->left = del(root->left, name);
    else if (strcmp(name, root->name) > 0) root->right = del(root->right, name);
    else {
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        } else if (!root->left || !root->right) {
            Node *child = root->left ? root->left : root->right;
            free(root);
            return child;
        } else {
            Node *successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            strcpy(root->name, successor->name);
            strcpy(root->type, successor->type);
            root->quantity = successor->quantity;
            root->right = del(root->right, successor->name);
        }
    }
    return checkBalance(root);
}

void deleteMenu() {
    printBar(root);
    char name[50];
    printf("Input Item Name to delete: ");
    scanf("%[^\n]", name);
    getchar();
    root = del(root, name);
}

bool checkEmpty() {
    if (!root) {
        printf("\nNo Data\n");
        return true;
    }
    return false;
}

void mainMenu() {
    while (1) {
        printf("Menu\n");
        printf("1. Input new items\n");
        printf("2. List of items\n");
        printf("3. Request items\n");
        printf("4. Add stock\n");
        printf("5. Delete item\n");
        printf("6. Exit\n");

        int choice;
        do {
            printf(">> ");
            scanf("%d", &choice);
            getchar();
        } while (choice < 1 || choice > 6);

        if (choice == 1) {
            addBar();
        } else if (choice == 2) {
            printf("Item List\n");
            printf("==========================================\n");
            printf("ID  Name         Type         Quantity\n");
            printf("------------------------------------------\n");
            printBar(root);
        } else if (choice == 3) {
            request(root);
        } else if (choice == 4) {
            addStock(root);
        } else if (choice == 5) {
            if (checkEmpty()) continue;
            deleteMenu();
        } else if (choice == 6) {
            break;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}