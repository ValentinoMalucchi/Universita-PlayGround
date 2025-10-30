/*
Esercizi
Utilizzando l'implementazione vista a lezione delle liste concatenate, si deve implementare una struttura dati
rappresentante una pila (struttura dati LIFO ) e una serie di funzioni che permettono le seguente operazioni:
-push - inserisce un elemento nella pila
-pop - rimuove il primo elemento dalla pila e lo ritorna. Deve tornare il valore 0 se la pila è vuota.
-peek - restituisce il valore del primo elemento della pila senza rimuoverlo. 
Deve tornare il valore 0 se la pila è vuota.
-length - calcola la lunghezza della pila in modo ricorsivo
-print - stampa gli elementi della pila , iniziando con l'elemento in testa (vedi esempio), 
in modo ricorsivo

Scrivere una funzione Main che legge da standard input una serie di numeri interi e, utilizzando le funzioni 
definite sopra, esegue le seguenti operazioni:
• Se il numero è diverso da zero ed è un multiplo di 3, viene inserito nella pila il numero diviso 3
• Se il numero è diverso da 0 e non è un multiplo di 3, viene inserito in pila
• Se il numero è 0, viene eliminato un elemento dalla pila , solo se l'elemento da eliminare è dispari o 
la pila attualmente contiene più di 3 elementi.
• Il programma si ferma quando si leggono tre valori 0 di seguito
Alla fine della funzione Main, deve essere stampato in stdout il contenuto della pila e la sua lunghezza, 
con tutti gli elementi della pila su un'unica riga, separati da uno spazio, e la lunghezza della pila come 
ultimo valore.
Esempio di input:
2   56  -3  5   897 432 0   19  -54 0   45  0   0   0
Esempio di output:
5 -1 56 2 4
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valore;
    struct nodo* next;
}Nodo;
typedef Nodo* Pila;

int main(){
    Pila s = NULL;
    int x,zero = 0;
    printf("inserisci una serie di numeri interi:   \n");
    
    do{
        scanf("%d",&x);
        if(x % 3 == 0 && x != 0){
            zero = 0;
            push(x/3,&s);
        }
        if(x % 3 != 0 && x != 0){
            zero = 0;
            push(x,&s);
        }
        if(x == 0){
            if(peek(s) % 2 != 0 || length(s) > 3){
                zero++;
                pop(&s);
            }
        }
    }while(zero < 3);
    stampa(s);
    printf("%d  \n",length(s));
    return 0;
}


void push(int x, Pila* s){
    Nodo* nuovo=malloc(sizeof(Nodo));
    if(nuovo == NULL){
        exit(1);
    }
    nuovo -> valore = x;
    nuovo -> next = *s;
    *s = nuovo;
}

int pop(Pila* s){
    if(*s == NULL){
        return 0;
    } else {
        Nodo* attuale = *s;
        int ritorno = attuale -> valore;
        *s = attuale -> next;
        free(attuale);
        return ritorno;
    }
}
int peek(Pila s){
    if(s == NULL){
        return 0;
    }else{
        return s -> valore;
    }
}
int length(Pila s){
    if(s == NULL){
        return 0;
    }else{
        return 1 + length(s -> next);
    }
}
void stampa(Pila s){
    if(s == NULL){
        return;
    }else{
        printf("%d  ",s -> valore);
        stampa(s -> next);
    }
}


