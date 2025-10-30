/*
Scrivere un programma in linguaggio C per la gestione di una lista concatenata ordinata di numeri interi.
Ogni nodo della lista contiene:
un valore intero
un puntatore al nodo successivo

La lista è inoltre gestita tramite una struttura che mantiene:
il numero di elementi presenti
il puntatore alla testa della lista

Il programma deve implementare le seguenti funzionalità:
Inserimento ordinato
Data un numero intero, inserirlo nella lista in modo da mantenere l’ordine crescente dei valori.
Cancellazione di un valore
Eliminare tutte le occorrenze di un determinato valore dalla lista, se presenti.
Stampa della lista
Stampare gli elementi della lista in ordine inverso (fondo verso la testa) utilizzando una procedura ricorsiva.
Restituzione del numero di elementi
Fornire il numero degli elementi attualmente memorizzati nella lista.
Verifica di sottostringa
Scrivere una funzione che prenda in ingresso due stringhe e restituisca:
1 se la seconda stringa è una sottostringa della prima
0 altrimenti
(senza usare funzioni come strstr)

Il main() deve testare adeguatamente tutte le funzioni sviluppate.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valore;
    struct Nodo next;
}Nodo;

typedef struct Testa{
    int totel;
    struct *s;
}Testa;

void insert(int x, Testa* s){
    Nodo* nuovo = (Nodo)malloc(sizeof(Nodo));
    if(nuovo == NULL){
        return s;
    }
    nuovo -> valore = x;
    nuovo -> next = NULL;
    if(s == NULL){
        s = nuovo;
    }
    while(s -> next != NULL){
        s = s -> next;
    }
    s -> next = nuovo;
}
void delete (int x, list_head* l){
    Nodo* temp;
    if(l -> s == NULL){
        return;
    }
    if(l -> s -> valore == x){
        l -> totel--;
        temp = l -> s;
        l -> s = l -> s -> next;
        free(temp);
        delete(x,l);
    }
}

void print_app(elem* el) 
void print(list_head L) 
int numero_el (list_head L)
int sub_string(const char *str1, const char *str2) 






int main(void) {
  list_head L = {0,NULL};
  insert(10,&L);  
  insert(2,&L);  
  delete(10,&L);
  delete(5,&L);
  insert(4,&L);  
  insert(-34,&L);  
  delete(10,&L);
  insert(0,&L);  
  insert(5,&L);  
  insert(0,&L); 
  delete(0,&L);
  delete(5,&L);
  print(L);
  printf("%d\n",sub_string("ccciaciao","ciao"));
}





