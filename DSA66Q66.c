#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Graph as adjacency list
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;
}

// DFS helper function
bool dfs(int node, bool visited[], bool recStack[], Node* graph[]) {
    visited[node] = true;
    recStack[node] = true;

    Node* temp = graph[node];
    while(temp != NULL) {
        int neighbor = temp->dest;
        if(!visited[neighbor] && dfs(neighbor, visited, recStack, graph))
            return true;
        else if(recStack[neighbor])
            return true;
        temp = temp->next;
    }

    recStack[node] = false;
    return false;
}

// Check cycle
bool isCyclic(Node* graph[], int V) {
    bool visited[V];
    bool recStack[V];

    for(int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 0; i < V; i++) {
        if(!visited[i] && dfs(i, visited, recStack, graph))
            return true;
    }

    return false;
}

int main() {
    int V = 4;
    Node* graph[V];
    for(int i=0;i<V;i++) graph[i]=NULL;

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 2);

    if(isCyclic(graph, V))
        printf("Graph contains a cycle\n");
    else
        printf("Graph does not contain a cycle\n");

    return 0;
}