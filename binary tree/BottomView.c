#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

typedef struct BottomViewNode {
    struct node* node;
    int horizontalDistance;
    struct BottomViewNode* next;
} BottomViewNode;

node* newNode(int data);
node* insert(node* root, int val);
int max(int a, int b);
int height(node* root);
BottomViewNode* createBottomViewNode(node* node, int horizontalDistance);
void updateBottomView(node* root, int distance, int level, BottomViewNode** bottomViewMap);
void printBottomView(node* root);


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
    
    printf("Bottom view: ");
    printBottomView(root);

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

BottomViewNode* createBottomViewNode(node* node, int horizontalDistance) {
    BottomViewNode* newNode = (BottomViewNode*)malloc(sizeof(BottomViewNode));
    newNode->node = node;
    newNode->horizontalDistance = horizontalDistance;
    newNode->next = NULL;
    return newNode;
}

void updateBottomView(node* root, int distance, int level, BottomViewNode** bottomViewMap) {
    
	if (root == NULL) {
        return;
    }

    if (bottomViewMap[distance] == NULL || level >= bottomViewMap[distance]->horizontalDistance) {
        BottomViewNode* newNode = createBottomViewNode(root, level);
        bottomViewMap[distance] = newNode;
    }

    // Recur for the left subtree with decreased distance
    updateBottomView(root->left, distance - 1, level + 1, bottomViewMap);

    // Recur for the right subtree with increased distance
    updateBottomView(root->right, distance + 1, level + 1, bottomViewMap);
}

void printBottomView(node* root) {
	
    if (root == NULL) {
        return;
    }

    // Create a map to store nodes for each horizontal distance
    BottomViewNode** bottomViewMap = (BottomViewNode**)malloc(sizeof(BottomViewNode*) * (2 * height(root) + 1));
    for (int i = 0; i < 2 * height(root) + 1; i++) {
        bottomViewMap[i] = NULL;
    }

    // Update the bottomView map with the updateBottomView() function
    updateBottomView(root, height(root), 0, bottomViewMap);

    // Print the bottom view nodes
    for (int i = 0; i < 2 * height(root) + 1; i++) {
        if (bottomViewMap[i] != NULL) {
            printf("%d ", bottomViewMap[i]->node->data);
        //    printf("%d -> %d (hd)\n", bottomViewMap[i]->node->data,bottomViewMap[i]->horizontalDistance);
        }
    }
}

