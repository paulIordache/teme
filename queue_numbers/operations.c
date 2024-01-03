#include "header.h"
#include <stdio.h>

void enqueue(Queue **queue, uint32_t number) {
    if (*queue == NULL) {
        //allocate space for the queue and for the first element of the list
        Queue *temp = (Queue *) malloc(sizeof(Queue));
        temp->size = 1;

        //assign a substitute Node variable
        Node *subst = malloc(sizeof(Node));
        temp->elements = subst;

        //allocate space for the string & assign it
        subst->value = number;

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
        subst->value = number;

        (*queue)->size++;
        (*queue)->front = subst;

    }
}

void print_queue(FILE *gp, Queue *queue) {
    if(queue->front == NULL || queue->tail == NULL) {
        fprintf(gp, "The Queue is EMPTY");
        return;
    }

    Node *subst = queue->front;

    while(subst) {
        fprintf(gp, "\t(0x%p)\t\"%d\"\n", subst, subst->value);
        subst = subst->next;
    }
}


void dequeue(Queue **queue) {
    if (queue == NULL)
        return;
    //create a Node which will be deleted
    Node *del = (*queue)->tail;
    (*queue)->tail = del->prev;
    if((*queue)->tail != NULL)
        (*queue)->tail->next = NULL;

    //free all of allocated memory, avoid memory leaks
    (*queue)->size--;
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

Queue *init_queue(Queue *queue) {
    queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}