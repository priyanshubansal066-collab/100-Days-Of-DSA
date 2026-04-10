#include <stdio.h>
#define MAX 100

int main() {
    int n = 6;

    int adj[MAX][MAX] = {0};

    // Graph (DAG)
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    int indegree[MAX] = {0};

    // Calculate indegree
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Queue
    int queue[MAX], front = 0, rear = 0;

    // Add nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // BFS
    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Cycle check
    if(count != n) {
        printf("\nCycle detected!");
    }

    return 0;
}