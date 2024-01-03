#include <stdio.h>

typedef struct NodeT
{
    int data;
    struct NodeT *left, *right;
}NodeT;


void max(NodeT *root, int *maxi)
{
    if(root = NULL)
        return;
    max(root->left, *maxi + 1);
    max(root->right, *maxi + 1);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
