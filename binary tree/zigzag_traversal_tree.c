#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

typedef struct StackNode{
    node* data;
    struct StackNode* next;
} StackNode;

typedef struct Stack{
    StackNode* top;
} Stack;


node* newNode(int data); // create new node
node* insert(node* root, int val); // insertion
void inOrder(node* root); // DFS traversal  (Depth-First Traversal)
void preOrder(node* root); // DFS traversal (Depth-First Traversal)
void postOrder(node* root); // DFS traversal (Depth-First Traversal)
int max(int a,int b);
int height(node* root);
Stack* createStack();
void push(Stack* s, node* new_node);
node* pop(Stack* s);
bool is_empty(Stack* s);
void zigzagTraversal(node* root);



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
    
	printf("Preorder traversal : ");
    preOrder(root);
    printf("\n");
    
	printf("Postorder traversal : ");
    postOrder(root);
    printf("\n");
	
    printf("Zigzag traversal : ");
	zigzagTraversal(root);
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

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, node* new_node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = new_node;
    newNode->next = s->top;
    s->top = newNode;
}

node* pop(Stack* s) {
    if (s->top == NULL) {
        return NULL;
    }

    StackNode* temp = s->top;
    s->top = s->top->next;

    node* data = temp->data;
    free(temp);

    return data;
}

bool is_empty(Stack* s) {
    return s->top == NULL;
}

void zigzagTraversal(node* root) {
	
    if (root == NULL) {
        return;
    }

    Stack* stack1 = createStack();
    Stack* stack2 = createStack();
    push(stack1, root);

    while (!is_empty(stack1) || !is_empty(stack2)) {
        while (!is_empty(stack1)) {
            node* node = pop(stack1);

            // Print the node's value
            printf("%d ", node->data);

            if (node->left) {
                push(stack2, node->left);
            }
            if (node->right) {
                push(stack2, node->right);
            }
        }

        while (!is_empty(stack2)) {
            node* node = pop(stack2);

            // Print the node's value
            printf("%d ", node->data);

            if (node->right) {
                push(stack1, node->right);
            }
            if (node->left) {
                push(stack1, node->left);
            }
        }
    }
}

