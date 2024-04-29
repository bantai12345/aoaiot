#include <stdbool.h>
#include <stdio.h>

#define MAX_V 10 

void printSolution(int color[], int V);
bool isSafe(int v, bool graph[][MAX_V], int color[], int c, int V);
bool graphColoringUtil(bool graph[][MAX_V], int m, int color[], int v, int V);
bool graphColoring(bool graph[][MAX_V], int m, int V);

void printSolution(int color[], int V) {
    int i;
    printf("Vertex\tColor\n");
    for (i = 1; i <= V; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

bool isSafe(int v, bool graph[][MAX_V], int color[], int c, int V) {
    int i;
    for (i = 1; i <= V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(bool graph[][MAX_V], int m, int color[], int v, int V) {
    if (v == V + 1) {
        return true;
    }
    int c;
    for (c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[][MAX_V], int m, int V) {
    int color[MAX_V + 1];
    int i;
    for (i = 1; i <= V; i++) {
        color[i] = 0;
    }
    if (graphColoringUtil(graph, m, color, 1, V) == false) {
        printf("Solution does not exist\n");
        return false;
    }
    printf("Solution exists. Assigned colors:\n");
    printSolution(color, V);
    return true;
}

int main() {
    int V, m, i, j;
    printf("Enter the number of vertices (maximum %d): ", MAX_V);
    scanf("%d", &V);

    bool graph[MAX_V][MAX_V];
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (i = 1; i <= V; i++) {
        for (j = 1; j <= V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);
    return 0;
}

