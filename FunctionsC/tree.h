#ifndef _TREE_H
#define _TREE_H

typedef struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
}TreeNode;

typedef struct tree
{
    TreeNode* root;
}Tree;

Tree BuildTreeFromArray(int* arr, int size);
int* BuildArrayFromTree(Tree tr, int* size);
void printTreeInorder(Tree tree);
void printByLevels(Tree tr);
void freeTree(Tree tree);
int numOfNodesInTree(Tree t);
int getTreeHeight(Tree t);
int isBinSearchTree(Tree t);
int isBST(Tree t);
unsigned int findLongestSequenceByFunction(Tree tr, int(*isValid)(TreeNode* t));

#endif 
