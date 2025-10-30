/*
Scrivere un programma che fa la somma dei parametri ricevuti dalla linea
di comando
*/

#include <stdio.h>

int main(){
    int i, n, val, somma=0;

    printf("inserisci quanti numeri vuoi sommare:  \n");
    fflush(stdout);   // <-- forza la stampa immediata
    scanf("%d", &n);

    printf("inserisci i numeri: \n");
    for(i=0;i<n;i++){
        scanf("%d", &val);
        somma += val;
    }

    printf("somma = %d\n", somma);
    return 0;
}
