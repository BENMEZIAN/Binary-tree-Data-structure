#include <stdio.h>
#include <stdlib.h>


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
int Depth(node* root, int key, int depth); // Depth of any node in binary tree




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
    insert(root, 4);
    
    
    printf("Inorder traversal : ");
    inOrder(root);
    printf("\n");
    
    
    printf("%d",Depth(root, 10,0));
    
    
    
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

int Depth(node* root, int key, int depth){
	
	if (root == NULL) {
        return -1; // Key not found
    }else if(root->data == key) {
        return depth; // Key found at this depth
    }else if(key < root->data) {
        return Depth(root->left, key, depth + 1);
    }else{
        return Depth(root->right, key, depth + 1);
    }
}

