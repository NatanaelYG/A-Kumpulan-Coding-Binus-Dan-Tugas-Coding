#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct List{
    char Title[35];
    char Singer[35];
    char Type[15];
    struct List *left, *right;
    int height;
} Node;

Node *root = NULL;

int sum = 0;

Node *newList(char *Title, char *Singer, char *Type){
    Node *list = (Node*)malloc(sizeof(Node));
    strcpy(list->Title, Title);
    strcpy(list->Singer, Singer);
    strcpy(list->Type, Type);
    list->left = list->right = NULL;
    list->height = 1;
    return list;
}

int height(Node *root){
    if(!root){
        return 0;
    }
    return root->height;
}

int max(int a, int b){
    return a > b ? a : b;
}

int getBalance(Node *root){
    if(!root){
        return 0;
    }
    return height(root->left) - height(root->right);
}

Node *rightRotate(Node *x){
    Node *y = x->left;
    Node *z = y->right;

    y->right = x;
    x->left = z;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node *leftRotate(Node *x){
    Node *y = x->right;
    Node *z = y->left;

    y->left = x;
    x->right = z;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node *checkBalance(Node *root){
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    //Left Left
    if(balance > 1 && getBalance(root->left) > 0) {
        return rightRotate(root);
    }

    //Right Right 
    if (balance < -1 && getBalance(root->right) < 0) {
        return leftRotate(root);
    }

    //Left Right
    if (balance > 1 && getBalance(root->left) <= 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //Right Left
    if (balance < -1 && getBalance(root->right) >= 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node *insert(Node *root, char *Title, char *Singer, char *Type) {
    if (!root) {
        return newList(Title, Singer, Type);
    } 

    if (strcmp(Title, root->Title) < 0) {
        root->left = insert(root->left, Title, Singer, Type);
    } else if(strcmp(Title, root->Title) > 0) {
        root->right = insert(root->right, Title, Singer, Type);
    } else {
        return root;
    }

    return checkBalance(root);
}

bool checkTitle(char *Title){
    int len = strlen(Title);

    if (len < 3 || len > 30){
        return false;
    }
    return true;
}

bool checkSinger(char *Singer){
    int len = strlen(Singer);

    if (len < 3 || len > 30){
        return false;
    } 
    return true;
}

bool checkType(char *Type) {
    if (!(strcmp(Type, "jazz") == 0 || strcmp(Type, "pop") == 0 || strcmp(Type, "rock") == 0)){
        return false;
    }
    return true;
}

void addList() {
    char Title[35];
    do {
        printf("Title: ");
        scanf("%[^\n]", Title);
        getchar();
    } while(!checkTitle(Title));

    char Singer[35];
    do {
        printf("Singer: ");
        scanf("%[^\n]", Singer);
        getchar();
    } while(!checkSinger(Singer));

    char Type[15];
    do {
        printf("Type [pop, jazz, rock]: ");
        scanf("%[^\n]", Type);
    } while(!checkType(Type));

    root = insert(root, Title, Singer, Type);
    sum++;
} 

void printList(Node *root){
    if (root) {
        printList(root->left);
        printf(" %d. | %s                          | %s                                   | %s\n", sum, root->Title, root->Singer, root->Type);
        printList(root->right);
    }
}

Node *search(Node *root, char Title[]){
    if(!root) return NULL;
    if(strcmp(Title, root->Title) < 0){
        return search(root->left, Title);
    } 
    if(strcmp(Title, root->Title) > 0){
        return search(root->right, Title);
    }

    return root;
}

Node *del(Node *root, char Title[]){
    if(!root) return NULL;
    else if(strcmp(Title, root->Title) < 0) root->left = del(root->left, Title);
    else if(strcmp(Title, root->Title) > 0) root->right = del(root->right, Title);

    else {
        if(!root->left && !root->right) {
            free(root);
            return NULL;
        } else if (!root->left || !root->right) {
            Node *child;
            if(root->left) child = root->left;
            else root->right;

            free(root);
            return child;
        } else {
            Node *successor = root->right;
            while(successor->left) {
                successor = successor->left;
            }
            strcpy(root->Title, successor->Title);
            strcpy(root->Singer, successor->Singer);
            strcpy(root->Type, successor->Type);

            root->right = del(root->right, successor->Title);
        }
    }

    return checkBalance(root);
}

void deleteMenu(){
    printList(root);
    char Title[35];
    printf("Input Title: ");
    scanf("%s", Title);
    getchar();
    root = del(root, Title);
    sum--;
}

bool checkEmpty(){
    if(!root){
        printf("\nNothing Data\n");
        return true;
    }
    return false;
}

void mainMenu(){
    while(true) {
        printf("Music List (printed in preorder)\n");
        printf("================================\n");
        printf("No. | Title                          | Singer                                | Type     \n");
        printf("----------------------------------------------------------------------------------------\n");
        printList(root);
        checkEmpty();
        printf("Menu\n");
        printf("1. Add Data\n");
        printf("2. Delete Data\n");
        printf("3. Exit\n");

        int a;

        do{
            printf(">> ");
            scanf("%d", &a);
            getchar();
        } while (a < 1 || a > 3);
        
        if (a == 1) {
            addList();
        } else if (a == 2) {
            if(checkEmpty()) continue;
            deleteMenu();
        } else if(a == 3){
            break;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}