#include <stdio.h>

#define MAX 100
#define INF 9999

// Edge structure
struct Edge {
    int src, dest, weight;
};

int main() {
    int V = 5; // vertices
    int E = 8; // edges

    struct Edge edges[] = {
        {0,1,6}, {0,2,7}, {1,2,8}, {1,3,5},
        {1,4,-4}, {2,3,-3}, {2,4,9},
        {3,1,-2}, {4,3,7}
    };

    int dist[MAX];

    // Initialize
    for(int i = 0; i < V; i++) {
        dist[i] = INF;
    }

    int source = 0;
    dist[source] = 0;

    // Step 1: Relax edges V-1 times
    for(int i = 1; i <= V-1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 2: Check negative cycle
    for(int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative weight cycle detected!\n");
            return 0;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for(int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }

    return 0;
}