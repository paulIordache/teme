#include <stdio.h>



void addEdge(int G[10][10], int x, int y) {
    G[x][y] = 1;
    G[y][x] = 1;
}

void print_matrix(int G[10][10], int n) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", G[i][j]);
        puts("\n");
    }
}

void init_matrix(int G[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            G[i][j] = 0;
    }
}

void isCycle(int G[10][10], int n) {
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if (G[i][j] == 1) count++;
        }
        if (count < 2) {
            printf("No cycle\n");
            return;
        }

    }
    printf("Cycle\n");
}

void DFS(int i, int G[10][10],int n, int visited[10], int level)
{
    if (i == level) {
        printf("STOP\n");
        return;
    }
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(j=0;j<n;j++)
        if(!visited[j]&&G[i][j]==1){
            if(j < level)
                DFS(j, G, n, visited, level);
        }

}

void init_visit(int visited[10]) {
    for(int i = 0; i < 10; i++)
        visited[i] = 0;
}

int main() {
    int G[10][10];
    int T[10][10];
    init_matrix(G, 3);
    init_matrix(T, 6);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 2);

    addEdge(T, 0, 1);
    addEdge(T, 0, 2);
    addEdge(T, 1, 3);
    addEdge(T, 1, 4);
    addEdge(T, 4, 5);
    printf("FIRST GRAPH: \n");
    print_matrix(G, 3);
    isCycle(G, 3);
    puts("\n");
    printf("SECOND GRAPH: \n");
    print_matrix(T, 6);
    isCycle(G, 6);
    int visited_T[10];
    init_visit(visited_T);
    printf("DFS traversal of graph T: ");
    DFS(1, T, 6, visited_T, 2);
    return 0;
}
