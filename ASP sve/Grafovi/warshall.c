/*
PSEUDO KOD 

WARSHALL
P = A
for k = 1 to n do
  for i = 1 to n do
    if (p[i,k] == 1) then
      for j = 1 to n do
        p[i,j] = p[i,j] OR p[k,j]
      end for
    end if
  end for
end for
*/
#include <stdlib.h>
#include <stdio.h>
int mat[100][100];

void warshall(int n) { //n je broj cvorova
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            if(mat[i][k] == 1){
                for(int j = 0; j<n; j++){
                    mat[i][j] = mat[i][j] || mat[k][j];
                }
            }
        }
    }

}