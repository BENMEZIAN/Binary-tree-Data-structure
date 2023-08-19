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
int max(int a,int b);
int height(node* root);
int getWidth(node* root, int level); // width (number of nodes in a given level)
int findMaxWidth(node* root);  // width (number of nodes in binary tree)


int main() {
	
    node* root = NULL;

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
    
    
    printf("Inorder traversal : ");
    inOrder(root);
    printf("\n");
    
    printf("Width = %d\n",getWidth(root, 2)); // 2
    
    printf("Max Width = %d\n",findMaxWidth(root)); // 4
    
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

int max(int a,int b){
	
	if(a > b){
		return a;
	}else if(a < b){
		return b;
	}
}

int height(node* root){
	
	if(root == NULL){
		return -1;
	}else{
		return 1 + max(height(root->right),height(root->left));
	}
}

int getWidth(node* root, int level){
    if (root == NULL) {
        return 0;
    }
    if (level == 1) {
        return 1;
    } else if (level > 1) {
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
    }
}

int findMaxWidth(node* root){
    int h = height(root);
    int maxWidth = 0;

    for (int level = 1; level <= h; level++) {
        int width = getWidth(root, level);
        maxWidth = max(maxWidth, width);
    }

    return maxWidth;
}

