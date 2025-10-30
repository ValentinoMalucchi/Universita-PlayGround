/*
Scrivere un programma in ANSI C che gestisca una lista concatenata di studenti.
Ogni studente è rappresentato da una struttura contenente:
● matricola (intero positivo)
● età (intero positivo)
Il programma deve:
● Aggiungere studenti alla lista dinamicamente, trattata come una coda FIFO
● Stampare la lista.
● Ordinare la lista per età (ordine crescente).
● Estrarre tutti gli studenti di una certa età (letta da tastiera).
● Liberare la memoria al termine.
*/
typedef struct Studente{
    int matricola;
    int eta;
    struct Studente next;
}Studente;
void stampa(Studente* s){
    if(s == NULL ){
        return;
    }
    while(s != NULL){
        printf("%d  %d",s -> matricola, s -> eta);
        s = s -> next;
    }
}
void libera(Studente* s){
    Studente* temp;
    while(s != NULL){
        temp = s;
        s = s -> next;
        free(temp);
    }
}
Studente* aggiungiStudente(Studente* s,int matricola, int eta){

    Studente* nuovo = (Studente)malloc(sizeof(Studente));
    if(nuovo == NULL){
        return s;
    }
    nuovo -> matricola = matricola;
    nuovo -> eta = eta;
    nuovo -> next = NULL;

    if(s == NULL){
        return nuovo;
    }
    while(s -> next != NULL){
        s = s -> next;
    }
    s -> next = nuovo;
    return s;
}
void ordinaLista(Studente* s){
    Studente* temp = s;
    int scambia = 0;
    do{
        while(temp -> next != NULL){
            if(temp -> eta > temp -> next -> eta){
                int tempeta = temp -> next -> eta;
                int tempmatricola = temp -> next -> matricola;

                temp -> next -> eta = temp -> eta;
                temp -> next -> matricola = temp -> matricola;
                temp -> eta = temp -> next -> eta;
                temp -> matricola = temp -> next -> matricola;
                scambia = 1;
            }
            temp = temp -> next;
        }
    }while(scambia)
}
Studente* estraiPerEta(Studente* s,int x){
    Studente* lista = NULL;
    Studente* temp = s;

    while(temp != NULL){
        if(temp -> eta == x){
            lista = aggiungiStudente(lista ,temp -> matricola,temo -> eta);
        }
        temp = temp -> next;
    }
    return lista;
}























/*
typedef struct Studente{
    int matricola;
    int eta;
    struct Studente* next;
}Studente;

void stampalista(Studente* s){
    if(s == NULL){
        return;
    }
    while(s != NULL){
        printf("Matricola: %d  Età: %d\n", s -> matricola, s -> eta);
        s = s -> next;
    } 
}
void liberaMemoria(Studente* s){
    Studente* temp;
    while(temp != NULL){
        temp = s;
        s = temp -> next;
        free(temp);
    }
}
void ordinaLista(Studente* s){
    Studente* temp;
    int scambio;
    do{
        scambio = 0;
        while(temp -> next != NULL){
            if(temp -> eta > temp -> next -> eta){
                scambio = 1;
                int tempeta = temp -> eta;
                int tempmatricola = temp -> matricola;

                temp -> eta = temp -> next -> eta;
                temp -> matricola = temp -> next -> matricola;
                temp -> next -> eta = tempeta;
                temp -> next -> matricola = matricola;
            }
            temp = temp -> next;
        }
    }while(scambio);
}
Studente* estraiPerEta(Studente* s,int x){
    Srudente* temp = s;
    Studente* lista = NULL;

    while(temp != NULL){
        if(temp -> eta = x){
            lista = aggiungiStudente(lista,temp -> matricola, temp -> eta);
        }
        temp = temp -> next;
    }
    return lista;
}
Studente* aggiungiStudente(Studente* s,int matricla,int eta){
    Studente* nuovo = (Studente)malloc(sizeof(Studente));
    if(nuovo == NULL){
        return s; // errore di allocazione
    }
    nuovo -> matricola = matricola;
    nuovo -> eta = eta;
    nuovo -> next = NULL;

    if(s == NULL){
        return nuovo;
    }
    while(s -> next != NULL){
        s = s -> next; 
    }
    s -> next = nuovo;
    return s;

}
*/

/*
typedef struct Studente{
    int matricola;
    int eta;
    struct Studente* next;
}Studente;

Studente* estraiPerEta(Studente *s, int x){
    Studente* ptr = s;
    Student* prec = NULL;

    while(ptr != NULL){
        if(pts -> eta == x){
            prec = aggiungiStudente(prec, ptr -> matricola, ptr -> eta); 
        }
        ptr = ptr -> next
    }  return prec
}
void ordinaLista(Studente* s){
    if(s == NULL){
        return 0;
    }
    int scambiato;
    Studente *ptr;

    do{
    scambio = 0;
    while(ptr -> next != NULL){
        if(ptr -> eta > ptr -> next -> eta){
            scambio = 1;
            int tempeta = ptr -> eta;
            int tempmat = ptr -> matricola;

            ptr -> eta = ptr -> next -> eta;
            ptr -> matricola = ptr -> next -> matricola;

            ptr -> next -> eta = tempeta;
            ptr -> next -> matricola = tempmatricola;
        }
        ptr = ptr -> next;
    }
    }while(scambio);
}
void liberaMemoria(Studente* s){
    Studente* ora;
    while(s != NULL){
        ora = s;
        s = ora -> next;
        free(ora);
    }
}
void stampa(Studente* s){
    if(s == NULL){
        return;
    }
    Studente* ora = s;
    while(ora != NULL){
        printf("matricola:      ,eta:       \n",ora -> matricola, ora -> eta);
        s = ora -> next;
    }
}
Studente* aggiungiStudente(Studente *s, int matricola, int eta) {

    Studente *nuovo = (Studente*)malloc(sizeof(Studente));
    if (nuovo == NULL) {
        printf("Errore: allocazione di memoria fallita.\n");
        return s;
    }

    nuovo-> matricola = matricola;
    nuovo->eta = eta;
    nuovo->next = NULL;
    
    if (s == NULL) {
        return nuovo; // primo elemento
    }
    while (s->next != NULL) {
        s = s->next;
    }
    s->next = nuovo;
    return s;
}
int main(){
    d
}
*/
