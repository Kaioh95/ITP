#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int numi;
	float numf;
	double numd;
	char letra;
	char string[20];
}tab;

void criar(void);

int i, j, linha, coluna, ok;
char **tipo;
tab **mat;
char idTab[20];