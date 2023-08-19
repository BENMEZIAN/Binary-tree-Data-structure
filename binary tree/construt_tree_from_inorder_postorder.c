#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;

/* Prototypes for utility functions */
node* newNode(int data);
int search(int arr[], int strt, int end, int value);
node* buildUtil(int in[], int post[], int inStrt, int inEnd,int* pIndex);
node* buildTree(int in[], int post[], int n);
void preOrder(node* node);



// Driver code
int main(){
	
	int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
	int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
	int n = sizeof(in) / sizeof(in[0]);

	node* root = buildTree(in, post, n);

	printf("inorder traversal tree is: ");
	preOrder(root);

	return 0;
}

/* Helper function that allocates a new node */
node* newNode(int data){
	node* n = (node*)malloc(sizeof(node));
	n->data = data;
	n->left = n->right = NULL;
	return (n);
}

/* Function to find index of value in arr[start...end]
The function assumes that value is postsent in in[] */
int search(int arr[], int strt, int end, int value){
	
	int i;
	for (i = strt; i <= end; i++) {
		if (arr[i] == value)
			break;
	}
	return i;
}

node* buildUtil(int in[], int post[], int inStrt, int inEnd,int* pIndex){
	// Base case
	if (inStrt > inEnd){
		return NULL;
	}

	/* Pick current node from Postorder traversal using	postIndex and decrement postIndex */
	node* node = newNode(post[*pIndex]);
	(*pIndex)--;

	/* If this node has no children then return */
	if (inStrt == inEnd)
		return node;

	/* Else find the index of this node in Inorder traversal */
	int iIndex = search(in, inStrt, inEnd, node->data);

	/* Using index in Inorder traversal, construct left and	right subtrees */
	node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
	node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);

	return node;
}

// This function mainly initializes index of root and calls buildUtil()
node* buildTree(int in[], int post[], int n){
	int pIndex = n - 1;
	return buildUtil(in, post, 0, n - 1, &pIndex);
}

/* This function is here just to test */
void preOrder(node* node){
	if (node != NULL){
		printf("%d ", node->data);
		preOrder(node->left);
		preOrder(node->right);
	}
}

