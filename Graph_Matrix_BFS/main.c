#include <stdio.h>
#include "graph.h"

int main() {
    Graph *graph = create_graph(4);
    Queue *queue = NULL;
    hash_table *table = create_linked(4);
    insert_inList(&table, graph, queue);

    for(int i = 0; i < 4; i++) {
        Node1 *temp = table->array[i];

        while(temp) {

            temp = temp->next;
        }
        puts("\n");
    }

    return 0;
}
