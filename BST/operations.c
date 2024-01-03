#include <malloc.h>
#include <stdio.h>
#include "op.h"

NodeT *newNode(int item)
{
    NodeT *temp = (NodeT *)malloc(sizeof(NodeT));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void preorder(NodeT *root)
{
    if(root == NULL)
        return;
    else
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

NodeT *insert(NodeT *node, int key)
{
    if(node == NULL)
        return newNode(key);

    else
    {
        if (key < node->key)
            node->left = insert(node->left, key);
        else node->right = insert(node->right, key);
    }

    return node;

}

NodeT *deleteNode(NodeT *root, int key)
{
    if(root == NULL)
        return root;

    if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if(root->left == NULL) {
            NodeT *temp = root->right;  
        }
    }
}