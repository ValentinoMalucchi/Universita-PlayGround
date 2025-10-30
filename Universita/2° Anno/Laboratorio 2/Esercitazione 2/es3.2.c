/*
Scrivere un programma che gestisce pazienti in un ospedale. I pazienti sono identificati da un id numerico intero.
Possono essere o pazienti con diabete (1), o pazienti con malattie cardiovascolari (0).
Per ogni tipo di paziente sono disponibili tipi diversi di variabili cliniche. Per i pazienti con diabete abbiamo la glicemia
(float) e il peso (float), per i pazienti cardio abbiamo pressione (int) e frequenza cardiaca (int).
Il numero di pazienti deve essere chiesto in input all’utente. Per ogni paziente abbiamo l'ID e il tipo di malattia sulla
prima riga, e le due variabili di interesse sulla seconda riga, separate da uno spazio.
Il programma deve stampare tutti i pazienti che hanno la stessa malattia dell'ultimo paziente inserito, nel formato
specificato nell'output del seguente esempio.
Esempio Input:
3 ( numero pazienti )
1 1
134.5 90.1
2 0
110 70
3 1
230.6 110.7
Esempio Output:
ID:1, Glicemia:134.500000, Peso:90.099998ID:3, Glicemia:230.600006, Peso:110.699997
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float glicemia;
    float peso;
}diabete_t;

typedef struct{
    int pressione;
    int fcardio;
}cardio_t;

typedef union{
    cardio_t cardio;
    diabete_t diabete;
}tipo_t;

typedef struct {
    int id;
    int diagnosi;
    tipo_t tipo;
}pazienti_t;



int main(){

    int i, n;
    printf("inserisci numero pazienti:  \n");
    scanf("%d",&n);

    pazienti_t *lista = (pazienti_t*) malloc(sizeof(pazienti_t)*n);

    for(i = 0; i < n; i++){
        printf("inserire ID e il tipo di malattia:  \n");
        scanf("%d %d",&lista[i].id,&lista[i].diagnosi);

        while(lista[i].diagnosi != 1 && lista[i].diagnosi != 0){
            printf("numero tipo malattia errato, diabete(1) o malattie cardiovascolari(0):  \n");
            scanf("%d",&lista[i].diagnosi);
        }

        if(lista[i].diagnosi == 0){
            printf("inserisci cardio e pressione:   \n");
            scanf("%d  %d",&lista[i].tipo.cardio.pressione,&lista[i].tipo.cardio.fcardio);
        }
        if(lista[i].diagnosi == 1){
            printf("inserisci glicemia e peso:  \n");
            scanf("%f  %f",&lista[i].tipo.diabete.glicemia,&lista[i].tipo.diabete.peso);
        }
    }

    for(i = 0; i < n; i++){
        if(lista[i].diagnosi == lista[n-1].diagnosi){
            if(lista[i].diagnosi == 0){
                printf("ID:%d, FC:%d, Pressione:%d",lista[i].id,lista[i].tipo.cardio.fcardio,lista[i].tipo.cardio.pressione);
            }else{
                printf("ID:%d, Glicemia:%f, Peso:%f",lista[i].id,lista[i].tipo.diabete.glicemia,lista[i].tipo.diabete.peso);
            }
        }
    }
}

