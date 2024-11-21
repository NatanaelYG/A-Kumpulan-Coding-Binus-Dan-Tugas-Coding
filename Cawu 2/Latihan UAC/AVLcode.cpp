#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

typedef struct Mixue {
    char id[10];
    char name[100];
    char type[50];
    char email[100];
    int quantity;
    int price;
    struct Mixue *left, *right;
    int height;
} Node;

Node *root = NULL;

Node *newMixue(char *id, char *name, char *type, char *email, int quantity, int price) {
    Node *mixue = (Node *)malloc(sizeof(Node));
    strcpy(mixue->id, id);
    strcpy(mixue->name, name);
    strcpy(mixue->type, type);
    strcpy(mixue->email, email);
    mixue->quantity = quantity;
    mixue->price = price;
    mixue->left = mixue->right = NULL;
    mixue->height = 1;
    return mixue;
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

Node *rightRotate(Node *x) {
    Node *y = x->left;
    Node *z = y->right;

    y->right = x;
    x->left = z;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *z = y->left;

    y->left = x;
    x->right = z;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node *checkBalance(Node *root) {
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && getBalance(root->left) > 0) {
        return rightRotate(root);
    }
    // Right Right
    if (balance < -1 && getBalance(root->right) < 0) {
        return leftRotate(root);
    }
    // Left Right
    if (balance > 1 && getBalance(root->left) <= 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left
    if (balance < -1 && getBalance(root->right) >= 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node *insert(Node *root, char *id, char *name, char *type, char *email, int quantity, int price) {
    if (!root) {
        return newMixue(id, name, type, email, quantity, price);
    }
    if (strcmp(id, root->id) < 0) {
        root->left = insert(root->left, id, name, type, email, quantity, price);
    } else if (strcmp(id, root->id) > 0) {
        root->right = insert(root->right, id, name, type, email, quantity, price);
    } else {
        return root;
    }

    return checkBalance(root);
}

bool checkName(char *name) {
    int len = strlen(name);
    int countWord = 0;
    int x = 0;

    for (int i = 0; i < len; i++) {
        if (name[i] == ' ') {
            x = 0;
        } else if (x == 0) {
            countWord++;
            x = 1;
        }
    }
    if(countWord < 2){
        return false;
    }
    return true;
}

bool checkUnique(Node *root, char *name){
    if(root && strcmp(name, root->name) == 0) return false;
    if(!checkUnique(root->left, name)) return false;
    if(!checkUnique(root->right, name)) return false;
    return true;
}

bool checkType(char *type) {
    return strcmp(type, "Ice Cream") == 0 || strcmp(type, "Milk Tea") == 0 || strcmp(type, "Fruit Tea") == 0;
}

bool checkEmail(char *email) {
    int len = strlen(email);
    int posA = 0;
    int posB = 0;

    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            if ((email[i - 1] >= 'a' && email[i - 1] <= 'z') && (email[i + 1] >= 'a' && email[i + 1] <= 'z')) {
                posA = i;
            } else {
                return false;
            }
        } else if (email[i] == '.' && i+4 = strlen(email)) {
            char com[5] = {email[i + 1], email[i + 2], email[i + 3]};
            if (strcmp(com, "com") == 0 && posB == 0) {
                posB = i;
            } else {
                return false;
            }
        }
    }
    return posA < posB && posA != 0 && posB != 0;
}

void addMixue() {
    char name[100];
    do {
        printf("Product Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while (!checkName(name));

    char type[50];
    do {
        printf("Product Type: ");
        scanf("%[^\n]", type);
        getchar();
    } while (!checkType(type));

    char email[100];
    do {
        printf("Email: ");
        scanf("%s", email);
        getchar();
    } while (!checkEmail(email));

    int quantity;
    do {
        printf("Quantity: ");
        scanf("%d", &quantity);
        getchar();
    } while (quantity < 1);

    int price;
    if (strcmp(type, "Ice Cream") == 0) {
        price = 15000 * quantity;
    } else if (strcmp(type, "Milk Tea") == 0) {
        price = 20000 * quantity;
    } else if (strcmp(type, "Fruit Tea") == 0) {
        price = 25000 * quantity;
    }

    char id[10];  
    int a = rand() % 10;
    int b = rand() % 10;
    int c = rand() % 10;

    if (strcmp(type, "Ice Cream") == 0) {
        sprintf(id, "IC%d%d%d", a, b, c);
    } else if (strcmp(type, "Milk Tea") == 0) {
        sprintf(id, "MT%d%d%d", a, b, c);
    } else if (strcmp(type, "Fruit Tea") == 0) {
        sprintf(id, "FT%d%d%d", a, b, c);
    }

    root = insert(root, id, name, type, email, quantity, price);
}

void printMixue(Node *root) {
    if (root) {
        printMixue(root->left);
        printf("%s: %s\n", root->id, root->name);
        printMixue(root->right);
    }
}

Node *search(Node *root, char id[]){
    if(!root) return NULL;
    if(strcmp(id, root->id) < 0){
        return search(root->left, id);
    }
    if(strcmp(id, root->id) > 0){
        return search(root->right, id);
    }

    return root;
}

void updateMenu(){
    printMixue(root);
    char id[10];
    printf("Enter ID: ");
    scanf("%s", id);
    getchar();
    Node *key = search(root, id);
    if(!key){
        printf("ID not found!\n");
        return;
    }

    char name[100];
    do{
        printf("Product Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while(!checkName(name));

    strcpy(key->name, name);
}

Node *del(Node *root, char id[]){
    if(!root) return NULL;
    else if(strcmp(id, root->id) < 0) root->left = del(root->left, id);
    else if(strcmp(id, root->id) > 0) root->right = del(root->right, id);
    else {
        if(!root->left && !root->right){
            free(root);
            return NULL;
        } else if (!root->left || !root->right){
            Node *child;
            if(root->left) child = root->left;
            else root->right;

            free(root);
            return child;
        } else {
            Node *successor = root->right;
            while(successor->left){
                successor = successor->left;
            }
            strcpy(root->id, successor->id);
            strcpy(root->name, successor->name);
            strcpy(root->type, successor->type);
            strcpy(root->email, successor->email);
            root->quantity = successor->quantity;
            root->price = successor->price;

            root->right = del(root->right, successor->id);
        }
    }

    return checkBalance(root);
}

void deleteMenu(){
    printMixue(root);
    char id[10];
    printf("Input ID: ");
    scanf("%s", id);
    getchar();
    root = del(root, id);
}

bool checkEmpty(){
    if(!root){
        printf("\nThere are no transaction\n");
        return true;
    } 
    return false;
}

void mainMenu() {
    while (true) {
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. View\n");
        printf("5. Exit\n");

        int a;

        do {
            printf(">> ");
            scanf("%d", &a);
            getchar();
        } while (a < 1 || a > 5);

        if (a == 1) {
            addMixue();
        } else if (a == 2) {
            if(checkEmpty()) continue;
            updateMenu();
        } else if (a == 3) {
            deleteMenu();
        } else if (a == 4) {
            printMixue(root);
        } else if (a == 5) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    mainMenu();
    return 0;
}
