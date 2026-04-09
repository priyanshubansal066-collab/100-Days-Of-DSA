#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX]; // array of lists

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v) {
    // u → v
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // v → u (undirected)
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Print graph
void printGraph(int n) {
    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        printf("%d -> ", i);
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n = 3;

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    addEdge(0, 1);
    addEdge(1, 2);

    printGraph(n);

    return 0;
}