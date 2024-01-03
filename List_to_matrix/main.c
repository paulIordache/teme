#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
int matrix[4][4];

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
    Node *tmp = malloc(sizeof(Node));
    Node *temp = malloc(sizeof(Node));

    lst->array[0] = tmp;
    tmp->data = 2;
    temp->data = 3;
    tmp->next = temp;
    temp->next = NULL;

    Node *tmp1 = malloc(sizeof(Node));
    Node *temp2 = malloc(sizeof(Node));
    lst->array[1] = tmp1;
    lst->array[2] = temp2;
    tmp1->data = 3;
    temp2->data = 0;
    tmp1->next = NULL;
    temp2->next = NULL;

    Node *tmp3 = malloc(sizeof(Node));
    Node *temp3 = malloc(sizeof(Node));
    lst->array[3] = tmp3;
    tmp3->data = 0;
    temp3->data = 1;
    tmp3->next = temp3;
    temp3->next = NULL;

    return lst;
}

void DFS(List *lst) {
    for(int i = 0; i < 4; i++) {
        Node *tmp = lst->array[i];
        while(tmp) {
            matrix[i][tmp->data] = 1;
            tmp = tmp->next;
        }
    }
}

void print() {
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        puts("\n");
    }


}

int main() {
    List *lst = List_create(4);
    DFS(lst);
    print();

    return 0;
}
