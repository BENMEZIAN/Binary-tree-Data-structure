#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct QueueNode {
    TreeNode* node;
    int distance;
} QueueNode;

typedef struct Queue {
    QueueNode* array;
    int front;
    int rear;
    int capacity;
} Queue;

TreeNode* newNode(int data);
TreeNode* insert(TreeNode* root, int val);
Queue* createQueue(int capacity);
void enqueue(Queue* queue, TreeNode* new_node, int distance);
QueueNode dequeue(Queue* queue);
int isEmpty(Queue* queue);
void verticalOrderTraversal(TreeNode* root);
void printNodesAtDistance(TreeNode* node, int targetDistance, int currentDistance);


int main() {
	
    TreeNode* root = NULL;

    root = insert(root,10);
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

    printf("Vertical Order Traversal: ");
    verticalOrderTraversal(root);

    return 0;
}

TreeNode* newNode(int data){
	
    TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

TreeNode* insert(TreeNode* root, int val){
    
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

Queue* createQueue(int capacity){
	
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->array = (QueueNode*)malloc(sizeof(QueueNode) * capacity);
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

void enqueue(Queue* queue, TreeNode* new_node, int distance){
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    queue->rear++;
    queue->array[queue->rear].node = new_node;
    queue->array[queue->rear].distance = distance;
}

QueueNode dequeue(Queue* queue){
	
    QueueNode emptyNode;
    emptyNode.node = NULL;
    emptyNode.distance = 0;

    if (queue->front > queue->rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return emptyNode;
    }

    QueueNode qNode = queue->array[queue->front];
    queue->front++;
    return qNode;
}

int isEmpty(Queue* queue){
    return queue->front > queue->rear;
}

void verticalOrderTraversal(TreeNode* root){
	
    if (root == NULL){
    	return;
	}

    Queue* queue = createQueue(100);
    enqueue(queue, root, 0);

    int leftMostDistance = 0;
    int rightMostDistance = 0;

    while(!isEmpty(queue)){
        QueueNode qNode = dequeue(queue);
        TreeNode* currentNode = qNode.node;
        int distance = qNode.distance;

        if(currentNode->left != NULL){
            enqueue(queue, currentNode->left, distance - 1);
            leftMostDistance = (distance - 1 < leftMostDistance) ? distance - 1 : leftMostDistance;
        }

        if(currentNode->right != NULL){
            enqueue(queue, currentNode->right, distance + 1);
            rightMostDistance = (distance + 1 > rightMostDistance) ? distance + 1 : rightMostDistance;
        }
    }

    // Print the nodes in vertical order
    for(int dist = leftMostDistance; dist <= rightMostDistance; dist++){
        printNodesAtDistance(root, dist, 0);
    }
    
    // Free allocated memory (not shown in this simplified example)
    free(queue);
}

void printNodesAtDistance(TreeNode* node, int targetDistance, int currentDistance){
    
	if(node == NULL){
		return;
	}

    if(currentDistance == targetDistance){
        printf("%d ", node->data);
    }

    printNodesAtDistance(node->left, targetDistance, currentDistance - 1);
    printNodesAtDistance(node->right, targetDistance, currentDistance + 1);
}

