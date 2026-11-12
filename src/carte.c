#include "carte.h"

carte* carte_create(int n, int m){
  int i;
  carte* c = malloc(sizeof(carte));
  c->n = n;
  c->m = m;
  c->elt = (char **) malloc(n * sizeof(char *));
  for (i = 0; i < n; i++){
    c->elt[i] = (char *) malloc(m * sizeof(char)); 
  }

  return c;
}

void carte_free(carte* c) {
    int i;
    for (i = 0; i < c->n; i++){
	free(c->elt[i]);
    }
    free(c->elt);
    free(c);
}

void carte_print(carte* c) {
    int i, j;


    for (i = 0; i < c->n; i++) {
        for (j = 0; j < c->m; j++) {
            printf("%c", c->elt[i][j]);
        }
        printf("\n"); 
    }
    printf("\n");
}


carte* carte_file(FILE *fp){
    if (fp == NULL) {
        return NULL;
    }
    int ligne, col, i, j;
    fscanf(fp, "%d", &ligne);
    fscanf(fp, "%d", &col);
    carte* c = carte_create(ligne, col);
    int ch = fgetc(fp);
    while (ch != '\n' && ch != EOF) {
        ch = fgetc(fp);
    }
    for (i = 1; i < c->n; i++) {
	for (j = 0; j < c->m; j++) {   
	  ch = fgetc(fp);
	  if (ch == '\n') {
	    ch = fgetc(fp); 
          }
          c->elt[i][j] = (char)ch;
	}
    }
    return c;
}
