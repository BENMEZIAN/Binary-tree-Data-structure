#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	char data;
	struct node* left;
	struct node* right;
}node;

/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value);
node* newNode(char data);
node* buildTree(char in[], char pre[], int inStrt, int inEnd);
void printInorder(node* node);




/* Driver program to test above functions */
int main(){
	
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
	int len = sizeof(in) / sizeof(in[0]);
	struct node* root = buildTree(in, pre, 0, len - 1);

	/* Let us test the built tree by printing Inorder traversal */
	printf("Inorder traversal of the constructed tree is: ");
	printInorder(root);
	
	
	
	return 0;
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(char data){
	node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int search(char arr[], int strt, int end, char value){
	
	int i;
	for (i = strt; i <= end; i++) {
		if (arr[i] == value)
			return i;
	}
}

node* buildTree(char in[], char pre[], int inStrt, int inEnd){
	
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder traversal using preIndex and increment preIndex */
	node* tNode = newNode(pre[preIndex++]);

	/* If this node has no children then return */
	if (inStrt == inEnd){
		return tNode;
	}

	/* Else find the index of this node in Inorder traversal */
	int inIndex = search(in, inStrt, inEnd, tNode->data);

	/* Using index in Inorder traversal, construct left and right subtress */
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

	return tNode;
}

/* This function is here just to test buildTree() */
void printInorder(node* node){
	
	if (node != NULL){
		printInorder(node->left);
		printf("%c ", node->data);
		printInorder(node->right);
	}
}

