#include "Graph.h"

struct node {
    int v;
    struct node *next;
};

struct graph {
    int nV;

    struct node **adjList;
};

Graph GraphNew(int nV) {
    Graph g = malloc(sizeof(struct graph));
    g->nV = nV;
    g->adjList = calloc(nV, sizeof(struct node *));
    return g;
}

void GraphInsertEdge(Graph g, int v, int w) {
    g->adjList[v] = linkedListInsert(g->adjList[v], w);
    g->adjList[w] = linkedListInsert(g->adjList[w], v);
}