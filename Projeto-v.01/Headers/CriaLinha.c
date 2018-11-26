#include "CriaLinha.h"

void criarLinha(void){
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
		o tipo de dado de cada coluna. É feita a alocação de uma 
		matriz que guarda os valores da primeira linha da tabela 
		do arquivo.
		*/
		fscanf(arquivo, "linhas: %d\n", &linha);
		fscanf(arquivo, "colunas: %d\n", &coluna);
	
		mat1 = (char**) malloc((coluna-1) * sizeof(tab1*));
		tipo = (char**) malloc((coluna-1) * sizeof(char*));

		for(j=0; j<(coluna-1); j++){
			tipo[j] = (char*) malloc(6 * sizeof(char));
			fscanf(arquivo, " %s\n", tipo[j]);
		}

		for(j=0; j<coluna; j++){
			if(j==0){
				fseek(arquivo, 1, SEEK_CUR);
			}
			else{
				mat1[j-1] = (char*) malloc(20 * sizeof(tab1));
				fscanf(arquivo, " %12s\n", mat1[j-1]->string);
			}
		}
	
		fclose(arquivo);
		/*
		A variável "navolinha", receberá do usuário novas
		informações a serem adicionadas na tabela.
		*/
		novalinha = malloc((coluna-1) * sizeof(tab1));
		/*
		A sequir o arquivo é aberto utilazando o modo de
		abertura ("a"), que permite escrever a partir do final
		do arquivo.
		*/
		FILE *arq = fopen(idTab, "a");
		if(arq == NULL){
			printf("\t\tErro na leitura do arquivo\n");
			strcpy(idTab, "");
			strcpy(id, "");
			return NULL;
		}
		else{
			for(j=0; j<coluna; j++){
				if(j==0){
					fprintf(arq, " %12d", linha);
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						setbuf(stdin, NULL);
						printf("Digite um int em %s: ", mat1[j-1]->string);
						scanf("%d", &novalinha[j-1].numi);
						fprintf(arq, " %12d", novalinha[j-1].numi);
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						setbuf(stdin, NULL);
						printf("Digite um float em %s: ", mat1[j-1]->string);
						scanf("%f", &novalinha[j-1].numf);
						fprintf(arq, " %12f", novalinha[j-1].numf);
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						setbuf(stdin, NULL);
						printf("Digite um char em %s: ", mat1[j-1]->string);
						scanf("%c", &novalinha[j-1].letra);
						fprintf(arq, " %12c", novalinha[j-1].letra);
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						setbuf(stdin, NULL);
						printf("Digite uma string em %s: ", mat1[j-1]->string);
						scanf("%s", &novalinha[j-1].string);
						fprintf(arq, " %12s", novalinha[j-1].string);
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						setbuf(stdin, NULL);
						printf("Digite um double em %s: ", mat1[j-1]->string);
						scanf("%li", &novalinha[j-1].numd);
						fprintf(arq, " %12lf", novalinha[j-1].numd);
					}			
				}		
			}
		
			fprintf(arq, "\n");
			fclose(arq);

			FILE *ar = fopen(idTab, "r+");
			fprintf(ar, "linhas: %d", linha+1);
			fclose(ar);
			/*
			Por motivos já explicados é feita a liberação
			dos ponteiros.
			*/
			for(i=0; i<(coluna-1); i++){
				free(mat1[i]);
			}
			free(mat1);

			for(j=0; j<(coluna-1); j++){
				free(tipo[j]);
			}
			free(tipo);
			free(novalinha);
			strcpy(idTab, "");
			strcpy(id, "");
		}
	}
	strcpy(idTab, "");
	strcpy(id, "");
}