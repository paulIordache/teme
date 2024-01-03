

#ifndef QUEUE_IMP_QUEUE_H
#define QUEUE_IMP_QUEUE_H
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#define MAX_NAME 128
typedef struct _Node {
    uint32_t name;
    struct _Node *prev, *next;
}Node;

typedef struct _queue {
    uint32_t size;
    Node *front, *tail;
    Node *elements;

}Queue;

void enqueue (Queue **queue, uint32_t key);
void print_queue (Queue *queue);
void dequeue (Queue **queue);
Node *find_tail(Queue *queue);
Node *find_front(Queue *queue);

#endif //QUEUE_IMP_QUEUE_H
