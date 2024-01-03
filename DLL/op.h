
#ifndef DLL_OP_H
#define DLL_OP_H
#define MAX_NAME 64
#define MAX_RANGE 1000000
#include <stdbool.h>
#include <stdio.h>

typedef struct DLL{
    char name[MAX_NAME];
    struct DLL *right;
    struct DLL *left;
}Node;

unsigned int ascii(char *word);

void add_node(Node **head, char *word, Node **tail);


#endif //DLL_OP_H
