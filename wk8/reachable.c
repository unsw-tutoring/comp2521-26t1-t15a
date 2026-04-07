#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"

void visitDfs(Graph g, Vertex v, bool *visited) {
    visited[v] = true;

    for (int w = 0; w < GraphNumVertices(g); w++) {
        if (GraphIsAdjacent(g, v, w) && !visited[w]) {
            visitDfs(g, w, visited);
        }
    }
}

Set reachable(Graph g, Vertex src) {
    bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
    visitDfs(g, src, visited);

    Set res = SetNew();
    for (int w = 0; w < GraphNumVertices(g); w++) {
        if (visited[w]) SetInsert(res, w);
    }
    return res;
}
