#include <stdio.h>
#include "op.h"
#include <string.h>

instruction * hash_table[TABLE_SIZE];
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

unsigned int hash(char *name) {
    unsigned int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_table() {
    printf("Start\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(hash_table[i] == NULL)
            printf("\t%i\t---\n", i);
        else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hash_table_insert(instruction *p) {
    if(p == NULL) return false;
    unsigned int index = hash(p->name);
    if(hash_table[index]) {
        unsigned int i = index;
        while(++i != index)
        {
            if(i > TABLE_SIZE - 1)
                i = 0;
            if(!hash_table[i]) {
                hash_table[i] = p;
                break;
            }
        }
        return true;
    }
    hash_table[index] = p;
    return true;
}

unsigned int hash_table_lookup (char *name) {
    unsigned int index = hash(name);
    if(hash_table[index] != NULL)
    {
        if(strcmp(hash_table[index]->name, name) == 0)
            return index;
        else {
            unsigned int i = index;
            while(++i != index) {
                if(i >= TABLE_SIZE)
                    i = 0;
                if(strcmp(hash_table[i]->name, name) == 0)
                    return i;
            }
        }

    }
    else
        return -1;
}