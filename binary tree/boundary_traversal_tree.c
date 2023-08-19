#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root.

The boundary includes:
- left boundary (nodes on left excluding leaf nodes)
- leaves (consist of only the leaf nodes) - left and right leaf nodes-
- right boundary (nodes on right excluding leaf nodes)
*/

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;


node* newNode(int data);
node* insert(node* root, int val);
void inOrder(node* root); // DFS traversal  (Depth-First Traversal)
void preOrder(node* root); // DFS traversal (Depth-First Traversal)
void postOrder(node* root); // DFS traversal (Depth-First Traversal)
bool isLeaf(node* root); // function to check if a node in a leaf
void printLeftBoundary(node* root); // function to print the left side of binary tree except the leaves nodes
void printRightBoundary(node* root); // function to print the right side of binary tree except the leaves nodes
void printLeaves(node* root); // function to print the leaves nodes
void printBoundaryTraversal(node* root); // function to print the boundary traversal of binary tree



int main() {
	
    node* root = NULL;

    root = insert(root,10);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 36);
    root = insert(root, 56);
    root = insert(root, 78);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 4);
    
    printf("Inorder traversal: ");
    inOrder(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    preOrder(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    postOrder(root);
    printf("\n");
    
    printf("Boundary traversal: ");
    printBoundaryTraversal(root);
	printf("\n");
	
	
    
    
    return 0;
}

node* newNode(int data){
	
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* insert(node* root, int val){
    
	if(root == NULL) {
        return newNode(val);
    }

    if(val < root->data){
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

bool isLeaf(node* root){
	
	if(root->left == NULL && root->right == NULL){
		return true;
	}else{
		return false;
	}
}

void printLeftBoundary(node* root){
	
	if(root->left != NULL){
		if(root != NULL && !isLeaf(root)){
			printf("%d ",root->data); // to ensure top down order, print the node before calling itself for left subtree
			printLeftBoundary(root->left);
		}
	}else if(root->right != NULL){
		if(root != NULL && !isLeaf(root)){
			printf("%d ",root->data);
			printLeftBoundary(root->right);
		}
	}
}

void printRightBoundary(node* root){
	
	if(root->right != NULL){
		if(root != NULL && !isLeaf(root)){
			printRightBoundary(root->right); // to ensure bottom up order, first call for right subtree, then print this node
			printf("%d ",root->data);
		}
	}else if(root->left != NULL){
		if(root != NULL && !isLeaf(root)){
			printRightBoundary(root->left);
			printf("%d ",root->data);
		}
	}
}

void printLeaves(node* root){
	
	if(isLeaf(root)){
		printf("%d ",root->data);
	}
	
	if(root->left != NULL){
		printLeaves(root->left);  // start with the leaves of the left sub-tree
	}
	
	if(root->right != NULL){
		printLeaves(root->right);  // move to the leaves of the right sub-tree
	}
}

void printBoundaryTraversal(node* root){
	
	// print the root of the tree
	printf("%d ",root->data);
	
	// print the left boundary
	printLeftBoundary(root->left);
	
	// print the leave nodes
	printLeaves(root);
	
	// print the left boundary
	printRightBoundary(root->right);
		
}

