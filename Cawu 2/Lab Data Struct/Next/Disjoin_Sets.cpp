#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    int src;
    int dst;
} Edge;

typedef struct Graph {
    int vCount;
    int eCount;
    Edge *edges;
} Graph;

Graph *createGraph(int vCount, int eCount){
    Graph *newGraph = (Graph*) malloc(sizeof(Graph));
    
    newGraph->vCount = vCount;
    newGraph->eCount = eCount;

    newGraph->edges = (Edge*)malloc(sizeof(Edge) * eCount);

    return newGraph;
}

void printGraph(Graph *g){
    for(int i = 0;i < g->eCount; i++){
        printf("Src: %d, Dst: %d\n", g->edges[i].src, g->edges[i].dst);
    }
}

void makeSet(int i, int parent[]){
    parent[i] = i;
}

int find(int parent[], int toFind){
    if(parent[toFind] == toFind) return toFind;
    return parent[toFind] = find(parent, parent[toFind]);
}

void unionSet(int parent[], int src, int dst){
    parent[src] = dst;

}

bool isCyclic(Graph *graph) {
    int parent[graph->vCount + 1];

    for(int i = 1;i <= graph->vCount; i++){
        makeSet(i, parent);
    }

    for(int i = 0; i < graph->eCount; i++){
        int src = graph->edges[i].src;
        int dst = graph->edges[i].dst;

        int srcParent = find(parent, src);
        int dstParent = find(parent, dst);

        if(srcParent != dstParent){
            unionSet(parent, srcParent, dstParent);
        } else {
            return true;
        }
    }
    return false;

}

int main(){
    Graph *graph1 = createGraph(4, 4);

    graph1->edges[0].src = 1;
    graph1->edges[0].dst = 2;
    
    graph1->edges[1].src = 1;
    graph1->edges[1].dst = 3;
    
    graph1->edges[2].src = 1;
    graph1->edges[2].dst = 4; 
    
    graph1->edges[3].src = 3;
    graph1->edges[3].dst = 4;
    
    printGraph(graph1);

    puts("");

    printf("Graph 1 is %s.\n", isCyclic(graph1) ? "cyclic" : "no cyclic");

    return 0;
}