#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int to;
    struct Node *next;
} Node;

void addEdge(Node **adj, int v, int u) {
    Node *newNode = malloc(sizeof(Node));
    newNode->to = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void topoSortKahn(Node **adj, int n) {
    int *indeg = calloc(n, sizeof(int));
    int *q = malloc(n * sizeof(int));
    int *order = malloc(n * sizeof(int));
    int ql = 0, qr = 0, cnt = 0;

    for (int v = 0; v < n; v++) {
        for (Node *p = adj[v]; p != NULL; p = p->next) {
            indeg[p->to]++;
        }
    }
    for (int v = 0; v < n; v++) {
        if (indeg[v] == 0) q[qr++] = v;
    }

    while (ql < qr) {
        int v = q[ql++];
        order[cnt++] = v;

        for (Node *p = adj[v]; p != NULL; p = p->next) {
            indeg[p->to]--;
            if (indeg[p->to] == 0) {
                q[qr++] = p->to;
            }
        }
    }


    if (cnt < n) {
        printf("Graf ima ciklus — TopSort nije moguć.\n");
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
    int n, m;
    scanf("%d %d", &n, &m); // broj čvorova i ivica

    Node **adj = calloc(n, sizeof(Node*));

    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d %d", &v, &u); // ivica v -> u
        addEdge(adj, v, u);
    }

    topoSortKahn(adj, n);

    for (int i = 0; i < n; i++) {
        Node *p = adj[i];
        while (p) {
            Node *tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    free(adj);

    return 0;
}
