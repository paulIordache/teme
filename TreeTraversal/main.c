#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *right, *left;
}Node;

Node* newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;

    return node;
}


void printInOrder(Node *node)
{
    if(!node)
        return;

    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

void printPreOrder(Node *node)
{
    if(!node)
        return;
    printf("%d ", node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printPostOrder(Node *node)
{
    if(!node)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->data);
}


int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    Node *pre = root, *post = root, *in = root;

    printf("\nInOrder traversal\n");
    printInOrder(in);
    printf("\nPreOrder traversal\n");
    printPreOrder(pre);
    printf("\nPostOrder traversal\n");
    printPostOrder(post);

    return 0;
}
