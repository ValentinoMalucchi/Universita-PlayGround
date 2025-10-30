/*
• Si scriva un programma di gestione dell'anagrafe dei dipendenti di un'azienda che legga i seguenti dati per 6 diversi dipendenti:
• Un codice identificativo del dipendente ( intero ), diverso per ogni dipendente
• L'età del dipendente in anni (un intero)
• Stipendio (un float, indicato in euro come segue: 16540.32 );
• Il tipo di dipendente, indicando con il numero 0 i dirigenti, 1 i quadri, 2 gli operai e 3 gli impiegati, usando una opportuna
enum con etichette rispettivamente dirigente, quadro, operaio e impiegato.
Il numero di dipendenti deve essere chiesto in input all’utente; per ogni dipendente, si chieda in input il codice identificativo,
controllando se è diverso da uno già immesso e richiedendolo se è diverso, l’età, lo stipendio e il tipo di dipendente.
Nello stesso ordine in cui sono stati immessi i dati dei dipendenti si stampino, uno per linea, il codice identificativo, l'età e il ruolo di
ogni dipendente ( l’etichetta ) che guadagni meno dello stipendio medio aritmetico di tutti i dipendenti dell'azienda. I valori stampati
devono essere separati da un unico spazio.
Esempio di Input:
35,1,56,55650.33, 0, 2, 28, 36540.56, 1, 3, 22, 22120.54, 2, 4, 32, 28450.45, 3, 5, 45, 18960.65, 2, 6, 33,38960.54, 1
Esempio di Output:
3 22 operaio
4 32 impiegato
*/


