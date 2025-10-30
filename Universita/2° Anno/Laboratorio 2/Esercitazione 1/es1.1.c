/*
Esercizi
• Scrivere un programma che legge n e due vettori di dimensione n, e fa il
prodotto scalare tra i due vettori.
• Scrivere un programma che legge n e due matrici quadrate di dimensione
nXn, e fa il prodotto scalare tra le due matrici.
• Scrivere un programma che fa la somma dei parametri ricevuti dalla linea
di comando
*/
#include <stdio.h>

int main(){
    int n;
    int i;
    printf("inserisci dim vettori: \n");    
    scanf("%d", &n);

    int v1[n];
    int v2[n];
    printf("inserisci el primo: \n");
    for(i=0; i<n; i++) {
        scanf("%d", &v1[i]);
    }

    printf("inserisci el secondo: \n");
    for(i=0;i<n;i++){
        scanf("%d", &v2[i]);
    }

    int prodotto = 0;
    for(i=0; i< n ; i++){
        prodotto += v1[i] * v2[i];
    }

    printf("Il prodotto scalare è: %d\n", prodotto);

return 0;
}
