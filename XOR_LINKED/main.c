#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node
{
    int data;
    struct Node *nxp;
}Node;

Node *XOR(Node *a, Node *b)
{
    return (Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insert(Node **head, int value)
{
    if(*head == NULL)
    {
        Node *new = (Node *)malloc(sizeof(Node));
        new->data = value;
        new->nxp = XOR(NULL, NULL);
        *head = new;
    }
    else
    {
        Node *new = (Node *)malloc(sizeof(Node));
        Node *prev = NULL;
        Node *curr = *head;
        new->nxp = XOR(prev, curr);
        curr->nxp = XOR(new, curr->nxp);
        *head = new;
        new->data = value;

    }
}

void printList(Node *head)
{
    Node *curr = head, *prev = NULL, *next;
    while(curr)
    {
        printf("%d ", curr->data);
        next = XOR(prev, curr->nxp);
        prev = curr;
        curr = next;

    }
    puts("\n");
}

Node *printRev(Node **head)
{
    Node *curr = *head;
    Node *prev = NULL;
    Node *next;
    while(XOR(prev, curr->nxp) != NULL)
    {
        next = XOR(prev, curr->nxp);
        prev=  curr;
        curr = next;
    }
    return curr;
}

int main()
{
    Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printList(head);

    Node *tail = printRev(&head);
    printList(tail);

}

