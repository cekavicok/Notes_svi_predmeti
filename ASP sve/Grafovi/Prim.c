/*
Primov algoritam se koristi za trazenje: MST -> minimum spanning tree
sluzi da povezemo sve cvorove u grafu sa najmonjom tezinom tako da nema ciklusa
*/

/*
PSEUDO KOD 

PRIM(G, n):
    visited[0 : n-1] = false;
    min_edge[0 : n-1] = infinity;
    parent[0 : n-1] = -1;

    min_edge[0] = 0;

    for i to n-1:
        u = CVOR SA NAJMANJOM VREDNOSCU MIN_EDGE KOJI JOS NIJE U MST
        visited[u] = true;
        for svaki cvor v:
            if(grana(u,v) postoji i visited[v] = false i w(u,v) < min_edge[v]){
                min_edge[v] = w(u,v)
                parend[v] = u;
            }
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
//treba da se doda inicijalizacija matrice i tjt radi skroz valjda

int minWeight(bool* visited, int* minW, int n){
    int min = INT_MAX;
    int min_index = -1;
    for(int i = 0; i < n; i++) {
        if(!visited && minW[i] < min){
            min_index = i;
            min = minW[i];
        }
    }
    return min_index;
}


void printMST(int* parent, int** graph, int n) { //pisao chet dzi pi ti ovu fju mrzelo me
    int total = 0;
    printf("Grana \tTežina\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Ukupna težina MST: %d\n", total);
}


void PRIMs(int** graph, int n, int v) { //v je prvi cvor koji se posecuje
    int* parent = (int*)malloc(sizeof(int)*n);
    int* minW = (int*)malloc(sizeof(int)*n); //najmanja tezina ka cvoru npr ako je 1 onda se gledaju sve njegove grane i trazi se najmanja tezina
    bool* visited = (bool*)malloc(sizeof(bool)*n);



    for(int i=0; i<n; i++){
        visited[i] = false;
        minW[i] = INT_MAX;
        parent[i] = -1;
    }

    minW[v] = 0;

    for(int i=0; i<n-1; i++) { //manje od n-1 jer sam prvi vec prosao lol
        v = minWeight(visited, minW, n);
        visited[v] = true;

        for(int u=0; u < n; u++){
            if(graph[v][u] != 0 && !visited[u] && graph[v][u] < minW[u]){
                parent[u] = v;
                minW[u] = graph[v][u];
            }
        }

    }

    printMST(parent, graph, n);
}
