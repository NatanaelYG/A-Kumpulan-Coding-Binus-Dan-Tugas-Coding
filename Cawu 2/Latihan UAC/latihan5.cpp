#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct list{
    char nik[15];
    char name[30];
    char email[30];
    int height;
    struct list *left, *right;
} node;

node *root = NULL;

node *createNode(char *nik, char *name, char *email){
    node *Newlist = (node*)malloc(sizeof(node));
    strcpy(Newlist->nik, nik);
    strcpy(Newlist->name, name);
    strcpy(Newlist->email, email);
    Newlist->height = 1;
    Newlist->left = Newlist->right = NULL;

    return Newlist;
}

int findMax(int a, int b){
    return (a > b) ? a : b;
}

int getHeight(node *root){
    return (root) ? root->height : 0;
}

int getBf(node *root){
    return (root) ? getHeight(root->left) - getHeight(root->right) : 0;
}

void updateHeight(node *root){
    root->height = findMax(getHeight(root->left), getHeight(root->right)) + 1;
}

node *leftRotate(node *root){
    node *right = root->right;
    node *rightleft = right->left;

    root->right = rightleft;
    right->left = root;

    updateHeight(root);
    updateHeight(right);

    return right;
}

node *rightRotate(node *root){
    node *left = root->left;
    node *leftright = left->right;

    root->left = leftright;
    left->right = root;

    updateHeight(root);
    updateHeight(left);

    return left;
}

node *balancing(node *root){
    if(!root) return NULL;

    updateHeight(root);

    int bf = getBf(root);

    if(bf > 1){
        if(getBf(root->left) < 0) root->left = leftRotate(root->left);
        root = rightRotate(root);
    } else if(bf < -1){
        if(getBf(root->right) > 0) root->right = rightRotate(root->right);
        root = leftRotate(root);
    }

    return root;
}

node *searching(char *nik, node *root){
    if(!root) return NULL;
    else if(strcmp(nik, root->nik) < 0) return searching(nik, root->left);
    else if(strcmp(nik, root->nik) > 0) return searching(nik, root->right);
    return root;
}

node *insertion(char *nik, char *name, char *email, node *root){
    if(!root) return createNode(nik, name, email);
    else if(strcmp(nik, root->nik) < 0) root->left = insertion(nik, name, email, root->left);
    else if(strcmp(nik, root->nik) > 0) root->right = insertion(nik, name, email, root->right);
    return balancing(root);
}

node *del(char *nik, node *root){
    if(!root) return NULL;
    if(strcmp(nik, root->nik) < 0) root->left = del(nik, root->left);
    else if(strcmp(nik, root->nik) > 0) root->right = del(nik, root->right);
    else {
        if(!root->left && !root->right){
            free(root);
            return NULL;
        } else if(!root->left){
            node *temp = root->right;
            free(root);
            return temp;
        } else if(!root->right) {
            node *temp = root->left;
            free(root);
            return temp;
        } else {
            node *temp = root->left;
            while(temp->right) temp = temp->right;
            strcpy(root->name, temp->name);
            strcpy(root->nik, temp->nik);
            strcpy(root->email, temp->email);
            root->left = del(temp->nik, root->left);
        }
    }
    return balancing(root);
}

void PrintList(node *root){
    if(root){
        PrintList(root->left);
        printf("%-5s %-5s %-5s\n", root->nik, root->name, root->email);
        PrintList(root->right);
    }
}

bool checkName(char *name){
    int len = strlen(name);
    return len >= 2;
}

bool checkEmail(char *email){
    int len = strlen(email);
    return len >= 2;
}

void updateMenu(){
    char nik[15];
    printf("Input nik To Update: ");
    scanf("%[^\n]", nik);
    getchar();

    node *key = searching(nik, root);
    if(!key){
        printf("NIK Tidak Ada\n");
        return;
    }

    char name[30];
    char email[30];

    do{
        printf("Input New Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while(!checkName(name));

    do{
        printf("Input New Email: ");
        scanf("%[^\n]", email);
        getchar();
    } while(!checkEmail(email));

    root = del(nik, root);
    root = insertion(nik, name, email, root);
}

void addList(){
    char nik[15];
    char name[30];
    char email[30];

    do{
        printf("Input New Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while(!checkName(name));

    do{
        printf("Input New Email: ");
        scanf("%[^\n]", email);
        getchar();
    } while(!checkEmail(email));

    int a = rand() % 10;
    int b = rand() % 10;
    int c = rand() % 10;

    sprintf(nik, "JPO%d%d%d", a, b, c);

    root = insertion(nik, name, email, root);
}

void deleteMenu(){
    char nik[15];
    printf("Input Nik to delete: ");
    scanf("%[^\n]", nik);
    getchar();

    node *key = searching(nik, root);
    if(!key){
        printf("NIK Tidak Ada\n");
        return;
    }

    root = del(nik, root);
}

void MainMenu(){
    int a;
    do{
        printf("Menu:\n");
        printf("1. AddList\n");
        printf("2. Print List\n");
        printf("3. Delete\n");
        printf("4. Update\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &a);
        getchar();

        if(a == 1){
            addList();
        } else if(a == 2){
            PrintList(root);
        } else if(a == 3){
            deleteMenu();
        } else if(a == 4){
            updateMenu();
        } else if(a == 0){
            break;
        }
    } while(a >= 0 && a <= 4);
}

int main(){
    srand(time(NULL));
    MainMenu();
    return 0;
}
