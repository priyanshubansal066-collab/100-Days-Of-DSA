#include <stdio.h>
#define MAX 100
#define INF 9999

int main() {
    int n = 5;

    // Adjacency matrix
    int graph[MAX][MAX] = {
        {0, 10, 0, 30, 100},
        {0, 0, 50, 0, 0},
        {0, 0, 0, 0, 10},
        {0, 0, 20, 0, 60},
        {0, 0, 0, 0, 0}
    };

    int dist[MAX], visited[MAX] = {0};

    // Initialize distances
    for(int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    int source = 0;
    dist[source] = 0;

    for(int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;

        // Find minimum distance node
        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update neighbors
        for(int v = 0; v < n; v++) {
            if(!visited[v] && graph[u][v] != 0 &&
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for(int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }

    return 0;
}