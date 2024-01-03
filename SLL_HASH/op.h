
#ifndef LL_OP_H
#define LL_OP_H

#include <stdbool.h>
#define MAX_NAME 16
#define TABLE_SIZE 8
typedef struct linked_list{
    int data;
    struct linked_list *next;
}Node;
typedef struct{
    char name [MAX_NAME];
}instruction;

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
unsigned int hash_table_lookup (char *name);
bool hash_table_insert(instruction *p);
void print_table();
void init_hash_table();
unsigned int hash(char *name);
#endif //LL_OP_H