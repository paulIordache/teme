#include <stdio.h>
#include "queue.h"


int main() {
    FILE *fp = fopen("input.txt", "r");
    Queue *queue = NULL;
    char *buffer = malloc(MAX_NAME);

    while(!feof(fp) && fgets(buffer, MAX_NAME, fp) != NULL) {
        buffer[strcspn(buffer, "\n\r")] = 0;
        enqueue(&queue, buffer);
    }

    print_queue(queue);
    Node *f = find_front(queue);
    Node *t = find_tail(queue);

    if (f == NULL || t == NULL)
        printf("\nThe Queue is Empty");
    else {
        printf("\nFront of the queue: (%p)\t\"%s\"\nTail of the queue: (%p)\t\"%s\"",
               f, f->name, t, t->name);
    }
    printf("\n");
    dequeue(&queue);
    puts("\n");
    print_queue(queue);
    return 0;
}
