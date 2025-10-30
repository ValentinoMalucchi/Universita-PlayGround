/*
Scrivere un programma che accetti in input due array di interi distinti e restituisca in output il numero di
elementi comuni a entrambi gli array. Si assuma che la lunghezza di ogni array sia fornita prima
dell'immissione degli elementi.
L'input è formato da:
- dimensione del primo array;
- lista dei valori (distinti) del primo array;
- dimensione del secondo array;
- lista dei valori (distinti) del secondo array.
L'unica riga dell'output contiene il numero di elementi in comune tra il primo e il secondo array.
Esempio di input:
3 (numero di elementi)
32
145
54
7 (numero di elementi)
145
4355
54
5675
14
65
23
Esempio di Output:
2
*/

#include <stdio.h>
#define MAX 100
int A[MAX], B[MAX];


int main(){

    int n, i, j, m, count = 0;

    printf("inserisci dimensione primo array A: \n");
    scanf("%d", &n);
    int A[n];

    printf("inserisci elementi array A: \n");
    for(i = 0; i<n; i++){
        scanf("%d",&A[i]);
    }

    printf("inserisci dimensione secondo array B:   \n");
    scanf("%d",&m);
    int B[m];

    printf("inserisci elementi array B: \n");
    for(i = 0; i<m; i++){
        scanf("%d",&B[i]);
    }


    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(A[i] == B[j]){
                count++;
                break;
            }
        }
    }
    printf("gli elementi in comune sono: %d \n", count);
    return 0;

}