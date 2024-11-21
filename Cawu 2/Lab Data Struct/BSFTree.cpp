// includee
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct definitionn
struct data{
    int value;
    char name[100];
    data *left, *right;
} *root = NULL;

// createNode thingy
data *createNode(int value, char name[]){
    data* node = (data*)malloc(sizeof(data));
    node->value = value;
    strcpy(node->name, name);
    node->left = node->right = NULL;

    return node;
}

// pushh
data *push(data *root, int value, char name[]){
    // klo root kosong brrti taro disitu
    if(!root){
        return createNode(value, name);
    }
    // klo value lbh kecil traverse ke kiri
    if(value < root->value){
        root->left = push(root->left, value, name);
    }
    // klo value lbh besar traverse ke kanan
    else if(value > root->value){
        root->right = push(root->right, value, name);
    }

    return root;
}

// traverse #1
void preOrder(data *root){
    if(!root) return;
    printf("%d %s\n", root->value, root->name);
    preOrder(root->left);
    preOrder(root->right);
}

// traverse #2
void inOrder(data *root){
    if(!root) return;
    inOrder(root->left);
    printf("%d %s\n", root->value, root->name);
    inOrder(root->right);
}

// traverse #3
void postOrder(data *root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d %s\n", root->value, root->name);
}

// update
void update(data* root, int value, char name[]){
    // klo root null artinya yg dicari ga ketemu
    if(!root){
        printf("Data not found!\n");
    }
    // klo yg dicari lbh kecil traverse ke kiri
    else if(value < root->value){
        update(root->left, value, name);
    }
    // klo yg dicari lbh besar traverse ke kanan
    else if(value > root->value){
        update(root->right, value, name);
    }
    // klo ketemuu
    else{
        //update hereeeeee
        strcpy(root->name, name);
    }
}

data *search(data* root, int value){
    if(!root){
        return NULL;
    } else if (value < root->value) {
        return search(root->left, value);
    } else if (value > root->value) {
        return search(root->right, value);
    } else {
        return root;
    }
}

data *deleted(data* root, int value){
    if(!root){
        printf("Data Not Found!!!\n");
        return NULL;
    } else if(value < root->value) {
        root->left = deleted(root->left, value);
    } else if(value > root->value) {
        root->right = deleted(root->right, value);
    } else {
        if(!root->left && !root->right){
            // not child
            free(root);
            return NULL;
        } else if(!root->left || !root->right){
            // one child
            data* child = root->left?root->left:root->right;
            free(root);
            return child;
        } else {
            // two child
            data* pred = root->left;
            // data* succ = root->right;
            //cari processor
            //while(pred->left)
            while(pred->right){
                // pred = pred->left;
                pred = pred->right;
            }
            root->value = pred->value;
            strcpy(root->name, pred->name);

            root->left = deleted(root->left, pred->value);
        }
    }
        return root;
}

data* deletedAll(data* root){
    if(!root) return NULL;
    root->left = deletedAll(root->left);
    root->right = deletedAll(root->right);
    free(root);
    return NULL;
}

int main(){
    root = push(root, 10, "Fred");
    root = push(root, 15, "Niel");
    root = push(root, 7, "BCA");
    root = push(root, 8, "Test");

    update(root, 10, "Augh");
    update(root, 13, "Test");

    // preOrder(root);
    inOrder(root);
    // postOrder(root);

    data *key = search(root, 10);
    if(key){
        printf("%s\n", key->name);
    } else {
        printf("Data not found!!");
    }

    root = deleted(root, 15);
    inOrder(root);

    root = deletedAll(root);
    inOrder(root);
    return 0;
}