#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "queue.h"
#include <math.h>
#define END_OF_TREE -1

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
int maxInt(int a, int b) {
    return a > b ? a : b;
}
int getTreeHeight(Tree t) {
    return getTreeHeightHelper(t.root);
}
int getTreeHeightHelper(TreeNode* root) {
    if (root == NULL) return -1;
    return (1 + maxInt(getTreeHeightHelper(root->left), getTreeHeightHelper(root->right)));
}


// Build an array from a tree
void buildArrayFromTreeHelper(TreeNode* root, int* arr, int size) {
    int mid = (size / 2);
    if (root != NULL) {
        arr[mid] = root->data;
        buildArrayFromTreeHelper(root->left, arr, mid);
        buildArrayFromTreeHelper(root->right, arr + mid + 1, mid);
    }
}
int* BuildArrayFromTree(Tree tr, int* size) {
    int height = getTreeHeight(tr);
    *size = (pow(2, height + 1)) - 1;

    int* arr = malloc(sizeof(int) * (*size));
    memoryAndFileValidation(arr);

    for (int i = 0; i < *size; i++) arr[i] = -1;

    buildArrayFromTreeHelper(tr.root, arr, *size);

    return arr;
}

// Get tree max value
int maxValue(TreeNode* node)
{
    if (node == NULL) {
        return 0;
    }

    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);

    int value = 0;
    if (leftMax > rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }

    if (value < node->data) {
        value = node->data;
    }

    return value;
}

// Get tree min value
int minValue(TreeNode* node)
{
    if (node == NULL) {
        return 1000000000;
    }

    int leftMax = minValue(node->left);
    int rightMax = minValue(node->right);

    int value = 0;
    if (leftMax < rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }

    if (value > node->data) {
        value = node->data;
    }

    return value;
}

// Check if a tree is a binary search tree
int isBinSearchTreeHelper(TreeNode* root) {
    if (root == NULL) {
        return 1;
    }
    if (root->left) {
        if (root->data < maxValue(root->left)) return 0;
    }
    if (root->right) {
        if (root->data > minValue(root->right)) return 0;
    }
    if (!isBinSearchTreeHelper(root->left) || !isBinSearchTreeHelper(root->right)) return 0;
    return 1;
}
int isBinSearchTree(Tree t) {
    return isBinSearchTreeHelper(t.root);
}

// Check if tree binary tree in O(n)
// When you run inorder (left-root-right)
// if every element is greater than the last,
// then the tree is BST
// Binary search is like searching on a sorted array 
// that represents binary tree
int isBSTHelper(TreeNode* root, TreeNode** lastNode) {
    if (root == NULL) return 1;
    int leftRes = isBSTHelper(root->left, lastNode);
    if ((*lastNode) == NULL) 
    {
        (*lastNode) = root;
        return 1;
    }
    if ((*lastNode)->data >= root->data) return 0;
    (*lastNode) = root;
    int rightRes = isBSTHelper(root->right, lastNode);
    return leftRes && rightRes;
}
int isBST(Tree t) {
    TreeNode* lastNode = NULL;
    return isBSTHelper(t.root, &lastNode);
}

// Find the longest sequence of valid tree nodes in the tree
// The valid definition is dynamic by the input function
void findLongestSequenceByFunctionHelper(TreeNode* root, int(*isValid)(TreeNode* t), int count, int* max) {
    if (root != NULL) {
        if (!isValid(root)) {
            findLongestSequenceByFunctionHelper(root->left,isValid, 0, max);
            findLongestSequenceByFunctionHelper(root->right,isValid, 0, max);
        }
        else {
            count++;
            (*max) = max(count, *max);
            findLongestSequenceByFunctionHelper(root->left, isValid, count, max);
            findLongestSequenceByFunctionHelper(root->right, isValid, count, max);
        }
    }
}
unsigned int findLongestSequenceByFunction(Tree tr, int(*isValid)(TreeNode* t)) {
    int max = 0;
    findLongestSequenceByFunctionHelper(tr.root, isValid, 0, &max);
    return max;
}

// Return 1 if tree is balanced else 0
int isBalancedHelper(TreeNode* root, int* level, int* nodesAmount) {
    if (root == NULL) {
        *level = -1;
        *nodesAmount = 0;
        return 1;
    }
    int leftLevel, rightLevel;
    int leftNodesAmount, rightNodesAmount;

    int isLeftBalanced = isBalancedHelper(root->left, &leftLevel, &leftNodesAmount);
    int isRightBalanced = isBalancedHelper(root->right, &rightLevel, &rightNodesAmount);

    *level = 1 + max(leftLevel, rightLevel);
    *nodesAmount = 1 + leftNodesAmount + rightNodesAmount;


    if (isLeftBalanced && isRightBalanced) {
        if (abs(rightLevel - rightLevel) <= 1 && abs(rightNodesAmount - leftNodesAmount) <= 1) return 1;
        else return 0;
    }
    else return 0;


}
int isBalanced(Tree t) {
    int level, nodesAmount;
    return isBalancedHelper(t.root, &level, &nodesAmount);
}


// Returns true if the tree node is a leaf
bool isLeaf(TreeNode* t) {
    return (t->left == NULL && t->right == NULL);
}


// Get the minimum path from root to leaf
void minPathSumHelper(TreeNode* root, int* sum) {
    
    if (root == NULL) {
        *sum = END_OF_TREE;
    }
    else {
        int leftSum = 0, rightSum = 0;

        minPathSumHelper(root->left, &leftSum);
        minPathSumHelper(root->right, &rightSum);

        if (leftSum == END_OF_TREE && rightSum == END_OF_TREE) *sum += root->data;
        else if (leftSum == END_OF_TREE) *sum += (root->data + rightSum);
        else if (rightSum == END_OF_TREE) *sum += (root->data + leftSum);
        else *sum += (root->data + min(leftSum, rightSum));

    }
}
int minPathSum(Tree t) {
    int sum = 0;
    minPathSumHelper(t.root, &sum);
    return sum;
}


// Get the path from root to leaf when:
// |Height - Path| is the the minimum when the path is sorted
// If there is no sorted path return -1
int minPathHeight(int leftSum, int rightSum, int leftHeight, int rightHeight) {
    if (fabs(leftSum - leftHeight) > fabs(rightSum - rightHeight)) return rightSum;
    else return leftSum;
}
void minDiffSortedPathsHelper(TreeNode* root, int* sum, int* height, TreeNode* prev) {

    if (root == NULL || (prev && root->data < prev->data)) {
        *sum = END_OF_TREE;
        *height = END_OF_TREE;
        //return END_OF_TREE;
    }
    else {
        int leftSum = 0, rightSum = 0;
        int leftHeight, rightHeight;

        minDiffSortedPathsHelper(root->left, &leftSum, &leftHeight, root);
        minDiffSortedPathsHelper(root->right, &rightSum, &rightHeight, root);

        if (leftSum == END_OF_TREE && rightSum == END_OF_TREE) *sum += root->data;
        else if (leftSum == END_OF_TREE) *sum += (root->data + rightSum);
        else if (rightSum == END_OF_TREE) *sum += (root->data + leftSum);
        else *sum += (root->data + (minPathHeight(leftSum, rightSum, leftHeight, rightHeight)));

        *height = 1 + max(leftHeight, rightHeight);

        /*if (minDiffLeft == END_OF_TREE && minDiffRight == END_OF_TREE) return (*sum);
        else if (minDiffLeft == END_OF_TREE) return (int)fabs(*height - (*sum + minDiffRight));
        else if (minDiffRight == END_OF_TREE) return (int)fabs(*height - *sum) + minDiffLeft;
        else return (int)fabs(*height - *sum) + min(minDiffLeft, minDiffRight);*/

    }
}
int minDiffSortedPaths(Tree t) {
    int sum = 0;
    int height;
    minDiffSortedPathsHelper(t.root, &sum, &height, NULL);
    return sum;
}