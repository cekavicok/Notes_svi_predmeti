//REKURZIVNO sa matricom susednosti
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int sp;
    int* pod;
    int cap;
} Stack;

int mat[MAX][MAX];
int visit[MAX];

Stack* INITstack(int size) {
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    if(stack == NULL) {
        free(stack);
        return NULL;
    }
    stack->pod = (int *)malloc(sizeof(int)*size);
    
    if(stack->pod == NULL) {
        free(stack);
        return NULL;
    }
    stack->sp = -1;
    stack->cap = size;
    return stack;
}

void PUSH(Stack* stack, int a){
    stack->pod[++stack->sp] = a;
}

int POP(Stack* stek) {
    return stek->pod[stek->sp--];
}

int EMPTY(Stack* stek){
    return stek->sp == -1;
}

void DFS(int v, int n) {
    Stack* stek = INITstack(n);
    for(int i=0; i<n; i++){
        visit[i] = 0;
    }
    PUSH(stek, v);
    while(!EMPTY(stek)) {
        v = POP(stek);
        if(visit[v] == 0){
            visit[v] = 1;
            printf("%d", v);
            for(int u=0; u<n; u++){ //for(int u=n; u>=0; u--){...} da bi bilo isto kao rekurzija
                if(mat[v][u] == 1 && visit[u] == 0){
                    PUSH(stek, u);
                }
            }
        }
    }
    free(stek->pod);
    free(stek);
}