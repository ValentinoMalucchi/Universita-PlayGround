/*
Scrivere un programma che legge da standard input due stringhe di non più di mille caratteri ognuna 
( usare #define NUM, dove NUM è una costante da voi definita che contenga la stringa della dimensione 
 suddetta ) e definisca una funzione con il seguente prototipo:
char* my_strcat1(char *s1, char *s2);
che restituisca un puntatore ad una nuova stringa ottenuta concatenando le stringhe puntate da s1 e s2. 
Non si deve utilizzare le corrispondenti funzioni di libreria strcat o strncat.
Il programma prende in input:
- la lunghezza della prima stringa (e alloca esattamente quanto necessario, ricordarsi il terminatore \0) 
sulla prima riga dello stdin
- la prima stringa, sulla seconda riga dello stdin
- la lunghezza della seconda stringa (e alloca esattamente quanto necessario, ricordarsi il terminatore \0) 
sulla terza riga dello stdin
- la seconda stringa, sulla quarta riga dello stdin
Si stampi la stringa ottenuta concatenandole.
Esempio di input:
10
ciaoatutti
3
voi
Esempio di output:
ciaoatuttivoi
*/

#include <stdio.h>
#include <stdlib.h>
#define NUM  1000

char* my_strcat1(char *s1, char *s2){
    int len1 = 0, len2 = 0;

    while((s1[len1]) != '\0'){
        len1++;
    }
    while((s2[len2]) != '\0'){
        len2++;
    }

    char *s3 = (char*)malloc((len1 + len2 + 1)* sizeof(char));
    if(s3 == NULL){
        exit(1); // errore allocazione
    }

    for(int i = 0; i < len1; i++){
        s3[i] = s1[i];
    }
    for(int i = 0; i < len2; i++){
        s3[len1 + i] = s2[i];
    }

    s3[len1+len2] = '\0';
    return s3;
}


int main(){
    int len1,len2;

    printf("inserisci dim prima stringa:    \n");
    scanf("%d", &len1);
    char *s1 = (char*)malloc((len1 + 1) * sizeof(char));
    if(s1 == NULL){
        exit(1);
    }
    printf("inserisci prima stringa:  \n");
    scanf("%1000s",s1);

    printf("inserisci dim seconda stringa:    \n");
    scanf("%d",&len2);
    char *s2 = (char*)malloc((len2 + 1)* sizeof(char));
    if(s2 == NULL){
        exit(1);
    }
    printf("inserisci seconda stringa:  \n");
    scanf("%1000s", s2);

    char *risultato = my_strcat1(s1,s2);
    printf("la stringa risultate è\n:     %s", risultato);
    free(s1);
    free(s2);
    free(risultato);
    return 0;
}









