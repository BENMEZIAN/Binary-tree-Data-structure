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
bool isNodePresent(node* root, int data); // check if a node is exist in binary tree
node* lowestCommonAncestor(node* root, int p, int q); // find the LCA of two nodes in binary tree



int main() {
	
    node* root = NULL;
    int p,q;

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
    
    printf("enter p:");
    scanf("%d",&p);
    
    printf("enter q:");
    scanf("%d",&q);
    
    if(isNodePresent(root, p) && isNodePresent(root, q)) {
        node* n = lowestCommonAncestor(root, p, q);
        printf("LCA(%d,%d) = %d",p,q,n->data);
    }else{
    	printf("your node(s) doesn't (don't) exist");
	}
	
	
    
    
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

bool isNodePresent(node* root, int data){
    // base case
    if (root == NULL) {
        return false;
    }
 
    // if the node is found, return true
    if (root->data == data) {
        return true;
    }
 
    // return true if a given node is found in the left or right subtree
    return isNodePresent(root->left, data) || isNodePresent(root->right, data);
}

node* lowestCommonAncestor(node* root, int p, int q) {
    // Base case
    if(root == NULL || root->data == p || root->data == q) {
        return root;
    }

    node* left = lowestCommonAncestor(root->left, p, q);
    node* right = lowestCommonAncestor(root->right, p, q);

    // Result
    if(left != NULL && right != NULL) {
        return root;
    } else if (left != NULL) {
        return left;
    } else {
        return right;
    }
}

