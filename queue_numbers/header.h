

#ifndef QUEUE_IMP_QUEUE_H
#define QUEUE_IMP_QUEUE_H
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#define MAX_NAME 128
typedef struct Node {
    uint32_t value;
    struct Node *prev, *next;
}Node;

typedef struct _queue {
    uint32_t size;
    Node *front, *tail;
    Node *elements;

}Queue;

void enqueue(Queue **queue, uint32_t number);
void print_queue (FILE *gp, Queue *queue);
void dequeue (Queue **queue);
Node *find_tail(Queue *queue);
Node *find_front(Queue *queue);
Queue *init_queue(Queue *queue);

#endif //QUEUE_IMP_QUEUE_H
