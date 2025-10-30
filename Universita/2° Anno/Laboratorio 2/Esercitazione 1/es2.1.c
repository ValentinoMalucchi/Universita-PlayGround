/*
• Scrivere un programma che legge n e due matrici quadrate di dimensione
nXn, e fa il prodotto scalare tra le due matrici. 
*/

#include <stdio.h>

int main(){
    int n, i, j, prodotto=0 ;
    int A[n][n];
    int B[n][n];


    printf("dim n:  \n");
    scanf("%d", &n);

    printf("parametri dentro A (%d x %d):  \n", n, n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("prametri dentro B:  \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("B[%d][%d]", i, j);
            scanf("%d", &B[i][i]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        prodotto += A[i][j]*B[i][j];
        }
    }

    printf("Il prodotto scalare è: %d  \n", prodotto);

}

