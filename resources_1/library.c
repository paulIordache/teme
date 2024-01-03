#include "library.h"
#include <stdio.h>
#include <stdbool.h>

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
    Node *subst = queue->front;

    while(subst) {
        fprintf(gp, "\t(0x%p)\t\"%d\"\n", subst, subst->value);
        subst = subst->next;
    }
}


void dequeue(Queue **queue) {
    //create a Node which will be deleted
    Node *del = (*queue)->tail;
    (*queue)->tail = del->prev;
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

void shortest_path(int G[MAX][MAX],int n,int startnode)
{

    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count, min_distance, next_node, i, j;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        min_distance=INFINITY;

        for(i=0;i<n;i++)
            if(distance[i]<min_distance&&!visited[i])
            {
                min_distance=distance[i];
                next_node=i;
            }

        visited[next_node]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(min_distance+cost[next_node][i]<distance[i])
                {
                    distance[i]=min_distance+cost[next_node][i];
                    pred[i]=next_node;
                }
        count++;
    }
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistance of node%d=%d",i,distance[i]);
            printf("\nPath=%d",i);
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
        }
}

void inter(int *a, int n1, int *b, int n2, int *c) {
    int pa = 0, pb = 0, pc = 0;
    while (pa < n1 && pb < n2) {
        if(a[pa] <= b[pb]) {
            c[pc] = a[pa];
            pa++;
            pc++;
        }
        else {
            c[pc] = b[pb];
            pb++;
            pc++;
        }
    }

    while(pa < n1) {
        c[pc] = a[pa];
        pc++;
        pa++;
    }

    while(pb < n2) {
        c[pc] = b[pb];
        pb++;
        pc++;
    }


}

void print_vector(int *a, int n1) {
    for(int i = 0; i < n1; i++)
        printf("%d ", a[i]);
    puts("\n");
}

void merge_sort(int **x, int n) {
    int step = 1, *b = malloc(sizeof(int) * n), *q, *a = *x;
    for(int i = 0; i < n; i++) b[i] = a[i];
    while(step <= n) {
        int i = 0;
        for(; i <= n - 2 * step ; i += 2*step)
            inter(&(a[i]), step, &(a[i+step]), step, &(b[i]));

        int r = n - i;
        if(r > step) inter(&(a[i]), step, &(a[i+step]), r - step, &(b[i]));
        else for(; i < n; i++) b[i] = a[i];

        step *= 2;
        q = a;
        a = b;
        b = q;
    }
    *x = a;
}

void DFS(int i, int G[10][10], bool visited[10],int n)
{
    int j;
    printf("%d ",i+1);
    visited[i]=1;
    for(j=0;j<n;j++)
        if(!visited[j]&&G[i][j]==1)
            DFS(j, G, visited, n);
}

void BFS(int start, int n, int G[10][10])
{
    Queue *q = malloc(sizeof(Queue));
    bool* visited = malloc(sizeof(bool) * n);
    for(int i=0;i<n;i++)
        visited[i] = false;
    visited[start] = true;
    enqueue(&q, start);
    while(q != NULL)
    {
        Node *f = find_front(q);
        uint32_t node = f->value;
        dequeue(&q);
        printf("%u ", node);
        for(int i=0;i<n;i++)
        {
            if(G[node][i]==1 && !visited[i])
            {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    free(visited);
}
