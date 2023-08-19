#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

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
node** createQueue(int* front, int* rear);
void enQueue(node** queue, int* rear,node* new_node);
node* deQueue(struct node** queue, int* front);
void levelOrder(node* root); // BFS traversal (Breadth-First Traversal)


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
    
	printf("Preorder traversal : ");
    preOrder(root);
    printf("\n");
    
	printf("Postorder traversal : ");
    postOrder(root);
    printf("\n");
    
	printf("Level order traversal : ");
    levelOrder(root);
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

// function that inserts new node to binary tree
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

node** createQueue(int* front, int* rear){
	node** queue = (node**)malloc(sizeof(node*) * MAX_Q_SIZE);
    *front = *rear = 0;
    return queue;
}

void enQueue(node** queue, int* rear,node* new_node){
    queue[*rear] = new_node;
    (*rear)++;
}
 
node* deQueue(struct node** queue, int* front){
    (*front)++;
    return queue[*front - 1];
}

void levelOrder(node* root) {
	
    int rear, front;
    node** queue = createQueue(&front, &rear);
    node* temp = root;

    if (root != NULL) {
        while (temp != NULL) {
	        printf("%d ", temp->data);
	 
	        // Enqueue left child
	        if (temp->left){
	        	enQueue(queue, &rear, temp->left);
			}
	 
	        // Enqueue right child
	        if (temp->right){
	        	enQueue(queue, &rear, temp->right);
			}
	        // Dequeue node and make it temp_node
	        temp = deQueue(queue, &front);
    	}
    }
}
