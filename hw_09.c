#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10


typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int visited[MAX_VERTICES];
    int numVertices;
} Graph;


void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}


void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

void resetVisited(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        g->visited[i] = 0;
    }
}


void DFS(Graph* g, int vertex) {
    printf("%d ", vertex);
    g->visited[vertex] = 1;

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !g->visited[i]) {
            DFS(g, i);
        }
    }
}

void BFS(Graph* g, int startVertex) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    g->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !g->visited[i]) {
                g->visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    Graph g;
    int vertexCount = 6; 
    initGraph(&g, vertexCount);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 4);
    addEdge(&g, 3, 5);

    printf("Derinlik Oncelikli Arama (DFS) Baslangic 0: ");
    DFS(&g, 0);
    printf("\n");

    resetVisited(&g); 

    printf("Genislik Oncelikli Arama (BFS) Baslangic 0: ");
    BFS(&g, 0);
    printf("\n");

    return 0;
}
