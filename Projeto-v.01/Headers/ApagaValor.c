#include "ApagaValor.h"


void apagarValor(void){
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
	
		mat4 = (int**) malloc(linha * sizeof(tab4*));
		tipo = (char**) malloc((coluna-1) * sizeof(char*));

		for(j=0; j<(coluna-1); j++){
			tipo[j] = (char*) malloc(6 * sizeof(char));
			fscanf(arquivo, " %s\n", tipo[j]);
		}
		
		/*
		O seguinte bloco "for" grava os valores da tabela
		na matriz alocada.
		*/
		for(i=0; i<linha; i++){
			mat4[i] = (int*) malloc(coluna * sizeof(tab4));
			fseek(arquivo, 1, SEEK_CUR);
			for(j=0; j<coluna; j++){
				if(i==0 && j>0){
					fscanf(arquivo, " %12s", mat4[i][j].string);
				}
				else if(j==0){
					fscanf(arquivo, " %12d", &mat4[i][j].numi);				
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						fscanf(arquivo, " %12d", &mat4[i][j].numi);
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						fscanf(arquivo, " %12f", &mat4[i][j].numf);
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						fscanf(arquivo, " %12c", &mat4[i][j].letra);
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						fscanf(arquivo, " %12s", mat4[i][j].string);					
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						fscanf(arquivo, " %12lf", &mat4[i][j].numd);
					}

				}

			}

		}
	
		fclose(arquivo);
		printf("\n");

		opcao = -1;
		while(opcao){
			setbuf(stdin, NULL);
			printf("\t\tDigite: (1) para apagar uma linha\n");
			printf("\t\tDigite: (2) para apagar um valor na linha escolhida\n");
			printf("\t\tDigite: (0) para retornar ao menu principal\n");
			scanf("%d", &opcao);

			if(opcao == 1){
				ok = 0;
				while(ok <= 0 || ok >= linha){
					setbuf(stdin, NULL);
					printf("Digite a chave primaria da linha a ser apagada: ");
					scanf("%d", &ok);
					if(ok <= 0 || ok >= linha)
						printf("A chave digitada nao pode ser apagada\n");
				}

				FILE* arq = fopen(idTab, "w");
				if(arq == NULL){
					printf("Erro na modificacao do arquivo\n");
					strcpy(idTab, "");
					strcpy(id, "");
					return NULL;
				}
				else{
					fprintf(arq, "linhas: %d\ncolunas: %d\n", (linha-1), coluna);
					for(j=0; j<(coluna-1); j++){
						fprintf(arq, " %s\n", tipo[j]);
					}
					fprintf(arq, "\n");

					mat4[0][0].numi = 0;
					for(i=0; i<linha; i++){
						for(j=0; j<coluna; j++){
							if(i != ok && i < ok){
								if(i==0 && j>0){	
									fprintf(arq, " %12s", mat4[i][j].string);
								}
								else if(j==0){
									fprintf(arq, " %12d", mat4[i][j].numi);
								}
								else{
									if(strcmp(tipo[j-1], "int") == 0){
										fprintf(arq, " %12d", mat4[i][j].numi);
									}
									else if(strcmp(tipo[j-1], "float") == 0){
										fprintf(arq, " %12f", mat4[i][j].numf);
									}
									else if(strcmp(tipo[j-1], "char") == 0){
										fprintf(arq, " %12c", mat4[i][j].letra);
									}
									else if(strcmp(tipo[j-1], "string") == 0){
										fprintf(arq, " %12s", mat4[i][j].string);
									}
									else if(strcmp(tipo[j-1], "double") == 0){
										fprintf(arq, " %12lf", mat4[i][j].numd);
									}
								}
							}
							else if(i > ok){
								if(i==0 && j>0){	
									fprintf(arq, " %12s", mat4[i][j].string);
								}
								else if(j==0){
									fprintf(arq, " %12d", (mat4[i][j].numi-1));
								}
								else{
									if(strcmp(tipo[j-1], "int") == 0){
										fprintf(arq, " %12d", mat4[i][j].numi);
									}
									else if(strcmp(tipo[j-1], "float") == 0){
										fprintf(arq, " %12f", mat4[i][j].numf);
									}
									else if(strcmp(tipo[j-1], "char") == 0){
										fprintf(arq, " %12c", mat4[i][j].letra);
									}
									else if(strcmp(tipo[j-1], "string") == 0){
										fprintf(arq, " %12s", mat4[i][j].string);
									}
									else if(strcmp(tipo[j-1], "double") == 0){
										fprintf(arq, " %12lf", mat4[i][j].numd);
									}
								}
							}		
						}
						if(i != ok){
							fprintf(arq, "\n");
						}

					}

				}
				fclose(arq);
			}
			else if(opcao == 2){
				ok = 0;
				while(ok <= 0 || ok >= linha){
					setbuf(stdin, NULL);
					printf("Digite a chave primaria da linha a ser selecionada: ");
					scanf("%d", &ok);
					if(ok <= 0 || ok >= linha)
						printf("A chave digitada nao pode ser modificada\n");
				}
				for(j=0; j<coluna; j++){
					printf(" %12d", j);
				}
				printf("\n");
				for(j=0; j<coluna; j++){
					if(j==0){
						printf(" %12d", mat4[ok][j].numi);
					}
					else if(strcmp(tipo[j-1], "int") == 0){
						printf(" %12d", mat4[ok][j].numi);
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						printf(" %12f", mat4[ok][j].numf);
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						printf(" %12c", mat4[ok][j].letra);
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						printf(" %12s", mat4[ok][j].string);
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						printf(" %12lf", mat4[ok][j].numd);
					}

				}
				printf("\n");
				colunaSel = 0;
				while(colunaSel <= 0 || colunaSel >= coluna){
					setbuf(stdin, NULL);
					printf("Digite a coluna do valor a ser apagada: ");
					scanf("%d", &colunaSel);
					if(colunaSel <= 0 || colunaSel >= coluna)
						printf("A coluna nao pode ser modificada\n");
				}
				
				if(strcmp(tipo[colunaSel-1], "int") == 0){
					mat4[ok][colunaSel].numi = 0;
				}
				else if(strcmp(tipo[colunaSel-1], "float") == 0){
					mat4[ok][colunaSel].numf = 0;
				}
				else if(strcmp(tipo[colunaSel-1], "char") == 0){
					mat4[ok][colunaSel].letra = '0';
				}
				else if(strcmp(tipo[colunaSel-1], "string") == 0){
					strcpy(mat4[ok][colunaSel].string, "0");
				}
				else if(strcmp(tipo[colunaSel-1], "double") == 0){
					mat4[ok][colunaSel].numd = 0;
				}

				FILE *ar = fopen(idTab, "w");
				
				if(ar == NULL){
					printf("Erro na leitura do arquivo\n");
					strcpy(idTab, "");
					strcpy(id, "");
					return NULL;
				}
				else{
					/*
					Primeiramente, é gravado o numero de linhas, colunas e o tipo
					de dado de cada coluna para vacilitar a leitura do arquivo.
					*/
					fprintf(ar, "linhas: %d\ncolunas: %d\n", linha, coluna);
					for(j=0; j<coluna-1; j++){
						fprintf(ar, " %s\n", tipo[j]);
					}
					fprintf(ar, "\n");
					/*
					A seguir o código grava a tabela no arquivo, fazendo
					a operação correspondente ao tipo de dado da coluna.
					*/
					mat4[0][0].numi = 0;
					for(i=0; i<linha; i++){
						for(j=0; j<coluna; j++){
							if(i==0 && j>0){	
								fprintf(ar, " %12s", mat4[i][j].string);
							}
							else if(j==0){
								fprintf(ar, " %12d", mat4[i][j].numi);
							}
							else{
								if(strcmp(tipo[j-1], "int") == 0){
									fprintf(ar, " %12d", mat4[i][j].numi);
								}
								else if(strcmp(tipo[j-1], "float") == 0){
									fprintf(ar, " %12f", mat4[i][j].numf);
								}
								else if(strcmp(tipo[j-1], "char") == 0){
									fprintf(ar, " %12c", mat4[i][j].letra);
								}
								else if(strcmp(tipo[j-1], "string") == 0){
									fprintf(ar, " %12s", mat4[i][j].string);
								}
								else if(strcmp(tipo[j-1], "double") == 0){
									fprintf(ar, " %12lf", mat4[i][j].numd);
								}
							}
						}
						fprintf(ar, "\n");
					}
				}
				fclose(ar);	
			}
		}
			
		for(i=0; i<linha; i++){
			free(mat4[i]);
		}
		free(mat4);
		for(j=0; j<(coluna-1); j++){
			free(tipo[j]);
		}
		free(tipo);
		
	}
	strcpy(idTab, "");
	strcpy(id, "");
}