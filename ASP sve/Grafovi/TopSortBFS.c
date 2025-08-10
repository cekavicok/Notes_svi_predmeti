#include <stdio.h>
#include <stdlib.h>

void topoSortKahn(int **G, int n) {
    int *indeg = malloc(n * sizeof(int)); //koliko cvorova ulazi u neki cvor
    int *q = malloc(n * sizeof(int));
    int *order = malloc(n * sizeof(int)); //konacan topsort
    int rear = 0, front = 0;
    int cnt = 0;

    for (int u = 0; u < n; u++) { 
        indeg[u] = 0;
        for (int v = 0; v < n; v++) {
            if (G[v][u]) indeg[u]++;
        }
        if (indeg[u] == 0) {
            q[front++] = u;
        }
    }


    while (rear < front) { //prvo se doda prvi kao kod bfs i skinem grane pa dodajem sledece cvorove bez ulaznih grana
        int u = q[rear++];
        order[cnt++] = u;

        for (int v = 0; v < n; v++) {
            if (G[u][v]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q[front++] = v;
                }
            }
        }
    }

    if (cnt < n) {
        printf("Graf ima ciklus — topološko sortiranje nije moguće.\n");
    } else {
        printf("Topološki poredak: ");
        for (int i = 0; i < cnt; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");
    }

    free(indeg);
    free(q);
    free(order);
}

int main(void) {
    int n;
    scanf("%d", &n); 

    int **G = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        G[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    topoSortKahn(G, n);

    for (int i = 0; i < n; i++) {
        free(G[i]);
    }
    free(G);

    return 0;
}
