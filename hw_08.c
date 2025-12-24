#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX] = {
    {0, 1, 1, 0, 0, 0, 0}, 
    {1, 0, 1, 0, 0, 0, 0}, 
    {1, 1, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 0}  
};

int visited[MAX];
int numNodes = 7; 

void DFS(int node);

int main(void) {
    int i;
    int clusterCount = 0;

    for (i = 0; i < numNodes; i++) {
        visited[i] = 0;
    }

    printf("Graph Clusters:\n");
    printf("--------------------------------------\n");

    for (i = 0; i < numNodes; i++) {
        if (visited[i] == 0) {
            clusterCount++;
            printf("Cluster %d: { ", clusterCount);
            DFS(i); 
            printf("}\n");
        }
    }

    printf("\nTotal Clusters Found: %d\n", clusterCount);

    return 0;
}

void DFS(int node) {
    int i;
    
    visited[node] = 1;
    printf("%d ", node); 

    for (i = 0; i < numNodes; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}
