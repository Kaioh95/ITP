#include "CriaTabela.h"

void criar(void){
	strcat(idTab, "tabelas/");
	setbuf(stdin, NULL);
	printf("Digite o numero de linhas e colunas da tabela, respectivamente: ");
	scanf("%d %d", &linha, &coluna);
	linha++;
	setbuf(stdin, NULL);
	printf("Digite o nome(id) da tabela: ");
	scanf("%s", &id);
	/*
	Em idTab é feita concatenação do endereço onde será salvo
	as tabelas com a string "(id da tabela).txt" para
	a criação do arquivo posteriorente.
	*/
	strcat(idTab, id);
	strcat(idTab, ".txt");
	/*
	Alocação dinâmica de uma matriz com um novo tipo criado a partir
	de um struct, permitindo a criação de um matriz com todos os tipos
	de dados primitivos.
	*/
	mat = (int**) malloc(linha * sizeof(tab*));
	/*
	Alocação de um vetor que guarda o tipo de dado de cada
	coluna da tabela.
	*/
	tipo = (char**) malloc(coluna * sizeof(char*));

	for(i=0; i<linha; i++){
		mat[i] = (int*) malloc(coluna * sizeof(tab));
		
		for(j=0; j<coluna; j++){
			
			if(i==0){
				tipo[j] = (char*) malloc(6 * sizeof(char));
				setbuf(stdin, NULL);
				printf("Linha %d e coluna %d\n", i+1, j+1);
				setbuf(stdin, NULL);
				printf("Digite o tipo de dado (int, float, char, string ou double): ");
				scanf("%s", &tipo[j][0]);
				ok = 1;
				/*
				No seguinte bloco while é feito o tratamento caso o usuário digite 
				um tipo de dado inválido.
				*/
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
				/*
				A seguir é ultilizado vetor(tipo) que define o tipo
				de dado de cada coluna da tabela para fazer a operação
				correspondente a tipo de dado, pois o struct utilizado
				para a alocação da matriz, tem uma variável para cada
				tipo de dado.
				*/
				if(strcmp(tipo[j], "int") == 0){
					setbuf(stdin, NULL);
					printf("Digite um int em %s: ", mat[0][j].string);
					scanf("%d", &mat[i][j].numi);
				}
				else if(strcmp(tipo[j], "float") == 0){
					setbuf(stdin, NULL);
					printf("Digite um float em %s: ", mat[0][j].string);
					scanf("%f", &mat[i][j].numf);
				}
				else if(strcmp(tipo[j], "char") == 0){
					setbuf(stdin, NULL);
					printf("Digite um char em %s: ", mat[0][j].string);
					scanf("%c", &mat[i][j].letra);
				}
				else if(strcmp(tipo[j], "string") == 0){
					setbuf(stdin, NULL);
					printf("Digite uma string em %s: ", mat[0][j].string);
					scanf("%s", &mat[i][j].string);
				}
				else if(strcmp(tipo[j], "double") == 0){
					setbuf(stdin, NULL);
					printf("Digite um double em %s: ", mat[0][j].string);
					scanf("%lf", &mat[i][j].numd);
				}

			}

		}

		
	}

	/*
	Criação do arquivo fazendo a utilização da variável(idTab)
	mencionada no início do código. 
	*/

	FILE *arquivo = fopen(idTab, "w");
	/*
	Primeiramente, é gravado o numero de linhas, colunas e o tipo
	de dado de cada coluna para vacilitar a leitura do arquivo
	posteriormente em outra função.
	*/
	fprintf(arquivo, "linhas: %d\ncolunas: %d\n", linha, coluna+1);
	for(j=0; j<coluna; j++){
		fprintf(arquivo, " %s\n", tipo[j]);
	}
	fprintf(arquivo, "\n");
	/*
	A seguir o código grava a tabela no arquivo, fazendo
	a operação correspondente ao tipo de dado da coluna.
	*/
	for(i=0; i<linha; i++){
			fprintf(arquivo, " %12d", i);
		for(j=0; j<coluna; j++){
			if(i==0){
				fprintf(arquivo, " %12s", mat[i][j].string);
			}
			else if(strcmp(tipo[j], "int") == 0){
				fprintf(arquivo, " %12d", mat[i][j].numi);
			}
			else if(strcmp(tipo[j], "float") == 0){
				fprintf(arquivo, " %12f", mat[i][j].numf);
			}
			else if(strcmp(tipo[j], "char") == 0){
				fprintf(arquivo, " %12c", mat[i][j].letra);
			}

			else if(strcmp(tipo[j], "string") == 0){
				fprintf(arquivo, " %12s", mat[i][j].string);
			}
			else if(strcmp(tipo[j], "double") == 0){
				fprintf(arquivo, " %12lf", mat[i][j].numd);
			}	
		}
		fprintf(arquivo, "\n");
	}
	fclose(arquivo);
	/*
	Como a matriz e o vetor alocados inicialmente no código
	estão ocupando um espaço na memória RAM, estão é necessário
	que seja feita a liberação desse espaço alocado. Afinal,
	fazemos jus ao nome da dupla.
	*/
	for(i=0; i<linha; i++){
		free(mat[i]);
	}
	free(mat);

	for(j=0; j<coluna; j++){
		free(tipo[j]);
	}
	free(tipo);
	strcpy(idTab, "");
	strcpy(id, "");

}