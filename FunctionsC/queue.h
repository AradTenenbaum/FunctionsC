#ifndef _QUEUE_H
#define _QUEUE_H
#include "tree.h"
#include <stdbool.h>

typedef struct queueNode {
    TreeNode* data;
    struct queueNode* next;
} QueueNode;

typedef struct queue {
    struct queueNode* first;
    struct queueNode* last;
} Queue;

Queue CreateEmptyQueue();
QueueNode* CreateQueueNode(TreeNode* data, QueueNode* next);
void printQueue(Queue q);
void Enqueue(Queue* q, TreeNode* data);
QueueNode* Dequeue(Queue* q);
int printQueueAndCount(Queue q);
bool isQueueEmpty(Queue q);

#endif 
