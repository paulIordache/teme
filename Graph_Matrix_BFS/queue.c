#include "queue.h"
#include <stdio.h>

void enqueue (Queue **queue, uint32_t key) {
    if (*queue == NULL) {
        //allocate space for the queue and for the first element of the list
        Queue *temp = (Queue *) malloc(sizeof(Queue));
        temp->size = 1;

        //assign a substitute Node variable
        Node *subst = malloc(sizeof(Node));
        temp->elements = subst;

        //allocate space for the string & assign it
        subst->name = key;

        subst->next = NULL;
        subst->prev = NULL;

        //set the front and tail to the first element of the list
        temp->front = subst;
        temp->tail = subst;
        *queue = temp;
    } else {
        //allocate space for a Node type variable
        Node *subst = (Node *)malloc(sizeof(*subst));

        //assign next address to the front of queue & previous to NULL
        subst->next = (*queue)->front;
        subst->prev = NULL;
        (*queue)->front->prev = subst;

        //allocate space for the string & assign it
        subst->name = key;

        (*queue)->size++;
        (*queue)->front = subst;

    }
}

void print_queue(Queue *queue) {
    Node *subst = queue->front;

    while(subst) {
        printf("\t(0x%p)\t\"%d\"\n", subst, subst->name);
        subst = subst->next;
    }
}


void dequeue(Queue **queue) {
    if (*queue == NULL) return;

    //create a Node which will be deleted
    Node *del = (*queue)->tail;
    (*queue)->tail = del->prev;
    if ((*queue)->tail != NULL)
        (*queue)->tail->next = NULL;
    (*queue)->size--;

    //free all of allocated memory, avoid memory leaks
    //free(del->name);
    free(del);
}


Node *find_front(Queue *queue) {
    if (queue == NULL) return NULL;

    return queue->front;
}

Node *find_tail(Queue *queue) {
    if(queue == NULL) return NULL;

    return queue->tail;
}


