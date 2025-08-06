#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct {
    int v, u;
    int weight;
} Edge;

Edge edges[MAX];
Edge mst[MAX];
int parent[MAX];
int n, m; // n = broj čvorova, m = broj grana


//nije implementiran ceo vec samo potpisi fja i sam algoritam
int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

// FIND funkcija (sa path compression)
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// UNION funkcija
void union_sets(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[px] = py;
}

int kruskal() {
    int i, count = 0;
    int totalWeight = 0;

    // Inicijalizacija disjunktnih skupova
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Sortiraj grane po težini
    qsort(edges, m, sizeof(Edge), compare);

    for (i = 0; i < m && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u) != find(v)) {
            mst[count++] = edges[i];
            union_sets(u, v);
            totalWeight += w;
        }
    }

    return totalWeight;
}
