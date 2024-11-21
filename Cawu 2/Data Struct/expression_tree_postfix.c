#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

//Create new node
struct TreeNode* createNode(char value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

//Operator check
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to build an expression tree from a postfix expression
struct TreeNode* buildExpressionTree(char postfix[]) {
    struct TreeNode* stack[100];
    int top = -1;
	int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        struct TreeNode* newNode = createNode(postfix[i]);

        if (isdigit(postfix[i])) {
            stack[++top] = newNode;
        } else if (isOperator(postfix[i])) {
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }

    return stack[top];
}

// Function to evaluate the expression tree
int evaluateExpressionTree(struct TreeNode* root) {
    if (root->data == '+') {
        return evaluateExpressionTree(root->left) + evaluateExpressionTree(root->right);
    } else if (root->data == '-') {
        return evaluateExpressionTree(root->left) - evaluateExpressionTree(root->right);
    } else if (root->data == '*') {
        return evaluateExpressionTree(root->left) * evaluateExpressionTree(root->right);
    } else if (root->data == '/') {
        return evaluateExpressionTree(root->left) / evaluateExpressionTree(root->right);
    } else {
        return root->data - '0'; // Convert character to integer
    }
}

// Function to perform in-order traversal of the expression tree
void inOrderTraversal(struct TreeNode* root) {
	
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c ", root->data);
        inOrderTraversal(root->right);
    }
    
}

void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
    	printf("%c ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c ", root->data);
    }
}


// Function to free the memory allocated for the expression tree
void freeExpressionTree(struct TreeNode* root) {
    if (root != NULL) {
        freeExpressionTree(root->left);
        freeExpressionTree(root->right);
        free(root);
    }
}

int main() {
    char postfixExpression[]="457*+62/-";
    
    //input example 457*+62/-
    
    // Input postfix expression
//    printf("Enter a postfix expression: ");
//    scanf("%s", postfixExpression);

    // Build the expression tree
    struct TreeNode* root = buildExpressionTree(postfixExpression);

    // Display the in-order traversal of the expression tree
    printf("In-order Traversal of the Expression Tree: ");
    inOrderTraversal(root);
    printf("\n");
	
	
	printf("Pre-order Traversal of the Expression Tree: ");
	preOrderTraversal(root);
	printf("\n");
	
	
	printf("Post-order Traversal of the Expression Tree: ");
	postOrderTraversal(root);
	printf("\n");
    // Evaluate and display the result
    int result = evaluateExpressionTree(root);
    printf("Result: %d\n", result);

    // Free allocated memory
    freeExpressionTree(root);

    return 0;
}