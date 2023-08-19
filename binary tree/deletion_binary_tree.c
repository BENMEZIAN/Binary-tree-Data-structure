#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

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
node** createQueue(int* front, int* rear);
void enQueue(node** queue, int* rear,node* new_node);
node* deQueue(struct node** queue, int* front);
void levelOrder(node* root); // BFS traversal (Breadth-First Traversal)
int getRightMin(node *root);
int getLeftMax(node *root);
node* deleteBST(node* root, int val); // deletion from binary tree


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

    root = deleteBST(root,30);
    
    printf("Inorder traversal after deleting 30: ");
    inOrder(root);
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

int getRightMin(node *root){ // i pass "root->right"
	
    node *temp = root;
    //min value should be present in the left most node.
    while(temp->left != NULL){
		temp = temp->left;
	}

    return temp->data;
}

int getLeftMax(node *root){ // i pass "root->left"
	
    node *temp = root;
    //min value should be present in the left most node.
    while(temp->right != NULL){
		temp = temp->right;
	}

    return temp->data;
}

node* deleteBST(node* root, int val){
	
	if (root == NULL){
		return root;
	}

    if (val < root->data) {
        root->left = deleteBST(root->left, val);
    } else if (val > root->data) {
       root->right = deleteBST(root->right, val);
    }else{ // val == root->data
    	
    	// Case 1: Leaf node. Both left and right reference is NULL
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        
        // Case 2: Node has one child.
        else if(root->left == NULL){ 
            node *temp = root->right; // replace the root node with root->right 
            free(root); 
            return temp;
        }else if(root->right == NULL){  // Node has left child.
            node *temp = root->left;
            free(root);
            return temp;
        }else{ // Case 3: Node has both left and right children.
            int rightMin = getRightMin(root->right); // Find the min value in the right subtree
            root->data = rightMin; // replace node value with min.
            root->right = deleteBST(root->right,rightMin); // delete the node which has the min value.
            /***********************OR********************************************************/
            /*
            int leftMax = getLeftMax(root->left); // Find the min value in the left subtree
            root->data = leftMax; // replace node value with min.
            root->left = deleteBST(root->left,leftMax); // delete the node which has the min value.
			*/
        }
	}
	
	return root;
}
