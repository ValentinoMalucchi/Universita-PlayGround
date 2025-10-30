/*
Data una matrice quadrata A di dimensione MxM, calcolare la somma degli elementi di una sottomatrice 
quadrata B di testa di dimensione NxN usando una funzione sum_submatrix con prototipo:
int sum_submatrix(int **matrix, int n) con M≥N≥0 (con sottomatrice di testa si intende la 
sottomatrice che inizia dall'angolo superiore sinistro della matrice A). Si allochi la matrice A
dinamicamente, per righe.
Inserire dallo stdin prima la dimensione della matrice A, seguita dalla dimensione della matrice B, 
e poi gli elementi della matrice A, inseriti per righe, uno per ogni riga dello stdin. 
Stampare in output, in una funzione, il valore della somma degli elementi 
della matrice di testa B.
Esempio di input:
4 ( M )
2 ( N )

1   2   3   4
5   6   7   8   
9   10  11  12
13  14  15  16

Esempio di output:
1+2+5+6 = 14
*/

#include <stdio.h>
#include <stdlib.h>

int sum_submatrix(int **matrix, int n){
    int i, j, somma = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            somma += matrix[i][j];
        }
    }
    return somma;
}

int main(){
    int i, j, m, n, unico;

    printf("inserisci dim matrice A:    \n");
    scanf("%d",&m);
    printf("inserisci dim matrice B:    \n");
    scanf("%d",&n);

    do{
        unico = 1;
        if(m < 1 || m < n){
            printf("dimensione di A non valida, inserisci dimensione:    \n");
            scanf("%d",&m);
            unico = 0;
        }
        if(n < 1){
            printf("dimensione di B non valida, inserisci dimensione:   \n");
             scanf("%d",&n);
            unico = 0;
        }
    } while(!unico);

    int** A = (int **)malloc(m * sizeof(int*));  //allocazione dinamica matrice 

    for( i = 0 ; i < m ; i++ ){
        A[i] = (int *)malloc(m * sizeof(int));
    }

    printf("inserire elementi matrice A della prima riga:   \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("la somma dei valori è %d \n",sum_submatrix(A,n));
    return 0;
}
