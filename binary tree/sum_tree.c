#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;


node* newNode(int data); // create new node
node* insert(node* root, int val); // insertion
void inOrder(node* root); // DFS traversal  (Depth-First Traversal)
void preOrder(node* root); // DFS traversal (Depth-First Traversal)
void postOrder(node* root); // DFS traversal (Depth-First Traversal)
int sum(node* root); // sum of elements in bst
bool isSumTree(node* root); // check if bst in sumtree or not


int main() {
	
    node* root = NULL;

    root = insert(root, 10);
    insert(root, 30);
    insert(root, 25);
    insert(root, 36);
    insert(root, 56);
    insert(root, 78);
    insert(root, 6);
    insert(root, 7);
    insert(root, 5);

    
    printf("Inorder traversal : ");
    inOrder(root);
    printf("\n");
    
	bool isSum = isSumTree(root);
	
	if(isSum==true){
		printf("the BST is a sumtree");
	}else{
		printf("the BST is not a sumtree");
	}
    
    printf("\n");
    
    
    return 0;
}

node* newNode(int data) {
	node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* insert(node* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

void inOrder(node* root){
	
	if(root != NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
		
}

void preOrder(node* root){
	
	if(root != NULL){
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
	
}

void postOrder(node* root){
	
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ",root->data);
	}
	
}

int sum(node* root){
	
	if(root == NULL){
		return 0;
	}
	
	return root->data + sum(root->left) + sum(root->right);	
}

bool isSumTree(node* root){
	
	if(root == NULL ||(root->left == NULL && root->right == NULL))
        return true;
        
	int sumleft = sum(root->left);
	int sumright = sum(root->right);

	if(root->data == (sumleft+sumright) && isSumTree(root->left) && isSumTree(root->right)){
		return true;
	}
	
	return false;
}

