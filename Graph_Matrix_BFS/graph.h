
#ifndef GRAPH_MATRIX_BFS_GRAPH_H
#define GRAPH_MATRIX_BFS_GRAPH_H

#include <stdint.h>
#include <stdbool.h>
#include "queue.h"

typedef struct _graph {
    uint16_t elements;
    uint32_t **matrix;
}Graph;

typedef struct _node {
    struct _node *next;
    uint32_t data;
}Node1;

typedef struct _hashtable {
    Node1 **array;
    uint32_t size;
}hash_table;


Graph *create_graph(uint32_t  number);
void insert_inList(hash_table **ht, Graph *gh, Queue *queue);
hash_table *create_linked(uint32_t number);
#endif //GRAPH_MATRIX_BFS_GRAPH_H
