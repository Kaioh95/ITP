#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int numi;
	float numf;
	double numd;
	char letra;
	char string[20];
}tab4;

void apagarValor(void);

int i, j, linha, coluna, ok, opcao, colunaSel;
char **tipo;
tab4 **mat4;
char id[25];
char idTab[50];