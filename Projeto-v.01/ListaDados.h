#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int numi;
	float numf;
	double numd;
	char letra;
	char string[20];
}tab2;

void listarDados(void);

int i, j, linha, coluna, ok;
char **tipo;
tab2 **mat2;
char id[25];
char idTab[50];