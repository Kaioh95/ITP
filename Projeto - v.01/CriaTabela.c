#include "CriaTabela.h"

void criar(void){
	setbuf(stdin, NULL);
	printf("Digite o numero de linhas e colunas da tabela, respectivamente: ");
	scanf("%d %d", &linha, &coluna);
	setbuf(stdin, NULL);
	printf("Digite o nome(id) da tabela: ");
	scanf("%s", idTab);
	strcat(idTab, ".txt");
	
	mat = (int**) malloc(linha * sizeof(tab*));
	tipo = (char**) malloc(coluna * sizeof(char*));

	for(i=0; i<linha; i++){
		mat[i] = (int*) malloc(coluna * sizeof(tab));
		
		for(j=0; j<coluna; j++){
			
			if(i==0){
				tipo[j] = (char*) malloc(6 * sizeof(char));
				setbuf(stdin, NULL);
				printf("Linha %d e coluna %d\n", i+1, j+1);
				setbuf(stdin, NULL);
				printf("Digite o tipo de dado: ");
				scanf("%s", &tipo[j][0]);
				ok = 1;

				while(ok){
					if((strcmp(tipo[j], "int") == 0) || (strcmp(tipo[j], "float") == 0) || (strcmp(tipo[j], "char") == 0) || (strcmp(tipo[j], "string") == 0) || (strcmp(tipo[j], "double") == 0)){
						ok = 0;
					}
					else{
						setbuf(stdin, NULL);
						printf("Tipo invalido digite novamente: ");
						scanf("%s", &tipo[j][0]);
					}
				}

				setbuf(stdin, NULL);
				printf("Digite o atributo da coluna: ");
				scanf("%s", &mat[i][j].string);
			}
			else{

				//Tratamento para cada tipo de dado
				if(strcmp(tipo[j], "int") == 0){
					setbuf(stdin, NULL);
					printf("Digite um int: ");
					scanf("%d", &mat[i][j].numi);
				}
				else if(strcmp(tipo[j], "float") == 0){
					setbuf(stdin, NULL);
					printf("Digite um float: ");
					scanf("%f", &mat[i][j].numf);
				}
				else if(strcmp(tipo[j], "char") == 0){
					setbuf(stdin, NULL);
					printf("Digite um char: ");
					scanf("%c", &mat[i][j].letra);
				}
				else if(strcmp(tipo[j], "string") == 0){
					setbuf(stdin, NULL);
					printf("Digite uma string: ");
					scanf("%s", &mat[i][j].string);
				}
				else if(strcmp(tipo[j], "double") == 0){
					setbuf(stdin, NULL);
					printf("Digite um double: ");
					scanf("%li", &mat[i][j].numd);
				}

			}

		}

		
	}


	FILE *arquivo = fopen(idTab, "w");
	
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			if(i==0){
				fprintf(arquivo, " %s", mat[i][j].string);
			}
			else if(strcmp(tipo[j], "int") == 0){
				fprintf(arquivo, " %d", mat[i][j].numi);
			}
			else if(strcmp(tipo[j], "float") == 0){
				fprintf(arquivo, " %f", mat[i][j].numf);
			}
			else if(strcmp(tipo[j], "char") == 0){
				fprintf(arquivo, " %c", mat[i][j].letra);
			}

			else if(strcmp(tipo[j], "string") == 0){
				fprintf(arquivo, " %s", mat[i][j].string);
			}
			else if(strcmp(tipo[j], "double") == 0){
				fprintf(arquivo, " %li", mat[i][j].numd);
			}	
		}
		fprintf(arquivo, "\n");
	}
	fclose(arquivo);

}