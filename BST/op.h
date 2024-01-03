//
// Created by Paul on 3/30/2023.
//

#ifndef BST_OP_H
#define BST_OP_H

typedef struct NodeT
{
    int key;
    struct NodeT *right, *left;
}NodeT;

NodeT *addNode(int data);
void length(NodeT **root, int nr, int *max);
#endif //BST_OP_H
