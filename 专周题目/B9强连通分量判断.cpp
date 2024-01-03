#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100
struct Graph {
    int vertices;
    int edges[MAX_NODES][MAX_NODES];
};
void initializeGraph(struct Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            g->edges[i][j] = 0;
        }
    }
}
void addEdge(struct Graph *g, int src, int dest) {
    g->edges[src][dest] = 1;
}
void dfs(struct Graph *g, int v, bool visited[]) {
    visited[v] = true;
    for (int i = 0; i < g->vertices; ++i) {
        if (g->edges[v][i] && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}
bool isStronglyConnected(struct Graph *g) {
    bool visited[MAX_NODES] = { false };
    dfs(g, 0, visited);
    for (int i = 0; i < g->vertices; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    struct Graph reverseGraph;
    initializeGraph(&reverseGraph, g->vertices);
    for (int i = 0; i < g->vertices; ++i) {
        for (int j = 0; j < g->vertices; ++j) {
            if (g->edges[i][j]) {
                addEdge(&reverseGraph, j, i);
            }
        }
    }
    for (int i = 0; i < g->vertices; ++i) {
        visited[i] = false;
    }
    dfs(&reverseGraph, 0, visited);
    for (int i = 0; i < g->vertices; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    struct Graph g;
    int vertices = 5;
    initializeGraph(&g, vertices);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 4);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 1);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 0);
    addEdge(&g, 3, 2);
    addEdge(&g, 4, 2);
    if (isStronglyConnected(&g)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

