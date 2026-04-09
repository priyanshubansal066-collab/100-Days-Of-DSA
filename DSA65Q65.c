#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS for cycle detection
bool dfs(int v, int parent) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, v))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }

        temp = temp->next;
    }
    return false;
}

// Check cycle in graph
bool hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int n = 4;

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    addEdge(0, 1);
    addEdge(1, 3);
    addEdge(3, 2);
    addEdge(2, 0); // cycle edge

    if (hasCycle(n))
        printf("Cycle Detected");
    else
        printf("No Cycle");

    return 0;
}