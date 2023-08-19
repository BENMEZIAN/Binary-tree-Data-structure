#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**/

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

// Structure for maintaining nodes at each diagonal
typedef struct DiagonalNode{
    struct node* node;
    struct DiagonalNode* next;
}DiagonalNode;

node* newNode(int data);
node* insert(node* root, int val);
void inOrder(node* root); // DFS traversal  (Depth-First Traversal)
void preOrder(node* root); // DFS traversal (Depth-First Traversal)
void postOrder(node* root); // DFS traversal (Depth-First Traversal)
int max(int a,int b);
int height(node* root);
DiagonalNode* createDiagonalNode(node* node); // Function to create a new diagonal node
void updateDiagonalMap(node* root, int diagonal,DiagonalNode** diagonalMap); // Function to update the diagonal map
void printDiagonalTraversal(node* root); // function to print the diagonal traversal of bst


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
	
	printf("Diagonal traversal:\n");
	printDiagonalTraversal(root);
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

DiagonalNode* createDiagonalNode(node* node){
    DiagonalNode* newNode = (DiagonalNode*)malloc(sizeof(DiagonalNode));
    newNode->node = node;
    newNode->next = NULL;
    return newNode;
}

void updateDiagonalMap(node* root, int diagonal,DiagonalNode** diagonalMap){
    
	if (root == NULL){
        return;
    }
    
    DiagonalNode* newNode = createDiagonalNode(root);
    DiagonalNode* current = diagonalMap[diagonal];
    
    // Traverse to the end of the linked list for this diagonal
	while (current && current->next) {
        current = current->next;
    }
    
    if (current != NULL) {
        current->next = newNode;
    } else {
        diagonalMap[diagonal] = newNode;
    }
    
    // Recur for the left subtree with increased diagonal
    updateDiagonalMap(root->left, diagonal + 1, diagonalMap);
    
    // Recur for the right subtree with the same diagonal
    updateDiagonalMap(root->right, diagonal, diagonalMap);
}

void printDiagonalTraversal(node* root){

    if (root == NULL) {
        return;
    }
    
    // Create a map to store nodes for each diagonal
    DiagonalNode** diagonalMap;
    diagonalMap = (DiagonalNode**)malloc(sizeof(DiagonalNode*) * height(root)); 
    for (int i = 0; i < height(root); i++) {
        diagonalMap[i] = NULL;
    }
    
    // Update the diagonal map with the updateDiagonalMap() function
    updateDiagonalMap(root, 0, diagonalMap);
    
    // Traverse the diagonal map and print nodes
    for (int i = 0; i < height(root); i++) {
        DiagonalNode* current = diagonalMap[i];
        while (current != NULL) {
            printf("%d ", current->node->data);
            current = current->next;
        }
        printf("\n");
    }	
}

