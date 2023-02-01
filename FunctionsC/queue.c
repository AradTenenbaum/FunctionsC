#include <stdio.h>
#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>
#include "memory.h"

// Check if queue is empty
bool isQueueEmpty(Queue q) {
    return(q.first == NULL);
}

// Print queue, for tests
void printQueue(Queue q) {
    QueueNode* qn = q.first;
    while (qn != NULL) {
        printf("%d ", qn->data->data);
        qn = qn->next;
    }
}

// Print queue and count it's nodes
int printQueueAndCount(Queue q) {
    QueueNode* qn = q.first;
    int counter = 0;
    while (qn != NULL) {
        printf("%d ", qn->data->data);
        counter++;
        qn = qn->next;
    }
    printf("\n");
    return counter;
}

// Create a Queue node - O(1)
QueueNode* CreateQueueNode(TreeNode* data, QueueNode* next) {
    QueueNode* qn;
    qn = (QueueNode*)malloc(sizeof(QueueNode));
    memoryAndFileValidation(qn);
    qn->next = next;
    qn->data = data;
    return qn;
}

// Insert data to queue - O(1)
void Enqueue(Queue* q, TreeNode* data) {
    QueueNode* qn = CreateQueueNode(data, NULL);
    if (q->last == NULL) {
        q->first = qn;
        q->last = qn;
    }
    else {
        q->last->next = qn;
        q->last = qn;
    }
}

// Remove data from queue and return it - O(1)
QueueNode* Dequeue(Queue* q) {
    QueueNode* qn = q->first;
    if (qn != NULL) {
        if (qn == q->last) {
            q->first = NULL;
            q->last = NULL;
        }
        else {
            q->first = qn->next;
        }
        free(qn);
    }
}

// Create empty queue - O(1)
Queue CreateEmptyQueue() {
    Queue q;
    q.first = NULL;
    q.last = NULL;
    return q;
}