#include "CriaColuna.h"

void CriaColuna(){
strcat(idTab, "tabelas/");
	setbuf(stdin, NULL);
	printf("Digite o nome(id) da tabela: ");
	scanf("%s", &id);
	strcat(idTab, id);
	strcat(idTab, ".txt");

	FILE *arquivo = fopen(idTab, "r");

	if(arquivo == NULL){
		printf("\t\t\t\tTabela nao existente \n");
		strcpy(idTab, "");
		strcpy(id, "");
		return NULL;
	}
	else{
		fscanf(arquivo, "linhas: %d\n", &linha);
		fscanf(arquivo, "colunas: %d\n", &coluna);
		mat5 = (int**) malloc((linha) * sizeof(tab5*));
		tipo = (char**) malloc((coluna) * sizeof(char*));
		for(j=0; j<(coluna); j++){
			if (j != coluna-1){
				tipo[j] = (char*) malloc(6 * sizeof(char));
				fscanf(arquivo, " %s\n", tipo[j]);
				printf ("%12s \n", tipo[j]);
			}
			else {
				tipo[j] = (char*) malloc(6 * sizeof(char));
				printf ("Digite o tipo de dado da nova coluna: ");
				scanf("%s", tipo[j]);
				ok = 1;
				while(ok){
					if((strcmp(tipo[j], "int") == 0) || (strcmp(tipo[j], "float") == 0) || (strcmp(tipo[j], "char") == 0) || (strcmp(tipo[j], "string") == 0) || (strcmp(tipo[j], "double") == 0)){
						ok = 0;
					}
					else{
						setbuf(stdin, NULL);
						printf("Tipo invalido digite novamente: ");
						scanf("%s", &tipo[j]);
					}
				}
			}
		}
		printf ("\n\n");
		coluna +=1;
		for(i=0; i<linha; i++){
			mat5[i] = (int*) malloc(coluna * sizeof(tab5));
			fseek(arquivo, 1, SEEK_CUR);
			for(j=0; j<coluna; j++){
				if(i==0 && j>0){
					if (j == (coluna-1)){
						printf ("Digite o nome da coluna: ");
						setbuf(stdin, NULL);
						scanf ("%s", &mat5[i][j].string);
					}
					else{
						fscanf(arquivo, " %12s", &mat5[i][j].string);
						//printf(" %12s", mat5[i][j].string);
					}
				}
				else if(j==0){
					fscanf(arquivo, " %12d", &mat5[i][j].numi);
					//printf(" %12d", mat5[i][j].numi);				
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						if (j == (coluna-1)){
							printf (" Digite um int: ");
							setbuf(stdin, NULL);
							scanf ("%i", &mat5[i][j].numi);
							//printf(" %12d", mat5[i][j].numi);
						}
						else{
							fscanf(arquivo, " %12d", &mat5[i][j].numi);
							//printf(" %12d", mat5[i][j].numi);
						}
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						if (j == (coluna-1)){
							printf (" Digite um float: ");
							setbuf(stdin, NULL);
							scanf ("%f", &mat5[i][j].numf);
							//printf(" %12f", mat5[i][j].numf);
						}
						else{
							fscanf(arquivo, " %12f", &mat5[i][j].numf);
							//printf(" %12f", mat5[i][j].numf);
						}
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						if (j == (coluna-1)){
							printf (" Digite um char: ");
							setbuf(stdin, NULL);
							scanf ("%c", &mat5[i][j].letra);
							//printf(" %12c", mat5[i][j].letra);
						}
						else{				
							fscanf(arquivo, " %12c", &mat5[i][j].letra);
							//printf(" %12c", mat5[i][j].letra);
						}
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						if (j == (coluna-1)){
							printf (" Digite uma string: ");
							setbuf(stdin, NULL);
							scanf ("%s", &mat5[i][j].string);
							//printf(" %12s", mat5[i][j].string);
						}
						else{
							fscanf(arquivo, " %12s", &mat5[i][j].string);
							//printf(" %12s", mat5[i][j].string);	
						}				
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						if (j == (coluna-1)){
							printf (" Digite um double: ");
							setbuf(stdin, NULL);
							scanf ("%lf", &mat5[i][j].numd);
							//printf(" %12lf", mat5[i][j].numd);
						}
						else{
							fscanf(arquivo, " %12lf", &mat5[i][j].numd);
							//printf(" %12lf", mat5[i][j].numd);
						}
					}
				}
			}
		}
	}
	fclose(arquivo);
	printf("\n");

	arquivo = fopen(idTab, "w");
	
	fprintf(arquivo, "linhas: %d\ncolunas: %d\n", linha, coluna);
	printf ("Numero de colunas: %i\n", coluna);
	for(j=0; j<(coluna-1); j++){
		fprintf(arquivo, " %s\n", tipo[j]);
	}

	fprintf(arquivo, "\n");
	for(i=0; i<linha; i++){
//			fprintf(arquivo, " %12d", i);
		for(j=0; j<coluna; j++){
			
			if(i==0 && j > 0){
				fprintf(arquivo, " %12s", mat5[i][j].string);
			}
			else if (j == 0){
				fprintf(arquivo, " %12d", mat5[i][j].numi);
			}
			else{
				if(strcmp(tipo[j-1], "int") == 0){
					fprintf(arquivo, " %12d", mat5[i][j].numi);
				}
				else if(strcmp(tipo[j-1], "float") == 0){
					fprintf(arquivo, " %12f", mat5[i][j].numf);
				}
				else if(strcmp(tipo[j-1], "char") == 0){
					fprintf(arquivo, " %12c", mat5[i][j].letra);
				}
				else if(strcmp(tipo[j-1], "string") == 0){
					fprintf(arquivo, " %12s", mat5[i][j].string);
				}
				else if(strcmp(tipo[j-1], "double") == 0){
					fprintf(arquivo, " %12lf", mat5[i][j].numd);
				}
			}	
		}
		fprintf(arquivo, "\n");
	}
	for(i=0; i<linha; i++){
		free(mat5[i]);
	}
	free(mat5);
	for(j=0; j<(coluna-1); j++){
		free(tipo[j]);
	}

	fclose(arquivo);
	strcpy(idTab, "");
		strcpy(id, "");
}