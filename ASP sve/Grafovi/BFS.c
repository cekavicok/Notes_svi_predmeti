#include <stdio.h>
#define MAX 100

int mat[MAX][MAX];
int visit[MAX];
int FIFOqueue[MAX];
int front, rear= -1; //front je levo, rear desno :) 

void insert(int a){
    rear++;
    FIFOqueue[rear] = a;
}

int delete() { //vraca prvi clan
    return FIFOqueue[front++];
}

int isEmpty(){
    return front > rear;
}

void BFS(int n, int start) { //n je broj grana
    for(int i=0; i < n; i++){
        visit[i] = 0; //svi svu ne poseceni
    }
    visit[start] = 1; //poseti se prvi koji je dat u fji
    print("%d", start);
    insert(start);
    while (!isEmpty()) //dok red nije prazan
    {
        int v = delete(); //uzme se sledeci cvor
        for(int u=0; u < n; v++){ 
            if(mat[v][u] == 1 && visit[u] == 0){
                visit[u] = 1; //isto kao gore
                print("%d", u);
                insert(u);
            }
        }
    }
    
}


