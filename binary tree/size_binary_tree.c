#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;


node* newNode(int data); // create new node
node* insertBST(node* root, int val); // insertion to binary tree
void inOrder(node* root); // DFS traversal  (Depth-First Traversal)
void preOrder(node* root); // DFS traversal (Depth-First Traversal)
void postOrder(node* root); // DFS traversal (Depth-First Traversal)
int size(node* root); // number of elements of binary tree

int main() {
	
    node* root = NULL;

    root = insertBST(root, 10);
    root = insertBST(root, 30);
    root = insertBST(root, 25);
    root = insertBST(root, 36);
    root = insertBST(root, 56);
    root = insertBST(root, 78);
    root = insertBST(root, 6);
    root = insertBST(root, 7);
    root = insertBST(root, 5);
    root = insertBST(root, 4);
    
    printf("Inorder traversal : ");
    inOrder(root);
    printf("\n");
    
    printf("Size of binary tree: %d",size(root));
    
    
    return 0;
}

node* newNode(int data){
	node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* insertBST(node* root, int val){
    if (root == NULL) {
        return newNode(val);
    }

    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else if (val > root->data) {
        root->right = insertBST(root->right, val);
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

int size(node* root){
	
	if(root == NULL){
		return 0;
	}else{
		return 1 + size(root->left) + size(root->right);
	}
    
}



