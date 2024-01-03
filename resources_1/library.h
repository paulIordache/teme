#ifndef RESOURCES_1_LIBRARY_H
#define RESOURCES_1_LIBRARY_H

#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#define MAX 10
#define INFINITY 9999

/*
 * QUEUE IMPLEMENTATION FOR NUMBERS
 */

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

/*
 * DIJKSTRA IMPLEMENTATION
 */
void shortest_path(int G[MAX][MAX], int n, int startnode);
void print_vector(int *a, int n1);

/*
 * ITERATIVE MERGE SORT IMPLEMENTATION
 */
void merge_sort(int **x, int n);
void inter(int *a, int n1, int *b, int n2, int *c);

/*
 *
 */
#endif //RESOURCES_1_LIBRARY_H
