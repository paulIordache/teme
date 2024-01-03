
#ifndef STACK_IMP_ST4CK_H
#define STACK_IMP_ST4CK_H
#include <inttypes.h>
#include <malloc.h>
#include <string.h>

typedef struct _node {
    char *name;
    struct _node *prev, *next;
}Node;

typedef struct _stack {
    Node *stack_pointer, *base_pointer;
    uint32_t size;
    Node *elements;
}Stack;

void push(Stack **stack, const char *name);
void pop(Stack **stack);
Node *returnBase_pointer(Stack *stack);
Node *returnStack_pointer(Stack *stack);
void print_stack(Stack *stack);

#endif //STACK_IMP_ST4CK_H
