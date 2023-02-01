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
void printTreeInorder(Tree tree);
void printByLevels(Tree tr);
void freeTree(Tree tree);
int numOfNodesInTree(Tree t);
int getTreeHeight(Tree* tr);

#endif 
