#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int numi;
	float numf;
	double numd;
	char letra;
	char string[20];
}tab3;

int i, j, linha, coluna, ok;
char **tipo;
tab3 **mat3;
char id[25];
char idTab[50];
int l;
int k;
tab3 valor;

void ProcuraString ();