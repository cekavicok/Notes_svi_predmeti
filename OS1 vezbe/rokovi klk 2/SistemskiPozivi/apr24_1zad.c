#include <stdlib.h>
#include <stdio.h>
#define handle_error(msg) do {printf("Error: %s\n", msg); exit(-1);} while(0)
#define pid_t int
const int N = 10;
void main() {   
    for(int i=0; i < N; i++){
        pid_t pid = fork();
        if(pid < 0){
            handle_error("Fork error");
        }
        else if(pid == 0){ //ovo je onda process dete
            for(unsigned long j = 0; j < (unsigned long)(i+1)*1000000; j++);
            exit(i);
        }  
    }
    for(int i=0; i<N;i++){
        int pi;
        pid_t pid = wait(&pi);
        printf("Dete #%d sa pid = %d je gotov", pi, pid);
    }
    return 0;
}