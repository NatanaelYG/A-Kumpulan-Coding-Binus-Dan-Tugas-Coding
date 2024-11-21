#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Book{
    char id[6];
    char name[50];
    char des[50];
    int price;
    struct Book *left, *right;
    int height;
} Node;

Node *root = NULL;

bool isUpperCase(char a){
    return (a >= 'A' && a <= 'Z');
}

Node *createNode(const char* name,const char* des, int price) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    sprintf(newNode->id, "%c%c%d%d%d", 
    isUpperCase(name[0]) ? name[0] : name[0] - 32, 
    isUpperCase(name[1]) ? name[1] : name[1] - 32,
    rand() % 10,
    rand() % 10,
    rand() % 10
    );

    strcpy(newNode->name, name);
    strcpy(newNode->des, des);
    newNode->price = price;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

int findMax(int a, int b){
    return (a > b) ? a : b;
}

int getHeight(Node *curr){
    return (curr) ? curr->height : 0;
}

int getBalanceFactor(Node *curr){
    return getHeight(curr->left) - getHeight(curr->right);
}

void updateHeight(Node *curr){
    curr->height = findMax(getHeight(curr->left), getHeight(curr->right)) + 1;
}

Node *leftRotate(Node *curr){
    Node *right = curr->right;
    Node *rightleft = right->left;

    curr->right = rightleft;
    right->left = curr;

    return right;
}

Node *rightRotate(Node *curr){
    Node *left = curr->left;
    Node *leftright = left->right;

    curr->left = leftright;
    left->right = curr;

    return left;
}

Node *balancing(Node *curr){
    if(!curr){
        return NULL;
    } 

    updateHeight(curr);

    int bf = getBalanceFactor(curr);

    if(bf > 1){
        if(getBalanceFactor(curr->left) <= 0)
            curr->left = leftRotate(curr->left);
        curr = rightRotate(curr);
    } else if(bf < -1){
        if(getBalanceFactor(curr->right) >= 0){
            curr->right = rightRotate(curr->right);
        curr = leftRotate(curr);
        }
    }

    return curr;
}

Node *insert(Node *newNode, Node *curr = root) {
    if(!curr) return newNode;

    else if (strcmp(newNode->id, curr->id) < 0)
        curr->left = insert(newNode, curr->left);

    else if (strcmp(newNode->id, curr->id) > 0) 
        curr->right = insert(newNode, curr->right);

    return balancing(curr);
}

void inOrder(Node *curr = root){
    if(curr) {
        inOrder(curr->left);
        printf("ID : %s\nName : %s\nDescription : %s\nPrice : %d\nHeight : %d\n\n", curr->id, curr->name, curr->des, curr->price, curr->height);
        inOrder(curr->right);
    }
}

Node *searching(char id[], Node *curr = root) {
    if(!curr) return NULL;
    else if(strcmp(id, curr->id) < 0)
        return searching(id, curr->left);
    else if(strcmp(id, curr->id) > 0)
        return searching(id, curr->right);
    return balancing(curr);
}

Node *rem(char id[], Node *curr = root) {
    if(!curr){
        puts("Not Found");
        return NULL;
    }
    else if(strcmp(id, curr->id) < 0)
        curr->left = rem(id, curr->left);
    else if(strcmp(id,curr->id) > 0)
        curr->right = rem(id,curr->right);
    else {
        if(!curr->left && !curr->right){
            free(curr);
            curr = NULL;
        } else if (!curr->left || !curr->right) {
            Node *temp = (curr->left) ? curr->left : curr->right;
            *curr = *temp;
            free(temp);
            temp = NULL;
        } else {
            Node *successor = curr->right;
            while(successor->left) {
                successor = successor->left;
            }
            strcpy(curr->id, successor->id);
            strcpy(curr->name, successor->name);
            strcpy(curr->des, successor->des);
            curr->price = successor->price;
            curr->right = rem(successor->id, curr->right);
        }
    }

    return balancing(curr);
}

Node* popAll(Node *curr = root){
	// kaya postOrder TRAVESAL pake while jg gak masalah
	if(curr){
		curr->left = popAll(curr->left);
		curr->right = popAll(curr->right);
		free(curr);
		curr = NULL;
		return NULL;
	}
}

int main(){
    srand(time(NULL));

    root = insert(createNode("Harry potter", "buku ini bagus", 50000));
    root = insert(createNode("Harry", "bagus", 45000));
    root = insert(createNode("potter", "buku", 60000));
    root = insert(createNode("Naruto", "wibu", 90000));
    root = insert(createNode("mafud", "good", 20000));
    root = insert(createNode("jelly potter", "minuman", 10000));

    inOrder();

    printf("\nInput ID to search : ");
    char id[6];
    scanf("%[^\n]", id);
    getchar();

    Node *result = searching(id);
    if(result == NULL){
        printf("Not found.");
    } else {
        printf("ID : %s\nBook Name: %s\n\n", result->id, result->name);
    }

    printf("\nInput ID to delete : ");
    char idRem[6];
    scanf("%[^\n]", idRem);
    getchar();

    root = rem(idRem);

    inOrder();

    printf("Press Enter to Pop All");
    getchar();

    inOrder();

    return 0;
}