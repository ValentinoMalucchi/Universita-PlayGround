/*
Scrivere un programma che lavori su una lista concatenata, costituita da elementi interi, il cui inserimento 
termina appena viene digitato un numero negativo.
Le operazioni da implementare devono essere contenute in apposite funzioni e essere le seguenti, 
dato un puntatore alla testa della lista denominato L:
-print(L): stampa tutti gli elementi della lista L, uno per riga
-insert(x, L): inserire l’elemento in coda alla lista L ( nota: NON RICORSIVA )
-insertRic(int x, L): come la precedente MA RICORSIVA
-delete(L): elimina dalla lista L l’ultimo elemento, NN RICORSIVA

Nella funzione main, testare le funzioni implementate, inserendo un elemento della lista per riga. 
Usare la funzione ricorsiva se l'elemento e' pari, non ricorsiva se e' dispari. 
Stampare in output gli elementi della lista, uno per riga. Dopo aver inserito l’elemento negativo, 
svuotare la lista e stamparla nuovamente.
Esempio di Input:
4   30  22  124 -2
Esempio di Output:
4   30  22  124 -2
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    int valore;
    struct nodo * next;
}Nodo;

typedef Nodo* Lista;

void insert(int,Lista* );
void insertRic(int,Lista* );
void stampa(Lista );
void delete(Lista*);

int main(){

    Lista L = NULL;
    int x;
    printf("inserisci elementi in lista:    \n");

    do{
        scanf("%d",&x);
        if(x%2 == 0){
            insertRic(x,&L);
        } else {
            insert(x,&L);
        }
    }while(x >= 0);

    printf("----lista inserita---- \n");
    stampa(L);
    
    while(L != NULL){
        delete(&L);
    }
    printf("\n----lista dopo svuotamento----\n");
    stampa(L);
    return 0;
}

void insertRic(int x,Lista* L){
    if(*L == NULL){
        Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo)); // alloca il nodo in memoria
        if(nuovo == NULL){
            exit(1);
        }
        nuovo -> valore = x;
        nuovo -> next = NULL;
        *L = nuovo; //collega il nodo alla lista
    } else {
        insertRic(x,(&(*L) -> next));
    }
}

void stampa(Lista L){
    if(L == NULL){
        return;
    } else {
        printf("%d  ", L -> valore);
    }
    stampa(L -> next); //chiamata ricorsiva su se stessa

}

void delete(Lista* L){
    if(*L == NULL){
        return;
    } 
    Nodo *attuale = *L;
    Nodo *precedente = NULL;

    while(attuale -> next != NULL){
        precedente = attuale;
        attuale = attuale -> next;
    }

    if(attuale == *L) {
        *L = NULL;
    }else{
        precedente -> next = NULL;
    }

    free(attuale);
}

void insert(int x,Lista* L){

    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));

    if(nuovo == NULL){
        exit(1);
    }
    nuovo -> valore = x;
    nuovo -> next = NULL;

    if(*L == NULL){
        *L = nuovo;
        return;
    }

    Nodo* attuale = *L;
    while(attuale -> next != NULL){
        attuale = attuale -> next;
    }
    attuale -> next = nuovo;

}