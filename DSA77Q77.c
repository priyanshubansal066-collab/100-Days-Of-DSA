#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
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
    adj[2][3] = adj[3][2] = 1;

    int count = 0;

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, adj, n);
            count++;
        }
    }

    printf("Number of connected components: %d", count);

    return 0;
}