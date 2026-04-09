#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int n; // number of vertices

// Initialize matrix with 0
void initGraph() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
}

// Add edge
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // for undirected graph
}

// Print matrix
void printGraph() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    n = 3; // number of vertices

    initGraph();

    addEdge(0, 1); // A-B
    addEdge(1, 2); // B-C

    printGraph();

    return 0;
}