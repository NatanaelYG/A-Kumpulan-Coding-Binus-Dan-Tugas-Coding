#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct tnode{
    char data;
    struct tnode *left;
    struct tnode *right;
};

// Function to check if a character is an operator
int is_operator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to create a newnode
struct tnode* newnode(char data){
    struct tnode *temp = (struct tnode*) malloc(sizeof(tnode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to construct the tree from prefix expression
void construct_tree(struct tnode **curr, char s[], int *p){
    if(is_operator(s[*p])){
        *p = *p + 1;
        (*curr)->left = newnode(s[*p]);
        construct_tree(&((*curr)->left), s, p);
        *p = *p + 1;
        (*curr)->right = newnode(s[*p]);
        construct_tree(&((*curr)->right), s, p);
    }
}

int evaluateExpressionTree(struct tnode* root){
    if (root->data == '+') {
        return evaluateExpressionTree(root->left) 
        + evaluateExpressionTree(root->right);
    } else if (root->data == '-') {
        return evaluateExpressionTree(root->left) 
        - evaluateExpressionTree(root->right);
    } else if (root->data == '*') {
        return evaluateExpressionTree(root->left) 
        * evaluateExpressionTree(root->right);
    } else if (root->data == '/') {
        return evaluateExpressionTree(root->left) 
        / evaluateExpressionTree(root->right);
    } else if (root->data == '^') {
        return pow(evaluateExpressionTree(root->left) 
        , evaluateExpressionTree(root->right));
    } else {
        return root->data - '0'; // Convert character to integer
    }
}

void preorder(struct tnode *root){
    if(root != NULL){
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct tnode *root){
    if(root != NULL){
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void postorder(struct tnode *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

void freeExpressionTree(struct tnode* root){
    if(root != NULL){
        freeExpressionTree(root->left);
        freeExpressionTree(root->right);
        free(root);
    }
}

int main(){
    char prefix_expression[] = "+*41/42";

    int pos = 0;

    struct tnode *root = newnode(prefix_expression[pos]);
    construct_tree(&root, prefix_expression, &pos);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    int result = evaluateExpressionTree(root);
    printf("Result: %d\n", result);

    freeExpressionTree(root);

}