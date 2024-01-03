#include <stdio.h>
#include "op.h"


void AF(int x, Node **head)
{
    Node* temp;
    temp = malloc(sizeof(Node));
    (*temp).next = *head;
    *head = temp;
    (**head).data = x;
}

void AL(int x, Node **head)
{
    Node* temp = malloc(sizeof(Node));
    if(!(*head))
    {
        (*temp).next = *head;
        *head = temp;
        (**head).data = x;
    }
    else
    {
        temp = *head;
        while((*temp).next)
            temp = (*temp).next;
        Node *add = malloc(sizeof(Node));
        (*add).next = NULL;
        (*add).data = x;
        (*temp).next = add;
    }

}

void DF(Node **head)
{
    Node *temp = *head;
    if(!(*temp).next)
        (*head) = NULL;
    if(*head)
    {
        (*head) = (**head).next;
        free(temp);
    }
}

void DL(Node **head)
{
    Node *temp = *head;
    if (!(*temp).next)
        (*head) = NULL;
    if (*head) {
        while (temp->next->next)
            temp = (*temp).next;
        Node *sub = temp;
        (*temp).next = NULL;
        sub = (*sub).next;
        free(sub);
    }
}

void doom_the_list(Node **head)
{
    if (!(**head).next)
        (*head) = NULL;
    if ((*head))
    {
        while ((**head).next) {
            Node *temp = *head;
            (*head) = (**head).next;
            free(temp);
        }
        *head = NULL;
    }
}

void print_all(Node *head)
{
    while(head)
    {
        printf("%d ", (*head).data);
        head = (*head).next;
    }
}

void DE(int x, Node **head) {
    if ((**head).next == NULL) {
        if ((**head).data == x)
            *head = NULL;
    } else {
        if (!((*head)->next->next)) {
            if ((**head).data == x) {
                DF(head);
                if ((**head).data == x)
                    DF(head);
            } else {
                if ((*head)->next->data == x) {
                    Node *sub = *head;
                    sub = (*sub).next;
                    (**head).next = NULL;
                    free(sub);
                }
            }
        } else
        {
            Node *temp = *head;
            while (temp)
            {

                if(!(*temp).next)
                {
                    if((*temp).data == x)
                    {
                        *head = temp;
                        temp = NULL;
                    }


                }
                else if(!temp->next->next)
                {
                    if ((*temp).data == x)
                    {
                        DF(&temp);
                        //*head = temp;
                    }
                    else if(temp->next->data == x)
                    {
                        Node *sub = temp;
                        sub = (*sub).next;
                        (*temp).next = NULL;
                        free(sub);
                    }
                }
                else
                {

                    if((*temp).data == x)
                    {
                        Node *sub = temp;
                        temp = (*temp).next;
                        *head = temp;
                        free(sub);
                    }
                    else
                    {
                        if(temp->next->data == x)
                        {

                            Node *sub = (*temp).next;
                            (*temp).next = (*sub).next;
                            free(sub);
                        }
                    }

                }
                temp = (*temp).next;
            }

        }
    }
}

void PRINT_F(int x, Node *head)
{
    int d = 1;
    while(d++ <= x)
    {
        printf("%d ", (*head).data);
        head = (*head).next;
    }
}

void PRINT_L(int x, Node *head, int a)
{
    int d = 1;
    while(head)
    {
        if(d++ >= a - x + 1)
            printf("%d ", (*head).data);
        head = (*head).next;
    }
}