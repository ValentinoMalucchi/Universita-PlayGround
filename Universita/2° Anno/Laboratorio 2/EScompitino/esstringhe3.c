/*
Date due stringhe s1 e s2, il Longest Common Prefix tra s1 e s2: LCP(s1, s2) è definito come la lunghezza del
più lungo prefisso che s1 e s2 hanno in comune.
Per esempio:
LCP(AABB,AAZZ) = 2
Perchè hanno entrambe AA iniziali
LCP(mississippi, missi) = 5
LCP(laboratorio,laboratoriale) = 10
Scrivere un programma C che legga da stdin un intero n, e poi legga una sequenza di n stringhe lunghe al 
massimo 500 caratteri. Il programma deve stampare, uno per linea, LCP(S[i-1], S[i]) per ogni 0 < i < n
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 500

int LCP(const char* s1, const char* s2){
    int i = 0;
    while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        i++;
    }
    return i;
}

int main(){
    char s1[MAX], s2[MAX];
    int soluzione = 0;

    printf("inserisci stringa s1:   \n");
    scanf("%s",s1);
    printf("inserisci stringa s2:   \n");
    scanf("%s",s2);

    soluzione = LCP(s1,s2);
    printf("%d\n",soluzione);
    return 0;
}
