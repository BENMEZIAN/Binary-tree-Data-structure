#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;


node* newNode(int data);
node* insert(node* root, int val);
int max(int a, int b);
int height(node* root);
void printRightView(node* root, int level,int* max_level);




int main() {
	
    node* root = NULL;
    int max_level = -1;
    
    root = insert(root, 10);
	root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 36);
    root = insert(root, 56);
    root = insert(root, 78);
	root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 4);
    
    printf("Right view: ");
	printRightView(root, 0, &max_level);

    
    
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

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int height(node* root) {
    if (root == NULL) {
        return -1;
    } else {
        return 1 + max(height(root->right), height(root->left));
    }
}

void printRightView(node* root, int level,int* max_level){
    // Base Case
    if (root == NULL){
    	return;
	}
 
    // If this is the last Node of its level
    if (*max_level < level) {
        printf("%d ", root->data);
        *max_level = level;
    }
 
    // Recur for right subtree first, then left subtree
    printRightView(root->right, level + 1, max_level);
    printRightView(root->left, level + 1, max_level);
}

