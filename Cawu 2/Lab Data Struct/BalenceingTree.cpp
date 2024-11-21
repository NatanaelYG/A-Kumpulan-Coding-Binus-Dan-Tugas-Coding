//AVL = SELF BALANCING TREE DARI SEBUAH BINARY TREE.
//BALANCE FACTOR
//semua leaf = root = height = 1; //sebenernya bebas height nya mau brp.
// Bandingin sama value terbesar dr leaf nya dan +1 jika dia leaf.
//anak kanan- kiri -> jika hasilnya positif  maka dia berat kiri. 
//anak kanan-kiri -> jika hasilnya negatif, maka dia berat ke kanan.

#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	node *left, *right;
	int height;
} *root = NULL;

struct node *createNode(int value){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	newNode->height = 1;
	
	return newNode;
}

int max(int a, int b){ // untuk mendapatkan nilai max dari si leafnya.
	if(a > b) return a;
	return b;
}

int getHeight(struct node* root){ // untuk mencari leaf di kanan dan kirinya
	if(!root) return 0;
	return root->height;
}

int getBF(struct node* root){
	if(!root){
		return 0;
	} 
	
	return getHeight(root->left) - getHeight(root->right);
}

struct node* rightRotate(node* A){
	node* B = A->left;
	node* C = B->right;
	
	B->right = A;
	A->left = C;
	
	A->height =  max(getHeight(A->left),  getHeight(A->right)) + 1; //untuk update nilai max nya setelah dirubah treenya. 
	B->height =  max(getHeight(B->left),  getHeight(B->right)) + 1;
	
	return B;
}

struct node* leftRotate(node* A){
	node* B = A->right;
	node* C = B->left;
	
	B->left = A;
	A->right = C;
	
	A->height =  max(getHeight(A->left),  getHeight(A->right)) + 1;
	B->height =  max(getHeight(B->left),  getHeight(B->right)) + 1;
	
	return B;
}


struct node* insert(node *root, int value){
	//Masih insert BST.
	if(!root){
		return createNode(value);
	} else if(value < root->value){
		root->left = insert(root->left, value);
	} else if(value > root->value){
		root->right = insert(root->right, value);
	}
	//TAMBAHAN UNTUK AVL dengan cara menghitung height yg baru.
	
	root->height = max(getHeight(root->left),  getHeight(root->right)) + 1; 
	
	int bf = getBF(root);
	if(bf > 1 ){ //BERAT KIRI -> POSITIF
	//untuk mencari dia berat kanan atau kiri dengan cara positif dan negatif. 
	//pake syarat bf > 1, karena jika bf = 1 maka dia sudah balance. Sehingga tdk bisa bf > 0.
		if(getBF(root->left) > 0){ //jika anaknya berat kiri juga.
			root = rightRotate(root);
		}else{
			root->left = leftRotate(root->left);
			root = rightRotate(root);
		}
	} else if(bf < -1){ //BERAT KANAN -> NEGATIF
		if(getBF(root->right) < 0){ //jika anaknya berat kanan juga.
			root = leftRotate(root);
		}else{
			root->right = rightRotate(root->right);
			root = leftRotate(root);
		}
	}
	return root;
}

int main(){
	
	return 0;
}
