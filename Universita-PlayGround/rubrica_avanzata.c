#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DB_FILENAME "rubrica.txt"
#define MAX_NAME 100
#define MAX_PHONE 40
#define MAX_EMAIL 100

/*
  Rubrica avanzata in C
  ---------------------
  ✅ Aggiunta contatti con nome, telefono, email
  ✅ Rimozione contatti
  ✅ Ricerca per nome (case-insensitive)
  ✅ Inserimento automatico in ordine alfabetico
  ✅ Salvataggio/caricamento da file
*/

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
} Contact;

typedef struct {
    Contact *data;
    size_t size;
    size_t capacity;
} ContactList;

/* === Gestione base lista === */
void init_list(ContactList *list) {
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

void free_list(ContactList *list) {
    free(list->data);
    list->data = NULL;
    list->size = list->capacity = 0;
}

int ensure_capacity(ContactList *list, size_t needed) {
    if (list->capacity >= needed) return 1;
    size_t newcap = list->capacity ? list->capacity * 2 : 4;
    while (newcap < needed) newcap *= 2;
    Contact *tmp = realloc(list->data, newcap * sizeof(Contact));
    if (!tmp) return 0;
    list->data = tmp;
    list->capacity = newcap;
    return 1;
}

/* === Utilità === */
void trim(char *s) {
    size_t n = strlen(s);
    while (n > 0 && (isspace((unsigned char)s[n-1]) || s[n-1] == '\n' || s[n-1] == '\r'))
        s[--n] = '\0';
    size_t start = 0;
    while (isspace((unsigned char)s[start])) start++;
    if (start > 0) memmove(s, s+start, strlen(s+start)+1);
}

void read_line(char *buffer, size_t sz) {
    if (!fgets(buffer, (int)sz, stdin)) {
        buffer[0] = '\0';
        return;
    }
    trim(buffer);
}

/* Confronto case-insensitive (per ordinamento e ricerca) */
int strcasecmp_custom(const char *a, const char *b) {
    for (; *a && *b; a++, b++) {
        int diff = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (diff != 0) return diff;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

/* === Inserimento ordinato alfabeticamente === */
int add_contact_sorted(ContactList *list, const char *name, const char *phone, const char *email) {
    if (!ensure_capacity(list, list->size + 1)) return 0;

    // Trova posizione corretta (ordine alfabetico per nome)
    size_t pos = 0;
    while (pos < list->size && strcasecmp_custom(list->data[pos].name, name) < 0)
        pos++;

    // Sposta gli elementi successivi in avanti
    for (size_t i = list->size; i > pos; i--) {
        list->data[i] = list->data[i-1];
    }

    // Inserisce il nuovo contatto
    strncpy(list->data[pos].name, name, MAX_NAME - 1);
    strncpy(list->data[pos].phone, phone, MAX_PHONE - 1);
    strncpy(list->data[pos].email, email, MAX_EMAIL - 1);
    list->data[pos].name[MAX_NAME - 1] = '\0';
    list->data[pos].phone[MAX_PHONE - 1] = '\0';
    list->data[pos].email[MAX_EMAIL - 1] = '\0';

    list->size++;
    return 1;
}

/* === Stampa e rimozione === */
void print_contacts(const ContactList *list) {
    if (list->size == 0) {
        printf("Rubrica vuota.\n");
        return;
    }
    printf("\n=== Rubrica (%zu contatti) ===\n", list->size);
    for (size_t i = 0; i < list->size; i++) {
        printf("%zu) %s — %s — %s\n", i+1,
               list->data[i].name,
               list->data[i].phone,
               list->data[i].email);
    }
}

int remove_contact(ContactList *list, size_t idx) {
    if (idx >= list->size) return 0;
    for (size_t i = idx; i + 1 < list->size; i++)
        list->data[i] = list->data[i + 1];
    list->size--;
    return 1;
}

/* === Ricerca per nome === */
void search_contact(const ContactList *list, const char *query) {
    int found = 0;
    for (size_t i = 0; i < list->size; i++) {
        if (strcasestr(list->data[i].name, query)) {
            if (!found)
                printf("\nRisultati per \"%s\":\n", query);
            printf("%zu) %s — %s — %s\n", i+1,
                   list->data[i].name,
                   list->data[i].phone,
                   list->data[i].email);
            found = 1;
        }
    }
    if (!found)
        printf("Nessun contatto trovato con \"%s\".\n", query);
}

/* === Salvataggio / caricamento file ===
   Formato CSV: nome,telefono,email
*/
int save_to_file(const ContactList *list) {
    FILE *f = fopen(DB_FILENAME, "w");
    if (!f) return 0;
    for (size_t i = 0; i < list->size; i++) {
        fprintf(f, "%s,%s,%s\n",
                list->data[i].name,
                list->data[i].phone,
                list->data[i].email);
    }
    fclose(f);
    return 1;
}

int load_from_file(ContactList *list) {
    FILE *f = fopen(DB_FILENAME, "r");
    if (!f) return 1; // non esiste: non è un errore
    char line[300];
    while (fgets(line, sizeof(line), f)) {
        trim(line);
        if (strlen(line) == 0) continue;

        char *n = strtok(line, ",");
        char *p = strtok(NULL, ",");
        char *e = strtok(NULL, ",");
        if (!n || !p || !e) continue;

        trim(n); trim(p); trim(e);
        add_contact_sorted(list, n, p, e);
    }
    fclose(f);
    return 1;
}

/* === Menu === */
void menu(ContactList *list) {
    char choice[10];
    char buffer[200];

    while (1) {
        printf("\n--- MENU RUBRICA ---\n");
        printf("1) Elenca contatti\n");
        printf("2) Aggiungi contatto\n");
        printf("3) Rimuovi contatto\n");
        printf("4) Cerca per nome\n");
        printf("5) Salva su file\n");
        printf("0) Esci\n");
        printf("Scelta: ");
        read_line(choice, sizeof(choice));

        if (strcmp(choice, "1") == 0) {
            print_contacts(list);

        } else if (strcmp(choice, "2") == 0) {
            char name[MAX_NAME], phone[MAX_PHONE], email[MAX_EMAIL];
            printf("Nome: ");
            read_line(name, sizeof(name));
            printf("Telefono: ");
            read_line(phone, sizeof(phone));
            printf("Email: ");
            read_line(email, sizeof(email));

            if (add_contact_sorted(list, name, phone, email))
                printf("Contatto aggiunto con successo (rubrica ordinata).\n");
            else
                printf("Errore: memoria insufficiente.\n");

        } else if (strcmp(choice, "3") == 0) {
            print_contacts(list);
            printf("Numero del contatto da rimuovere: ");
            read_line(buffer, sizeof(buffer));
            long idx = strtol(buffer, NULL, 10);
            if (idx > 0 && (size_t)idx <= list->size) {
                remove_contact(list, (size_t)idx - 1);
                printf("Contatto rimosso.\n");
            } else {
                printf("Indice non valido.\n");
            }

        } else if (strcmp(choice, "4") == 0) {
            printf("Inserisci nome (anche parziale): ");
            read_line(buffer, sizeof(buffer));
            search_contact(list, buffer);

        } else if (strcmp(choice, "5") == 0) {
            if (save_to_file(list))
                printf("Salvato con successo in '%s'.\n", DB_FILENAME);
            else
                printf("Errore nel salvataggio.\n");

        } else if (strcmp(choice, "0") == 0) {
            printf("Vuoi salvare prima di uscire? (s/n): ");
            read_line(choice, sizeof(choice));
            if (choice[0] == 's' || choice[0] == 'S')
                save_to_file(list);
            printf("Uscita dal programma. Arrivederci!\n");
            break;

        } else {
            printf("Scelta non valida.\n");
        }
    }
}

/* === MAIN === */
int main(void) {
    ContactList rubrica;
    init_list(&rubrica);
    load_from_file(&rubrica);

    printf("Rubrica caricata (%zu contatti).\n", rubrica.size);
    menu(&rubrica);

    free_list(&rubrica);
    return 0;
}
