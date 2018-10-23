#include "CriaTabela.h"

void criar(void){
	setbuf(stdin, NULL);
	printf("Digite o numero de linhas e colunas da tabela, respectivamente: ");
	scanf("%d %d", &linha, &coluna);
	
	mat = (int**) malloc(linha * sizeof(tab*));

	for(i=0; i<linha; i++){
		mat[i] = (int*) malloc(coluna * sizeof(tab));
		
		for(j=0; j<coluna; j++){
			setbuf(stdin, NULL);
			printf("Linha %d e coluna %d\n", i+1, j+1);
			setbuf(stdin, NULL);
			printf("Digite o tipo de dado: ");
			scanf("%s", tipo);
			
			//Tratamento para cada tipo de dado
			if(strcmp(tipo, "int") == 0){
				setbuf(stdin, NULL);
				printf("Digite: ");
				scanf("%d", &mat[i][j].numi);
			}
			else if(strcmp(tipo, "float") == 0){
				setbuf(stdin, NULL);
				printf("Digite: ");
				scanf("%f", &mat[i][j].numf);
			}
			else if(strcmp(tipo, "char") == 0){
				setbuf(stdin, NULL);
				printf("Digite: ");
				scanf("%c", &mat[i][j].letra);
			}
			else if(strcmp(tipo, "string") == 0){
				setbuf(stdin, NULL);
				printf("Digite: ");
				scanf("%s", &mat[i][j].string);
			}
		}

		
	}




}