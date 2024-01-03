
#include <stdio.h>
#include "st4ck.h"

void push(Stack **stack, const char *name) {
    if (*stack == NULL) {
        Stack *temp = (Stack *)malloc(sizeof(Stack));
        temp->size = 1;

        Node *subst = (Node *)malloc(sizeof(Node));
        temp->elements = subst;

        subst->name = strdup(name);
        subst->next = NULL;
        subst->prev = NULL;

        temp->base_pointer = subst;
        temp->stack_pointer = subst;

        *stack = temp;
    }
    else {
        Node *subst = (Node *)malloc(sizeof(Node));

        subst->next = NULL;
        subst->prev = (*stack)->base_pointer;
        (*stack)->base_pointer->next = subst;

        subst->name = strdup(name);

        (*stack)->size++;
        (*stack)->base_pointer = subst;
    }
}

void pop(Stack **stack) {
    if (*stack == NULL) return;
    Node *del = (*stack)->base_pointer;

    (*stack)->base_pointer = (*stack)->base_pointer->prev;
    (*stack)->base_pointer->next = NULL;
    free(del->name);
    del->prev = NULL;

    free(del);
}

Node *returnBase_pointer(Stack *stack) {
    if (stack == NULL) return NULL;

    return stack->base_pointer;
}

Node *returnStack_pointer(Stack *stack) {
    if (stack == NULL) return NULL;

    return stack->stack_pointer;
}

void print_stack(Stack *stack) {
    Node *temp = stack->base_pointer;

    while (temp) {
        printf("\t(0x%p)\t\"%s\"\n", temp, temp->name);
        temp = temp->prev;
    }
}