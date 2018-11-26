#include "ListaDados.h"

void listarDados(void){
	strcat(idTab, "tabelas/");
	setbuf(stdin, NULL);
	printf("Digite o nome(id) da tabela: ");
	scanf("%s", &id);
	strcat(idTab, id);
	strcat(idTab, ".txt");
	/*
	Em idTab é feita concatenação do endereço onde será salvo
	as tabelas com a string "(id da tabela).txt" para
	acessar a tabela.
	*/
	FILE *arquivo = fopen(idTab, "r");

	if(arquivo == NULL){
		printf("\t\tTabela nao existente\n");
		strcpy(idTab, "");
		strcpy(id, "");
		return NULL;
	}
	else{
		/*
		Como o arquivo é gravado de uma forma que facilite a
		leitura, (essa "forma" é explicada na função CriaTabela)
		então primeiramente lê-se o número de linhas, colunas e 
		o tipo de dado de cada coluna.
		*/
		fscanf(arquivo, "linhas: %d\n", &linha);
		fscanf(arquivo, "colunas: %d\n", &coluna);
	
		mat2 = (int**) malloc(linha * sizeof(tab2*));
		tipo = (char**) malloc((coluna-1) * sizeof(char*));

		for(j=0; j<(coluna-1); j++){
			tipo[j] = (char*) malloc(6 * sizeof(char));
			fscanf(arquivo, " %s\n", tipo[j]);
		}
		fseek(arquivo, 1, SEEK_CUR);
		/*
		O seguinte bloco "for" grava os valores da tabela
		na matriz alocada.
		*/
		for(i=0; i<linha; i++){
			mat2[i] = (int*) malloc(coluna * sizeof(tab2));
			fseek(arquivo, 1, SEEK_CUR);
			for(j=0; j<coluna; j++){
				if(i==0 && j>0){
					fscanf(arquivo, " %12s", mat2[i][j].string);
				}
				else if(j==0){
					fscanf(arquivo, " %12d", &mat2[i][j].numi);				
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						fscanf(arquivo, " %12d", &mat2[i][j].numi);
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						fscanf(arquivo, " %12f", &mat2[i][j].numf);
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						fscanf(arquivo, " %12c", &mat2[i][j].letra);
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						fscanf(arquivo, " %12s", mat2[i][j].string);					
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						fscanf(arquivo, " %12lf", &mat2[i][j].numd);
					}

				}

			}

		}
		fclose(arquivo);
		printf("\n");
		
		//Agora o código imprime a matriz na tela do usuário
		mat2[0][0].numi = 0;
		for(i=0; i<linha; i++){
			for(j=0; j<coluna; j++){
				if(i==0 && j>0){	
					printf(" %12s", mat2[i][j].string);
				}
				else if(j==0){
					printf(" %12d", mat2[i][j].numi);
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						printf(" %12d", mat2[i][j].numi);
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						printf(" %12f", mat2[i][j].numf);
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						printf(" %12c", mat2[i][j].letra);
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						printf(" %12s", mat2[i][j].string);
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						printf(" %12lf", mat2[i][j].numd);
					}
				}		
			}
			printf("\n");
		}

		for(i=0; i<linha; i++){
			free(mat2[i]);
		}
		free(mat2);
		for(j=0; j<(coluna-1); j++){
			free(tipo[j]);
		}
		free(tipo);

	}
	strcpy(idTab, "");
	strcpy(id, "");
}
