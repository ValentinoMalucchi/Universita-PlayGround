/*
• Scrivere un programma che calcoli il prodotto scalare di un array di 
interi A,la cui dimensione deve essere chiesta in input all’utente e . 
Il programma deve invertire l'array senza utilizzare un array di appoggio, 
ossia scambiare il contenuto della prima e dell'ultima cella, 
della seconda e della penultima, ecc… ed infine stampare a 
video ogni singolo elemento dell’array modificato.
*/

#include <stdio.h>

int main(){
    int n,i,temp,prodotto=0;

    printf("inserisci dim array:  \n");
    scanf("%d",&n);
    int A[n];
    printf("inserisci numeri array:  \n");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        prodotto += A[i] * A[i]; 
    }
    printf("in prodotto è %d \n",&prodotto);


    for(i=0;i<n/2;i++){
    temp = A[i];          // salvo il primo
    A[i] = A[n - 1 - i];    // metto l’ultimo al primo posto
    A[n - 1 - i] = temp;      // metto il vecchio primo all’ultimo posto
    }

    printf("array: \n");
    for(i=0;i<n;i++){
        printf("%d ", &A[i]);
    }

}