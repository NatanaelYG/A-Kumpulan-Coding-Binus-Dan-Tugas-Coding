#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *left, *right;
	int height;
} Node;

Node *root = NULL;

Node *createNode (int value) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

int findMax (int a, int b) {
	return (a > b) ? a : b;
}

int getHeight (Node *curr) {
	return (curr) ? curr->height : 0;
}

int getBf (Node *curr) {
	return (curr) ? getHeight(curr->left) - getHeight(curr->right) : 0;
}

void updateHeight (Node *curr) {
	curr->height = findMax(getHeight(curr->left), getHeight(curr->right)) + 1;
}

Node *leftRotate (Node *curr) {
	Node *right = curr->right;
	Node *rightLeft = right->left;
	
	curr->right = rightLeft;
	right->left = curr;
	
	updateHeight(curr);
	updateHeight(right);
	
	return right;
}

Node *rightRotate (Node *curr) {
	Node *left = curr->left;
	Node *leftRight = left->right;
	
	curr->left = leftRight;
	left->right = curr;
	
	updateHeight(curr);
	updateHeight(left);

	return left;
}

Node *balancing (Node *curr) {
	if (!curr) return NULL;
	
	updateHeight(curr);
	
	int bf = getBf(curr);
	
	if (bf > 1) {
		if (getBf(curr->left) < 0) curr->left = leftRotate(curr->left);
		curr = rightRotate(curr);
	} else if (bf < -1) {
		if (getBf(curr->right) > 0) curr->right = rightRotate(curr->right);
		curr = leftRotate(curr);
	}
	
	return curr;
}

Node *insertion (int value, Node *curr) {
	if (!curr) return createNode(value);
	else if (value < curr->value) curr->left = insertion(value, curr->left);
	else if (value > curr->value) curr->right = insertion(value, curr->right);
	return balancing(curr);
}

void preOrder (Node *curr) {
	if (curr) {
		printf("%d ", curr->value, curr->height);
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void inOrder(Node *curr){
	if (curr) {
		inOrder(curr->left);
		printf("%d ", curr->value, curr->height);
		inOrder(curr->right);
	}
}

Node *searching (int value, Node *curr) {
	if (!curr) return NULL;
	else if (value < curr->value) return searching(value, curr->left);
	else if (value > curr->value) return searching(value, curr->right);
	return curr;
}

Node *deletion (int value, Node *curr) {
	if (!curr) return NULL;
	else if (value < curr->value) curr->left = deletion(value, curr->left);
	else if (value > curr->value ) curr->right = deletion(value, curr->right);
	else {
		if (!curr->left && !curr->right) {
			free(curr);
			curr = NULL;
		} else if (!curr->left || !curr->right) {
			Node *temp = curr->left ? curr->left : curr->right;
			free(curr);
			*curr = *temp;
			free(temp);
			temp = NULL;
		} else {
			Node *temp = curr->left;
			while (temp->right) temp = temp->right;
			curr->value = temp->value;
			curr->left = deletion(temp->value, curr->left);
		}
	}
	
	return balancing(curr);
}

int main(){
	root = insertion(5, root);
	root = insertion(10, root);
	root = insertion(13, root);
	root = insertion(12, root);
	root = insertion(9, root);
	root = insertion(6, root);
	
	Node *value = searching(10, root);
	if (value) {
		printf("Value %d found!\n", value->value);
	} else {
		puts("Not found.");
	}
	
	inOrder(root);
	
	return 0;
}
