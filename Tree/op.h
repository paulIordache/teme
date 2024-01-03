

#ifndef TREE_OP_H
#define TREE_OP_H

typedef struct NodeT
{
    int data;
    struct NodeT *left, *right;
}NodeT;

typedef struct Node
{
    int data;
    struct Node *prev, *next;
}Node;

NodeT *addTree(Node **new);
NodeT *createTree(int data);
void addList(Node **head, Node **tail, NodeT *root);
void inOrder(NodeT *root);

#endif //TREE_OP_H
