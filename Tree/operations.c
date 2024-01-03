#include <stdio.h>
#include <malloc.h>
#include "op.h"
void inOrder(NodeT *root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);
    inOrder(root->left);
    inOrder(root->right);
}

void addList(Node **head, Node **tail, NodeT *root)
{
    if(root == NULL)
        return;

    if(*tail == NULL)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = root->data;
        node->prev = NULL;
        node->next = NULL;
        *head = node;
        *tail = *head;
    }
    else
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = root->data;
        node->prev = *tail;
        node->next = NULL;
        (*tail)->next = node;
        *tail = node;
    }
    addList(head, tail, root->left);
    addList(head, tail, root->right);
}

NodeT *createTree(int id)
{
    NodeT *root = (NodeT *)malloc(sizeof(NodeT));
    root->data = id;
    root->left = NULL;
    root->right = NULL;

    return root;
}

NodeT *addTree(Node **node)
{
    NodeT *temp;
    if(*node == NULL)
        return NULL;

    else
    {
        temp = (NodeT *) malloc(sizeof(NodeT));
        temp->data = (*node)->data;
        *node = (*node)->next;
        temp->left = addTree(node);
        temp->right = addTree(node);
    }
    return temp;
}