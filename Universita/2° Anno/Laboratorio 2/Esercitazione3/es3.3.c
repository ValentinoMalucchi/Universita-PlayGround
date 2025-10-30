/*
Dato un array di numeri interi, scrivere una funzione somma_con_trasformazione che calcoli la somma degli 
elementi di questo array. Questa funzione prende un puntatore a una funzione come parametro, 
ed ha il seguente prototipo, data la seguente definizione di tipo custom:
typedef int (*trasforma_fn)(int);
e il seguente prototipo per la funzione: int somma_con_trasformazione (int* a, int dim, trasforma_fn trasforma)

La funzione passata come parametro determina come ogni elemento dell'array dovrebbe essere trasformato 
prima di essere sommato. Le due possibili trasformazioni sono:
• valore_assoluto: calcola il valore assoluto dell'intero passato come parametro
• quadrato: calcola il quadrato dell'intero dell'intero passato come parametro
Il primo valore fornito da tastiera rappresenta la dimensione dell'array. Utilizzare l'allocazione dinamica 
della memoria. Nello stampare il risultato, utilizzare prima la funzione con il valore assoluto, 
seguita da uno spazio e poi dalla funzione che calcola il quadrato.
Esempio di input:
5
1
-1
1
-1
0
Esempio di output:
4 4
*/

#include <stdio.h>
#include <stdlib.h>

typedef int (*trasforma_fn)(int);

int valore_assoluto(int x){
    if(x < 0){
        return -x;
    } else {
        return x;
    }
}

int quadrato(int x){
    return x * x;
}

int somma_con_trasformazione(int* a, int dim, trasforma_fn trasforma){

    int i,somma=0;
    for(i=0;i<dim;i++){
        somma += trasforma(a[i]);
    }
    return somma;
}


int main(){
    int dim,i;

    printf("inserisci dimensione array:  \n");
    scanf("%d",&dim);

    int* a = malloc(dim * sizeof(int));

    printf("inserisci elementi array:   \n");
    for(i=0;i<dim;i++){
        scanf("%d",&a[i]);
    }

    printf("%d  ",somma_con_trasformazione(a, dim, valore_assoluto));
    printf("%d",somma_con_trasformazione(a,dim, quadrato));

    
    free(a);
    return 0;
}