#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS
void dfs(int node, int adj[MAX][MAX], int n) {
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[node][i] == 1 && !visited[i]) {
            dfs(i, adj, n);
        }
    }
}

int main() {
    int n = 5;

    int adj[MAX][MAX] = {0};

    // Undirected graph
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Start DFS from node 0
    dfs(0, adj, n);

    // Check all visited
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            printf("Graph is NOT connected\n");
            return 0;
        }
    }

    printf("Graph is connected\n");
    return 0;
}