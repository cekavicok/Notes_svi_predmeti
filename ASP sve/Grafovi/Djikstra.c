/*
PSEUDO KOD 
Djikstra(W){
    S = {x} //obrada prvog cvora, S je skup predjenih cvorova
    for(int i=0; i<n; i++){
        d[i] = w[x][i];
        if(w[x][i] != INF) t[i] = x;
        else t[i] = 0;
    }
    for(int k=0; k<n-1; k++){
        find min {d[i] : i pripada (V-S)} //trazi najmanje d[i] takvo da i ne pripada S tj predjenim cvorovima
        S = S unija i;
        for(int j=0; j<n; j++){
            if(j pripada (V-S)){
                if(d[i] + w[i][j] < d[j]){
                    d[j] = d[i] + w[i][j];
                    t[j] = i;
                }
            }
        }
    }
}
*/
#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 1000000000

int w[MAX][MAX];   // matrica težina
int d[MAX];        // najkraća rastojanja
int t[MAX];        // prethodnici
int S[MAX];        // skup obrađenih čvorova (1 = jeste, 0 = nije)


void Djikstra(int n, int x){
    for(int i=0; i<n; i++){
        d[i] = w[x][i];
        if(w[x][i] < INF && i != x) t[i] = x;
        else t[i] = -1;
    }

    d[x] = 0;
    S[x] = 1;

    for(int k=1; k<n; k++){
        int min = INF, u = -1;
        for(int i=0; i<n; i++){
            if(!S[i] && d[i] < min){
                min = d[i];
                u = i;
            }
        }
        if(u == -1){
            break;
        }

        S[u] = 1;
        for(int j=0; j<n; j++){
            if(!S[j] && w[u][j] < INF && d[j] > d[u] + w[u][j]){
                d[j] = d[u] + w[u][j];
                t[j] = u;
            }
        }
    }
}