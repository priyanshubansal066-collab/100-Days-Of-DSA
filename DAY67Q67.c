#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int stack[MAX], top = -1;

void push(int val) {
    stack[++top] = val;
}


void dfs(int v, int visited[], int adj[MAX][MAX], int n) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            dfs(i, visited, adj, n);
        }
    }

    push(v); 
}

void topoSort(int adj[MAX][MAX], int n) {
    int visited[MAX] = {0};

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, visited, adj, n);
        }
    }

    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n = 6;

    
    int adj[MAX][MAX] = {0};

   
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topoSort(adj, n);

    return 0;
}