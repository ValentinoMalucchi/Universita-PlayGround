/*
Scrivere un programma in ANSI C che memorizzi un insieme di studenti in un albero binario di ricerca (BST).
Ogni studente è rappresentato da una struttura con i seguenti campi:
● matricola (intero positivo)
● eta (intero positivo)
L’albero deve essere ordinato per età (i nodi più giovani a sinistra, i più anziani a destra).
● Il programma deve:
● Leggere da tastiera coppie di valori matricola e età e inserirli nell’albero.
L’inserimento termina quando l’utente digita 0 come matricola.
● Stampare l’albero in ordine crescente di età.
● Estrarre e stampare tutti gli studenti di una certa età (letta da tastiera).
● Liberare la memoria allocata dinamicamente.
Le funzioni di inserimento, stampa e estrazione devono essere RICORSIVE
*/

#include <stdio.h>
#include <stdlib.h> 

typedef struct Studente{
    int matricola;
    int eta;
    struct Studente* nodosx;
    struct Studente* nododx;
}Studente;
Studente* creaNodo(int matricola, int eta){
    Studente* nuovo = (Studente*)malloc(sizeof(Studente));
    if(nuovo == NULL){
        exit(1); // allocazione fallita
    }
    nuovo -> matricola = matricola;
    nuovo -> eta = eta;
    nuovo -> nodosx = NULL;
    nuovo -> nododx = NULL;

    return nuovo;
}
void stampa(Studente* s){
    if(s == NULL){
        return;
    }
    stampa( s -> nodosx);
    printf("Matricola: %d | Eta: %d\n", s -> matricola, s -> eta); //visita simmetri dell'albero
    stampa( s -> nododx);
}
void stampaEta(Studente* s,int x){
    if(s == NULL){
        return;
    }
    stampaEta(s -> nodosx,x);
    if(s -> eta == x){
        printf("Matricola: %d | Eta: %d\n", s -> matricola, s -> eta); 
    }
    stampaEta(s -> nododx,x);
}
void liberaMemoria(Studente* s){
    if(s == NULL){
        return;
    }
    liberaMemoria(s -> nodosx);
    liberaMemoria(s -> nododx);
    free(s);
}
Studente* inserisciStudente(Studente* s,int matricola,int eta){
    if(s == NULL){
        return creaNodo(matricola,eta);
    }
    if(eta < s -> eta){
        s -> nodosx = inserisciStudente(s -> nodosx,matricola,eta);
    } else {
        s -> nododx = inserisciStudente(s -> nododx,matricola,eta);
    }
    return s;
}
int main(){
    Studente *s = NULL;
    int matricola,eta;
    
    printf("inserisci matricola e eta ( matricola 0 per terminare). \n");
    
    do{
        printf("Matricola:  \n");
        if((scanf("%d",&matricola)) != 1){
            printf("input non valido\n");
            return 1;
        }
        if(matricola == 0){
            break;
        }

        printf("Eta:    \n");
        if((scanf("%d",&eta)) != 1){
            printf("input non valido\n");
            return 1;
        }
        s = inserisciStudente(s,matricola,eta);
    }while(matricola != 0);

    printf("albero in ordine di eta:    \n");
    stampa(s);

    int etaCercata;
    printf("inserisci un eta che desideri cercare:  \n");
    scanf("%d",&etaCercata);
    printf("studenti con eta cercata:   \n");
    stampaEta(s,etaCercata);

    liberaMemoria(s);//libera la memoria allocata
}
