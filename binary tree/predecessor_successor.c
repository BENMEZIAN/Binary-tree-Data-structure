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
int find_predecessor(node* root, int val); // predecessor of node
int find_successor(node* root, int val); // successor of node


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
    
    printf("Le predecesseur de 10 est: %d\n",find_predecessor(root,10));
    
    printf("Le successeur de 10 est: %d\n",find_successor(root,10));
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

int find_predecessor(node* root, int val){
	// if tree is empty
    if (root == NULL) {
        return -1; // Predecessor not found
    }
    // if root node equal to val
    if (root->data == val) {
        if (root->left != NULL) {
            node* predecessor = root->left;
            while (predecessor->right != NULL) {
                predecessor = predecessor->right;
            }
            return predecessor->data;
        } else {
            return -1; // No predecessor
        }
    }
    
    if (val < root->data) {
    	int pred = find_predecessor(root->left, val);
    } else { 
        int pred = find_predecessor(root->right, val);
        if (pred == -1) {
            return root->data; // Current root is the predecessor
        } else {
            return pred;
        }
    }
}

int find_successor(node* root, int val){
	// if tree is empty
    if (root == NULL) {
        return -1; // succecessor not found
    }
    // if root node equal to val
    if (root->data == val) {
        if (root->right != NULL) {
            node* predecessor = root->right;
            while (predecessor->left != NULL) {
                predecessor = predecessor->left;
            }
            return predecessor->data;
        } else {
            return -1; // No succecessor
        }
    }
    
    if (val < root->data) {
    	int pred = find_predecessor(root->left, val);
    } else { 
        int pred = find_predecessor(root->right, val);
        if (pred == -1) {
            return root->data; // Current root is the succecessor
        } else {
            return pred;
        }
    }
}
