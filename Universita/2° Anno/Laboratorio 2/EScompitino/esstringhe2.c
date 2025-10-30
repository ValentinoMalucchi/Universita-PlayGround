/*
Scrivere la funzione con il seguente prototipo, che restituisca 1 se le stringhe puntate da s1 e s2 sono una 
l'anagramma dell'altro e 0 altrimenti.
int anagramma(unsigned char *s1, unsigned char *s2);
Esempio: anagramma("pizza", "pazzi") == 1
Scrivere quindi un programma che legga da input due stringhe s1 e s2 e utilizzi questa funzione per stabilire 
se una è l'anagramma dell'altra.
Nota: utilizzare il tipo unsigned char * per le stringhe.
Hint: Data una stringa S, costruire un array aS[256] tale che aS[i] memorizzi il numero di occorrenze del 
carattere i-esimo in S. Chiedersi come sono gli array aSs e aSz di due stringhe S e Z che sono una 
l'anagramma dell'altra. L'output è 1 se s1 è l'anagramma di s2, 0 altrimenti.
Esempio di input:
aeiou
uoaei
Esempio di output:
1
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int anagramma(unsigned char *s1, unsigned char *s2){
    int counts1[256] = {0};
    int counts2[256] = {0};
    int i = 0;
    while(s1[i] != '\0'){
        counts1[s1[i]]++;
        i++;
    }
    i= 0;
    while(s2[i] != '\0'){
        counts2[s2[i]]++;
        i++;
    }
    for(int j = 0; j < 256; j++){
        if(counts1[j] != counts2[j]){
            return 0;
        }
    }
    return 1;
}

int main(){
    unsigned char s1[MAX];
    unsigned char s2[MAX];
    int risultato = 0;
    printf("inserisci prima stringa\n");
    scanf("%255s",s1);

    printf("inserisci seconda stringa\n");
    scanf("%255s",s2);

    risultato = anagramma(s1,s2);
    printf("%d\n",risultato);

    return 0;

}
