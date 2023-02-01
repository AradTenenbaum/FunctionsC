#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "queue.h"

// Recursive print tree inorder, receive root
void printTreeInorderNode(TreeNode* tNode)
{
    if (tNode != NULL)
    {
        printTreeInorderNode(tNode->left);

        printf("%d ", tNode->data);

        printTreeInorderNode(tNode->right);
    }
}

// Print wrapper
void printTreeInorder(Tree tree)
{
    printTreeInorderNode(tree.root);
}

// Create a tree node
TreeNode* CreateTreeNode(int data, TreeNode* left, TreeNode* right)
{
    TreeNode* t;
    t = (TreeNode*)malloc(sizeof(TreeNode*));
    memoryAndFileValidation(t);
    t->left = left;
    t->right = right;
    t->data = data;
    return t;
}

// Recursive build a tree node, returns the root 
TreeNode* buildTreeNodes(int* arr, int size)
{
    // Mid index is the roots for each tree level 
    int mid = (size / 2);
    // When the array ends and when the value is -1
    // there is no tree node
    if (size == 0 || arr[mid] == -1)
    {
        return NULL;
    }
    // Build the left node
    TreeNode* left = buildTreeNodes(arr, mid);
    // Create a root 
    TreeNode* root = CreateTreeNode(arr[mid], left, NULL);
    // Connect the right
    root->right = buildTreeNodes(arr + mid + 1, size - mid - 1);

    return root;
}

// Build tree wrapper
Tree BuildTreeFromArray(int* arr, int size)
{
    Tree t;
    // Set the root of the tree
    t.root = buildTreeNodes(arr, size);
    return t;
}

// Go over the nodes and free them
void freeTreeNodes(TreeNode* tNode)
{
    if (tNode != NULL)
    {
        freeTreeNodes(tNode->left);
        free(tNode);
        freeTreeNodes(tNode->right);

    }
}

// Free tree wrapper
void freeTree(Tree tree)
{
    freeTreeNodes(tree.root);
}

// Print by levels function - O(n)
void printByLevels(Tree tr) {
    Queue q = CreateEmptyQueue();
    Enqueue(&q, tr.root);
    int qSize = 0;

    // The loop ends when the nodes in the queue have no children
    while (!isQueueEmpty(q)) {
        // Go over all the nodes in a current level and print them
        qSize = printQueueAndCount(q);
        for (int i = 0; i < qSize; i++) {
            // For each node we insert it's child nodes in the tree if there are
            if (q.first->data->left != NULL) Enqueue(&q, q.first->data->left);
            if (q.first->data->right != NULL) Enqueue(&q, q.first->data->right);
            // Remove the parent from the queue
            Dequeue(&q);
        }
    }
}

// Count the number of nodes helper - recursive
int numNodesHelper(TreeNode* root)
{
    int numNodesLeft, numNodesRight;
    if (root == NULL)
        return 0;
    else
    {
        numNodesLeft = numNodesHelper(root->left);
        numNodesRight = numNodesHelper(root->right);
        return numNodesLeft + numNodesRight + 1;
    }
}

// Count the number of nodes
int numOfNodesInTree(Tree t) {
    return numNodesHelper(t.root);
}
// @Hadar Binsky

// Calculate tree height
int getTreeHeight(Tree* tr)
{
    return getTreeHeightHelper(tr->root);
}
int getTreeHeightHelper(TreeNode* root)
{
    int heightLeft, heightRight;
    if (root == NULL)
        return -1;
    else
    {
        heightLeft = getTreeHeightHelper(root->left);
        heightRight = getTreeHeightHelper(root->right);
        return 1 + max(heightLeft, heightRight);
    }
}
// @Hadar Binsky