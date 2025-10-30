/*
Scrivere un programma C che, data in ingresso una stringa non superiore a 1000 caratteri, stampa in output, 
uno per riga, tutti i suffissi della stringa, ordinati lessicograficamente.
Esempio di input:
Prendiamo la stringa "ciao", i suffissi sono:
"ciao"
"iao"
"ao"
"o"
Esempio di output:
I suffissi ordinati lessicograficamente sono:
"ao"
"ciao"
"iao"
"o«
Hint: potete usare la funzione di libreria qsort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int comparaStringhe(const char *a, const char *b){
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;
    return strcmp(s1,s2);
}

int main(){
    char s[MAX];

    printf("inserisci stringa:  \n");
    scanf("%999s",s);

    int len = strlen(s);
    char *suffissi[len];

    for(int i = 0; i < len; i++){
        suffissi[i] = &s[i];
    }
    qsort(suffissi, len, sizeof(char*),comparaStringhe);

    printf("ordinamento: \n");
    for(int i = 0; i < len; i++){
        printf("%s  \n",suffissi[i]);
    }
    return 0;
}
