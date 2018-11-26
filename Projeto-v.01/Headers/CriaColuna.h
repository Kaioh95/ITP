#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int numi;
	float numf;
	double numd;
	char letra;
	char string[20];
}tab5;

int i, j, linha, coluna, ok;
char **tipo;
tab5 **mat5;
tab5 *NovaColuna;
char id[25];
char idTab[50];

void CriaColuna();