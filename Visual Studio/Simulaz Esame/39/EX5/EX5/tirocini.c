/*
Creare i file tirocini.h e tirocini.c che consentano di utilizzare la seguente struttura:

struct tirocinio {
    char *nome;
    char *azienda1;
    char *azienda2;
    char *azienda3;
};

e la funzione:

extern bool tirocinio_load(FILE *f, struct tirocinio *t);

La struct consente di rappresentare le preferenze di tirocinio di uno studente, il cui
nome è contenuto nella stringa C puntata da nome, assieme ai nomi delle tre aziende
preferite. Nella struct sono contenuti puntatori a stringhe allocate dinamicamente (su
heap).

La funzione accetta come parametri un puntatore a file già aperto in lettura in modalità
tradotta (testo) e un puntatore ad una struct tirocinio già allocata. Non sono invece
allocati, né azzerati, i puntatori nome, azienda1, azienda2 e azienda3 del tirocinio.
La funzione deve leggere una sola riga da un file di testo con questa struttura:

Francesco,Edera,Tetrapak,System↵
Marco Bianchi,System,Doxee,Edera↵
Matteo Rossi,Comune di Modena,Tetrapak,System↵
Luca Neri,Foodpartner,EFFER,NonStop Recruitment↵
Giovanni Verdi,Erre Technology Group,AMARIS Group,UniCredit↵

e riempire opportunamente la struttura di cui ha ricevuto l’indirizzo. Il file consiste
di righe terminate da un a capo (anche l’ultima), in cui è presente il nome dello
studente, seguito dal nome di tre aziende. Questi nomi sono separati da virgole.
Supponiamo che il file sia corretto (non serve quindi fare accurati controlli di errore).
I nomi degli studenti o delle aziende possono contenere spazi.

La funzione deve ritornare true se riesce a leggere correttamente una riga del file,
false altrimenti. Questo dovrebbe accadere solo alla fine del file. La funzione non deve
né aprire, né chiudere il file.
*/
#include "tirocini.h"

bool tirocinio_load(FILE* f, struct tirocinio* t) {
    char* s=NULL;
    char x='0';
    unsigned int i = 0, j = 0, ret = 0;
    for (i = 0; i < 4; i++) {
        j = 0;
        do {
            ret = fscanf(f, "%c", &x);
            if (ret != 1 || x == EOF || ferror(f) != 0) {
                free(s);
                if (i > 0) {
                    free(t->nome);
                    free(t->azienda1);
                    free(t->azienda2);
                    free(t->azienda3);
                }
                return false;
            }
            if (x != ',' && x!='\n') {
                s = realloc(s, j+1);
                s[j] = x;
            }
            j++;
        }while (x != ',' && x!= '\n');
      //  j--;
        s = realloc(s, j + 1);
        s[j-1] = '\0';
        switch (i) {
        case 0:
            t->nome = calloc(j,1);
             strncpy(t->nome, s,j);
             memset(s, 0, j);
            break;
        case 1:
            t->azienda1 = calloc(j,1);
            strncpy(t->azienda1, s,j);
            memset(s, 0, j);
            break;
        case 2:
            t->azienda2 = calloc(j,1);
            strncpy(t->azienda2, s, j);
            memset(s, 0, j);
            break;
        case 3:
            t->azienda3 = calloc(j,1);
            strncpy(t->azienda3, s,j);
            memset(s, 0, j);
            break;
        default:
            break;
        }
    }
    free(s);
    return true;
}