#include <stdio.h>
#include "header.h"
#include "st

int main() {
    FILE *fp = fopen("input.txt", "r");
    FILE *gp = fopen("output.txt", "w+");
    Queue *queue = NULL;
    uint32_t buffer;

    while(!feof(fp) && fscanf(fp, "%d", &buffer))
        enqueue(&queue, buffer);


    print_queue(gp, queue);
    Node *f = find_front(queue);
    Node *t = find_tail(queue);

    if (f == NULL || t == NULL)
        fprintf(gp, "\nThe Queue is Empty");
    else {
        fprintf(gp, "\nFront of the queue: (0x%p)\t\"%u\"\nTail of the queue: (0x%p)\t\"%u\"",
               f, f->value, t, t->value);
    }
    fprintf(gp, "\n");
    dequeue(&queue);
    fprintf(gp, "\n");
    print_queue(gp, queue);
    return 0;
}
