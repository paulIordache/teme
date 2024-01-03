#include <stdio.h>
#include "op.h"
int main()
{
    Node *head = NULL, *tail = head;
    NodeT *root = createTree(7);
    root->left = createTree(21);

    root->right = createTree(45);
    root->right->right = createTree(87);
    root->left->left = createTree(22);

    root->left->left->right = createTree(1);
    addList(&head, &tail, root);
    Node *temp = head;

    printf("\nPrinting the list: ");
    while((*temp).next)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("%d ", (*temp).data);
    Node *rev = temp;
    printf("\nPrinting the reverse list: ");

    while(rev)
    {
        printf("%d ", rev->data);
        rev = rev->prev;
    }

    NodeT *created = addTree(&head);
    printf("\nPrinting the Tree: ");
    inOrder(created);

    return 0;
}
