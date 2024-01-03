
#include <malloc.h>
#include "graph.h"
#include "queue.h"

bool state[50];

Graph *create_graph(uint32_t  number) {
    Graph *temp = (Graph *)malloc(sizeof(Graph));

    temp->matrix = malloc(number * sizeof(uint32_t));
    for(int index = 0; index < number; index++)
        *(temp->matrix + index) = malloc(number * sizeof(uint32_t));

    for(int index = 0; index < number; index++)
            state[index] = false;

    for (int index = 0; index < number; index++)
        for (int s_index = 0; s_index < number; s_index++)
            if (index == 0 && s_index == 1 || index == 1 && (s_index == 0 || s_index == 3)
                || index == 3 && s_index == 1)
                temp->matrix[index][s_index]= 1;
            else temp->matrix[index][s_index] = 0;


    temp->elements = number;
    return temp;
}

hash_table *create_linked(uint32_t number) {
    hash_table *ht = malloc(sizeof(hash_table));

    ht->size = number;
    ht->array = calloc(sizeof(Node), ht->size);

    return ht;
}

void insert_inList(hash_table **ht, Graph *gh, Queue *queue) {

    for(uint32_t i = 0; i < gh->elements; i++)
        for(uint32_t j = 0; j < gh->elements; i++){

        }
}