/*
Si scriva un programma di gestione dell'anagrafe dei dipendenti di un'azienda che legga i seguenti dati per 6 diversi
dipendenti:
• Un codice identificativo del dipendente ( intero ), diverso per ogni dipendente
• L'età del dipendente in anni (un intero)
• Stipendio (un float, indicato in euro come segue: 16540.32 );
• Il tipo di dipendente, indicando con il numero 0 i dirigenti, 1 i quadri, 2 gli operai e 3 gli impiegati, usando
una opportuna enum con etichette rispettivamente dirigente, quadro, operaio e
impiegato.
Il numero di dipendenti deve essere chiesto in input all’utente; per ogni dipendente, si chieda in input il codice
identificativo, controllando se è diverso da uno già immesso e richiedendolo se è diverso, l’età, lo stipendio e il tipo di
dipendente.

Nello stesso ordine in cui sono stati immessi i dati dei dipendenti si stampino, uno per linea, il codice identificativo, l'età
e il ruolo di ogni dipendente ( l’etichetta ) che guadagni meno dello stipendio medio aritmetico di tutti i dipendenti
dell'azienda. I valori stampati devono essere separati da un unico spazio.
Esempio di Input:
35,1,56,55650.33, 0, 2, 28, 36540.56, 1, 3, 22, 22120.54, 2, 4, 32, 28450.45, 3, 5, 45, 18960.65, 2, 6, 33,38960.54, 1
Esempio di Output:
3 22 operaio
4 32 impiegato
*/

#include <stdio.h>
#include <stdlib.h>


typedef enum{
    dirigente = 0,
    quadro = 1,
    operaio = 2,
    impiegato = 3
} tipo_t;

typedef struct{
    int ci;
    int eta;
    float stipendio;
    tipo_t tipo;
}dipendente_t;


int main(int argc, char *argv[]){
    int i, j, unico, ci_dip, eta_dip, tipo_dip;
    float stipendio_dip, media = 0;

    dipendente_t dipendenti[6];
    /*printf("numero dei dipendenti:  \n");
    scanf("%d",&n)*/
    

    for(i=0; i<6; i++){
       
        do {
            unico = 1;  //condizione del while
            printf("Inserisci codice dipendente:    \n");
            scanf("%d", &ci_dip);

            for (j = 0; j < i; j++) {
                if (ci_dip == dipendenti[j].ci) {
                    printf("Codice già inserito, riprova.\n");
                    unico = 0;
                    break;
                }
            }
        } while (!unico);
        dipendenti[i].ci = ci_dip;

        printf("inserisci eta:  \n");
        scanf("%d",&eta_dip);
        dipendenti[i].eta = eta_dip;

        printf("inserisci stipendio:    \n");
        scanf("%f",&stipendio_dip);
        dipendenti[i].stipendio = stipendio_dip;

        printf("inserisci tipo: \n");
        scanf("%d",&tipo_dip);
        dipendenti[i].tipo = tipo_dip;

        media += stipendio_dip;
    }

    media /= 6;

    for(i=0; i < 6; i++){
        if(dipendenti[i].stipendio < media){
            printf("%d, %d, ", dipendenti[i].ci, dipendenti[i].eta);
            switch(dipendenti[i].tipo){
                case dirigente:
                    printf(" dirigente\n");
                    break;
                case quadro:
                    printf(" quadro\n");
                    break;
                case operaio:
                    printf(" operaio\n");
                    break;
                default:
                printf(" impiegato\n");
            }   

        }
    }
    return 0;

}