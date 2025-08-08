/*
PSEUDO KOD 


FLOYD(W) {
    D = W
    for(k=1; k<n; k++){
        for(i=1; i<n; i++){
            for(j=1; j<n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j]
                }
            }
        }
    }
}
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define inf 1000000

int d[MAX][MAX]; //treba lepo da se pozove malloc za svaku matricu ali me je mrzelo lol
int ecc[MAX];
int t[MAX][MAX];

void floyd(int n){
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][j] > d[i][k] + d[k][j] && d[i][k] < inf && d[k][j] < inf) {
                    d[i][j] = d[i][k] + d[k][j];
                    t[i][j] = t[k][j];
                }
            }
        }
    }
}

void path(int i, int j){
    if(i == j){
        printf("%d", i);
    }
    else if(t[i][j] == 0){
        printf("Nema puta od %d do %d\n", i, j);
    } else {
        path(i, t[i][j]);
        printf("%d ", j);
    }
}


