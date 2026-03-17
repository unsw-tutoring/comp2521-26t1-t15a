#include "Graph.h"

struct graph {
    int nV;
    bool **adjMatrix;
};

Graph GraphNew(int nV) {
    Graph g = malloc(sizeof(struct graph));
    g->nV = nV;
    g->adjMatrix = malloc(nV * sizeof(bool *));
    for (int i = 0; i < nV; i++) {
        g->adjMatrix[i] = calloc(nV, sizeof(bool));
    }
    return g;
}

void GraphInsertEdge(Graph g, int v, int w) {
    g->adjMatrix[v][w] = true;
    g->adjMatrix[w][v] = true;
}

// if (g->adjMatrix[v][w])