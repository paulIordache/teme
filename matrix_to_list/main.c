#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <malloc.h>

int G[4][4] = {0, 0, 1, 1,
               0, 0, 0, 1,
               1, 0, 0, 0,
               1, 1, 0, 0 } , visited[4];

typedef struct Node{
    uint32_t data;
    struct Node *next;
}Node;

typedef struct List {
    uint32_t size;
    Node **array;
}List;

List *List_create(uint32_t size) {
    List *lst = malloc(sizeof(List));
    lst->size = size;

    lst->array = calloc(sizeof(List *), lst->size);
    return lst;
}

void List_insert(List **lst, uint32_t j, uint32_t index) {
    if(*lst == NULL) return;

    Node *e = malloc(sizeof(Node));
    e->data = j;

    e->next = (*lst)->array[index];
    (*lst)->array[index] = e;

}

void DFS(List *lst)
{
    for(int i = 0; i < 4; i++) {
        printf("%d -> ", i);
        for (int j = 0; j < 4; j++)
            if (G[i][j] == 1)
                printf("%d -> ", j);
        puts("\n");
    }

}

void print_list(List *lst) {
    uint32_t i;
    for(i = 0; i < lst->size; i++) {
        if(lst->array[i] != NULL) {
            printf("\n%d -> ", i);
            Node *tmp = lst->array[i];
            while(tmp != NULL) {
                printf("%d", tmp->data);
                tmp = tmp->next;
            }
        }
    }
}

int main() {
    List *lst = List_create(4);
    DFS(lst);
    print_list(lst);
    return 0;
}
