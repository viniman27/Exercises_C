#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
  char *dado;
  struct celula *prox;
} celula;


celula *cria_lista () {
  celula *le = malloc (sizeof(celula));
  le -> prox = NULL;
  return le;
}

void desfazer (celula *le) {
  celula *lixo = le -> prox;
  if (lixo != NULL) {
    le -> prox = lixo -> prox;
    printf (" %s\n", lixo -> dado);
    free (lixo);
  }
  else printf ("NULL\n");
}

void inserir (celula *le, char *dado) {
  celula *novo = malloc (sizeof(celula));
  novo -> dado = dado;
  novo -> prox = le -> prox;
  le -> prox = novo;
}

int main () {
  celula *le = cria_lista ();
  char str[100];
  char *auxiliar = malloc(100 * sizeof(char));

  while(scanf(" %s", str) != EOF) {

    if (strcmp (str, "inserir") == 0) {

      scanf(" %[^\n]", auxiliar);
      auxiliar [strlen (auxiliar)] = '\0';
      inserir(le, auxiliar);

    }
    else if(strcmp(str,"desfazer")==0) desfazer(le);

    auxiliar = malloc (100 * sizeof(char));

  }
  return 0;
}