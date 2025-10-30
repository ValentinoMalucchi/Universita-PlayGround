/*
Data una matrice quadrata A di dimensione MxM, inserire dallo stdin prima la dimensione
della matrice A, e poi gli elementi della matrice A, inseriti per righe, uno per ogni riga dello
stdin.
Usando una funzione, cambiare il segno dei valori sulla diagonale principale della matrice A
e stampare infine il contenuto della matrice, una riga per ogni riga dello stdout, come nel
seguente esempio.
Esempio di Input:
3
1
2
3
4
5
6
7
8
9
Esempio di output:
-1 2 3
4 -5 6
7 8 -9
*/

#include <stdio.h>
#include <stdlib.h>

int cambiasegno(int **matrix,int m){
    int i,j;

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            if(i == j){
                matrix[i][j] = -matrix[i][j];
            }
        }
    }
}

int main(){
    int m,i,j;

    printf("inserisci dim matrice:  \n");
    scanf("%d",&m);

    int** A = (int **)malloc(m * sizeof(int*));

    for(i=0;i<m;i++){
        A[i] = (int *)malloc(m * sizeof(int));
    }

    printf("inserisci elementi matrice A:   \n");
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            scanf("%d",&A[i][j]);
        }
    }

    cambiasegno(A,m);
    printf("la matrice cambiata di segno è: \n");
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            printf("%d  ",A[i][j]);
        }
        printf("\n");
    }

    // Libero memoria allocata
    for(i = 0; i < m; i++) {
        free(A[i]);
    }

    free(A);
    return 0;
}
