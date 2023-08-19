#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

typedef struct topViewNode {
    struct node* node;
    int horizontalDistance;
    struct topViewNode* next;
} topViewNode;

node* newNode(int data);
node* insert(node* root, int val);
int max(int a, int b);
int height(node* root);
topViewNode* createTopViewNode(node* node, int horizontalDistance);
void updateTopView(node* root, int distance, int level, topViewNode** topViewMap);
void printTopView(node* root);


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
    
    printf("Top view: ");
    printTopView(root);

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

topViewNode* createTopViewNode(node* node, int horizontalDistance) {
    topViewNode* newNode = (topViewNode*)malloc(sizeof(topViewNode));
    newNode->node = node;
    newNode->horizontalDistance = horizontalDistance;
    newNode->next = NULL;
    return newNode;
}

void updateTopView(node* root, int distance, int level, topViewNode** topViewMap) {
    
	if (root == NULL) {
        return;
    }

    if (topViewMap[distance] == NULL || level <= topViewMap[distance]->horizontalDistance) {
        topViewNode* newNode = createTopViewNode(root, level);
        topViewMap[distance] = newNode;
    }

    // Recur for the left subtree with decreased distance
    updateTopView(root->left, distance - 1, level + 1, topViewMap);

    // Recur for the right subtree with increased distance
    updateTopView(root->right, distance + 1, level + 1, topViewMap);
}

void printTopView(node* root) {
	
    if (root == NULL) {
        return;
    }

    // Create a map to store nodes for each horizontal distance
    topViewNode** topViewMap = (topViewNode**)malloc(sizeof(topViewNode*) * (2 * height(root) + 1));
    for (int i = 0; i < 2 * height(root) + 1; i++) {
        topViewMap[i] = NULL;
    }

    // Update the bottomView map with the updateTopView() function
    updateTopView(root, height(root), 0, topViewMap);

    // Print the bottom view nodes
    for (int i = 0; i < 2 * height(root) + 1; i++) {
        if (topViewMap[i] != NULL) {
        	printf("%d ", topViewMap[i]->node->data);
        //    printf("%d -> %d (hd) \n", topViewMap[i]->node->data,topViewMap[i]->horizontalDistance);
        }
    }
}

