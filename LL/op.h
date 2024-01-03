
#ifndef LL_OP_H
#define LL_OP_H

#include <stdbool.h>
typedef struct linked_list{
    int data;
    struct linked_list *next;
}Node;
extern void *malloc(size_t size);
extern int strcmp (const char* str1, const char* str2);
extern char *strupr(char *str);
extern void free(void *ptr);
void AF(int x, Node **head);
void AL(int x, Node **head);
void DF(Node **head);
void DL(Node **head);
void doom_the_list(Node **head);
void print_all(Node *head);
void DE(int x, Node **head);
void PRINT_F(int x, Node *head);
void PRINT_L(int x, Node *head, int a);
#endif //LL_OP_H