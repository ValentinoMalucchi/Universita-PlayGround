/*
Scrivere un programma che lavori su una lista concatenata, costituita da elementi interi, il cui inserimento termina appena viene
digitato un numero negativo.
Le operazioni da implementare devono essere contenute in apposite funzioni e essere le seguenti, dato un puntatore alla testa
della lista denominato L:
-print(L): stampa tutti gli elementi della lista L, uno per riga
-insert(x, L): inserire l’elemento in coda alla lista L ( nota: NON RICORSIVA )
-insertRic(int x, L): come la precedente MA RICORSIVA
-delete(L): elimina dalla lista L l’ultimo elemento, NN RICORSIVA
Nella funzione main, testare le funzioni implementate, inserendo un elemento della lista per riga. Usare la funzione ricorsiva se
l'elemento e' pari, non ricorsiva se e' dispari. Stampare in output gli elementi della lista, uno per riga. Dopo aver inserito l’elemento
negativo, svuotare la lista e stamparla nuovamente.
Esempio di Input:
4
30
22
124
-2
Esempio di Output:
4
30
22
124
-2
*/


