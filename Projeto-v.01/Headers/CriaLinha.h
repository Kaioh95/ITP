#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int numi;
	float numf;
	double numd;
	char letra;
	char string[20];
}tab1;

void criarLinha(void);

int i, j, linha, coluna, ok;
char **tipo;
tab1 **mat1;
tab1 *novalinha;
char id[25];
char idTab[50];