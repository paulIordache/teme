#include <stdio.h>
#include "st4ck.h"
#define MAX_NAME 256

int main() {
    FILE *fp = fopen("input.txt", "r");
    char *buffer = malloc(MAX_NAME);
    Stack *stack = NULL;
    //stack->stack_pointer = NULL;
    //stack->base_pointer = NULL;

    while(!feof(fp) && fgets(buffer, MAX_NAME, fp)) {
        buffer[strcspn(buffer, "\n\r")] = 0;
        push(&stack, buffer);
    }

    print_stack(stack);
    Node *bs = returnBase_pointer(stack), *stk = returnStack_pointer(stack);
    puts("\n");

    printf("\tBase pointer: (0x%p)\t%s\n"
           "\tStack pointer: (0x%p)\t%s\n\n", bs, bs->name, stk, stk->name);

    pop(&stack);

    print_stack(stack);
    return 0;
}
