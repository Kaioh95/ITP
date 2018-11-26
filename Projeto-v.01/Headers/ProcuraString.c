# include "ProcuraString.h"

void ProcuraString(void){
	strcat(idTab, "tabelas/");
	setbuf(stdin, NULL);
	printf("Digite o nome(id) da tabela: ");
	scanf("%s", &id);
	strcat(idTab, id);
	strcat(idTab, ".txt");

	FILE *arquivo = fopen(idTab, "r");

	if(arquivo == NULL){
		printf("\t\t\t\tTabela nao existente\n");
		strcpy(idTab, "");
		strcpy(id, "");
		return NULL;
	}
	else{
		fscanf(arquivo, "linhas: %d\n", &linha);
		fscanf(arquivo, "colunas: %d\n", &coluna);
	
		mat3 = (int**) malloc(linha * sizeof(tab3*));
		tipo = (char**) malloc((coluna-1) * sizeof(char*));

		for(j=0; j<(coluna-1); j++){
			tipo[j] = (char*) malloc(6 * sizeof(char));
			fscanf(arquivo, " %s\n", tipo[j]);
		}
		
		
		for(i=0; i<linha; i++){
			mat3[i] = (int*) malloc(coluna * sizeof(tab3));
			fseek(arquivo, 1, SEEK_CUR);
			for(j=0; j<coluna; j++){
				if(i==0 && j>0){
					fscanf(arquivo, " %12s", mat3[i][j].string);
				}
				else if(j==0){
					fscanf(arquivo, " %12d", &mat3[i][j].numi);				
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						fscanf(arquivo, " %12d", &mat3[i][j].numi);
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						fscanf(arquivo, " %12f", &mat3[i][j].numf);
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						fscanf(arquivo, " %12c", &mat3[i][j].letra);
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						fscanf(arquivo, " %12s", mat3[i][j].string);					
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						fscanf(arquivo, " %12lf", &mat3[i][j].numd);
					}

				}

			}

		}
	}

	fclose(arquivo);
	printf("\n");
	mat3[0][0].numi = 0;

	printf ("Colunas Disponiveis: \n");

	for (i = 1; i < coluna; i++){
		printf ("%i - %s \n", i, mat3[0][i].string);
	}

	printf ("Digite o numero da coluna correspondente: ");
	setbuf(stdin, NULL);
	scanf ("%i", &l);
	setbuf(stdin, NULL);
	while (l >= i || l < 1 ){
		printf ("Opção invalida, digite novamente: ");
		setbuf(stdin, NULL);
		scanf ("%i", &l);
	}

	printf ("Coluna (%s)\n", mat3[0][l].string);
	
//  fazer o tratatamento por tipo;
	if(strcmp(tipo[l-1], "int") == 0){
		printf ("Digite um valor do tipo inteiro: ");
		setbuf(stdin, NULL);
		scanf ("%i", &valor.numi);
	}
	else if(strcmp(tipo[l-1], "float") == 0){
		printf ("Digite um valor do tipo float: ");
		setbuf(stdin, NULL);
		scanf ("%f", &valor.numf);
	}
	else if(strcmp(tipo[l-1], "char") == 0){
		printf ("Digite um valor do tipo char: ");
		setbuf(stdin, NULL);
		scanf ("%c", &valor.letra);

	}
	else if(strcmp(tipo[l-1], "string") == 0){
		printf ("Digite um valor do tipo string: ");
		setbuf(stdin, NULL);
		scanf ("%s", &valor.string);
	}
	else if(strcmp(tipo[l-1], "double") == 0){
		printf ("Digite um valor do tipo double: ");
		setbuf(stdin, NULL);
		scanf ("%lf", &valor.numd);
	}

	system ("clear");
	printf ("Coluna (%s)\n", mat3[0][l].string);
	printf ("Escolha Uma das opcoes abaixo: \n");
	printf("- 1 - Valores maiores( Digite 1): \n- 2 - Valores maiores ou iguais (Digite 2): \n- 3 - Valores menores (Digite 3): \n- 4 - Valores Menores ou iguais (Digite 4): \n- 5 - Valores Iguais (Digite 5):\n");
	if(strcmp(tipo[l-1], "string") == 0){
		printf ("- 6 - Valores Proximos (Digite 6): \n");
	}
	printf ("Digite a opcao desejada: ");

	setbuf(stdin, NULL);
	scanf ("%i", &k);

	if (k == 1){
		mat3[0][0].numi = 0;
		for(i=0; i<linha; i++){
			for(j=0; j<coluna; j++){
				if(i==0 && j>0){
					printf(" %12s ", mat3[i][j].string);	
				}
				else if(j==0){
					printf(" %12d ", mat3[i][j].numi);
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						if(strcmp(tipo[l-1], "int") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].numi > valor.numi){
								printf (">%12i<", mat3[i][j].numi);
							}
							else{
								printf (" %12i ", mat3[i][j].numi);
							}
						}
						else{
							printf (" %12i ", mat3[i][j].numi);
						}
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						if (strcmp(tipo[l-1], "float") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].numf > valor.numf){
								printf (">%12f<", mat3[i][j].numf);
							}
							else{
								printf(" %12f ", mat3[i][j].numf);
							}
						}
						else{
							printf(" %12f ", mat3[i][j].numf);
						}
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						if(strcmp(tipo[l-1], "char") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].letra > valor.letra){
								printf (">%12c<", mat3[i][j].letra);
							}
							else{
								printf(" %12c ", mat3[i][j].letra);
							}
						}
						else{
							printf(" %12c ", mat3[i][j].letra);
						}			
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						if(strcmp(tipo[l-1], "string") == 0 && (l-1) == (j-1)){
							if (strcmp(mat3[i][j].string, valor.string) > 0){
								printf (">%12s<", mat3[i][j].string);
							}
							else{
								printf (" %12s ", mat3[i][j].string);
							}
						}
						else{
							printf (" %12s ", mat3[i][j].string);
						}
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						if(strcmp(tipo[l-1], "double") == 0 && (l-1) == (j-1)){	
							if (mat3[i][j].numd > valor.numd){
								printf (">%12lf<", mat3[i][j].numd);
							}
							else{
								printf (" %12lf ", mat3[i][j].numd);
							}
						}
						else{
							printf (" %12lf ", mat3[i][j].numd);
						}
					}
				}			
			}
			printf("\n");
		}
		printf("\n");
	}
	else if (k == 2){
		mat3[0][0].numi = 0;
		for(i=0; i<linha; i++){
			for(j=0; j<coluna; j++){
				if(i==0 && j>0){
					printf(" %12s ", mat3[i][j].string);	
				}
				else if(j==0){
					printf(" %12d ", mat3[i][j].numi);
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						if (strcmp(tipo[l-1], "int") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].numi >= valor.numi){
								printf(">%12i<", mat3[i][j].numi);
							}
							else{
								printf(" %12i ", mat3[i][j].numi);
							}
						}
						else{
							printf(" %12i ", mat3[i][j].numi);
						}

					}
					else if(strcmp(tipo[j-1], "float") == 0){
						if (strcmp(tipo[l-1], "float") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].numf >= valor.numf){
								printf (">%12f<", mat3[i][j].numf);
							}
							else{
								printf (" %12f ", mat3[i][j].numf);
							}
						}
						else{
							printf (" %12f ", mat3[i][j].numf);
						}
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						if(strcmp(tipo[l-1], "char") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].letra >= valor.letra){
								printf (">%12c<", mat3[i][j].letra);
							}
							else{
								printf(" %12c ", mat3[i][j].letra);
							}
						}
						else{
							printf(" %12c ", mat3[i][j].letra);
						}			
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						if(strcmp(tipo[l-1], "string") == 0 && (l-1) == (j-1)){
							if (strcmp(mat3[i][j].string, valor.string) >= 0){
								printf (">%12s<", mat3[i][j].string);
							}
							else{
								printf (" %12s ", mat3[i][j].string);
							}
						}
						else{
							printf (" %12s ", mat3[i][j].string);
						}
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						if(strcmp(tipo[l-1], "double") == 0 && (l-1) == (j-1)){	
							if (mat3[i][j].numd >= valor.numd){
								printf (">%12lf<", mat3[i][j].numd);
							}
							else{
								printf(" %12lf ", mat3[i][j].numd);
							}
						}
						else{
							printf(" %12lf ", mat3[i][j].numd);
						}
					}
				}			
			}
			printf("\n");
		}
		printf("\n");
	}
	else if (k == 3){
		mat3[0][0].numi = 0;
		for(i=0; i<linha; i++){
			for(j=0; j<coluna; j++){

				if(i==0 && j>0){
					printf(" %12s ", mat3[i][j].string);	
				}
				else if(j==0){
					printf(" %12d ", mat3[i][j].numi);
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						if (strcmp(tipo[l-1], "int") == 0 && (l-1) == (j-1)){
							if(mat3[i][j].numi < valor.numi){
								printf (">%12i<", mat3[i][j].numi);
							}
							else{
								printf(" %12i ", mat3[i][j].numi);
							}
						}
						else{
							printf(" %12i ", mat3[i][j].numi);
						}
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						if(strcmp(tipo[l-1], "float") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].numf < valor.numf){
								printf (">%12f<", mat3[i][j].numf);
							}
							else{
								printf (" %12f ", mat3[i][j].numf);
							}
						}
						else{
							printf(" %12f ", mat3[i][j].numf);
						}
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						if(strcmp(tipo[l-1], "char") == 0 && (l-1) == (j-1)){
							if(mat3[i][j].letra < valor.letra){
								printf (">%12c<", mat3[i][j].letra);
							}
							else{
							printf(" %12c ", mat3[i][j].letra);
							}
						}
						else{
							printf(" %12c ", mat3[i][j].letra);
						}			
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						if(strcmp(tipo[l-1], "string") == 0 && (l-1) == (j-1)){
							if (strcmp(mat3[i][j].string, valor.string) < 0){
								printf (">%12s<", mat3[i][j].string);
							}
							else{
							printf (" %12s ", mat3[i][j].string);
							}
						}
						else{
							printf(" %12s ", mat3[i][j].string);
						}
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						if(strcmp(tipo[l-1], "double") == 0 && (l-1) == (j-1)){	
							if (mat3[i][j].numd < valor.numd){
								printf (">%12lf<", mat3[i][j].numd);
							}
							else{
								printf(" %12lf ", mat3[i][j].numd);
							}
						}
						else{
							printf(" %12lf ", mat3[i][j].numd);
						}
					}
				}			
			}
			printf("\n");
		}
		printf("\n");
	}
	else if (k == 4){
		mat3[0][0].numi = 0;
		for(i=0; i<linha; i++){
			for(j=0; j<coluna; j++){
				if(i==0 && j>0){
					printf(" %12s ", mat3[i][j].string);	
				}
				else if(j==0){
					printf(" %12d ", mat3[i][j].numi);
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						if (strcmp(tipo[l-1], "int") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].numi <= valor.numi){
								printf (">%12i<", mat3[i][j].numi);
							}
							else{
								printf (" %12i ", mat3[i][j].numi);
							}
						}
						else{
							printf(" %12i ", mat3[i][j].numi);
						}
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						if (strcmp(tipo[l-1], "float") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].numf <= valor.numf){
								printf(">%12f<", mat3[i][j].numf);
							}
							else{
							printf(" %12f ", mat3[i][j].numf);
							}
						}
						else{
							printf(" %12f ", mat3[i][j].numf);
						}
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						if(strcmp(tipo[l-1], "char") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].letra <= valor.letra){
								printf(">%12c<", mat3[i][j].letra);
							}
							else{
								printf(" %12c ", mat3[i][j].letra);
							}
						}
						else{
							printf(" %12c ", mat3[i][j].letra);
						}			
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						if(strcmp(tipo[l-1], "string") == 0 && (l-1) == (j-1)){
							if(strcmp(mat3[i][j].string, valor.string) <= 0){
								printf (">%12s<", mat3[i][j].string);
							}
							else{
								printf (" %12s ", mat3[i][j].string);
							}
						}
						else{
							printf(" %12s ", mat3[i][j].string);
						}
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						if(strcmp(tipo[l-1], "double") == 0 && (l-1) == (j-1)){	
							if(mat3[i][j].numd <= valor.numd){
								printf (">%12lf<", mat3[i][j].numd);
							}
							else{
								printf (" %12lf ", mat3[i][j].numd);
							}
						}
						else{
							printf(" %12lf ", mat3[i][j].numd);
						}
					}
				}			
			}
			printf("\n");
		}
		printf("\n");
	}
	else if (k == 5){
		mat3[0][0].numi = 0;
		for(i=0; i<linha; i++){
			for(j=0; j<coluna; j++){
				if(i==0 && j>0){
					printf(" %12s ", mat3[i][j].string);	
				}
				else if(j==0){
					printf(" %12d ", mat3[i][j].numi);
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						if (strcmp(tipo[l-1], "int") == 0){
							if(mat3[i][j].numi == valor.numi && (l-1) == (j-1)){
								printf (">%12i<", mat3[i][j].numi);
							}
							else{
								printf(" %12i ", mat3[i][j].numi);
							}
						}
						else{
							printf(" %12i ", mat3[i][j].numi);
						}
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						if(strcmp(tipo[l-1], "float") == 0 && (l-1) == (j-1)){
							if(mat3[i][j].numf == valor.numf){
								printf (">%12f<", mat3[i][j].numf);
							}
							else{
								printf (" %12f ", mat3[i][j].numf);
							}
						}
						else{
							printf(" %12f ", mat3[i][j].numf);
						}
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						if(strcmp(tipo[l-1], "char") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].letra == valor.letra){
								printf (">%12c<", mat3[i][j].letra);
							}
							else{
								printf(" %12c ", mat3[i][j].letra);
							}
						}
						else{
							printf(" %12c ", mat3[i][j].letra);
						}			
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						if(strcmp(tipo[l-1], "string") == 0 && (l-1) == (j-1)){
							if (strcmp(mat3[i][j].string, valor.string) == 0){
								printf(">%12s<", mat3[i][j].string);
							}
							else{
								printf(" %12s ", mat3[i][j].string);
							}
						}
						else{
							printf(" %12s ", mat3[i][j].string);
						}
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						if(strcmp(tipo[l-1], "double") == 0 && (l-1) == (j-1)){	
							if (mat3[i][j].numd == valor.numd){
								printf (">%12lf<", mat3[i][j].numd);
							}
							else{
								printf (" %12lf ", mat3[i][j].numd);
							}
						}
						else{
							printf (" %12lf ", mat3[i][j].numd);
						}
					}
				}			
			}
			printf ("\n");
		}
		printf("\n");
	}
	else if (k == 6 && (strcmp(tipo[l-1], "string") == 0)){
		mat3[0][0].numi = 0;
		for(i=0; i<linha; i++){
			for(j=0; j<coluna; j++){
				if(i==0 && j>0){
					printf(" %12s ", mat3[i][j].string);	
				}
				else if(j==0){
					printf(" %12d ", mat3[i][j].numi);
				}
				else{
					if(strcmp(tipo[j-1], "int") == 0){
						if (strcmp(tipo[l-1], "int") == 0){
							if (mat3[i][j].numi == valor.numi && (l-1) == (j-1)){
								printf (">%12i<", mat3[i][j].numi);
							}
							else{
								printf(" %12i ", mat3[i][j].numi);
							}
						}
						else{
							printf(" %12i ", mat3[i][j].numi);
						}
					}
					else if(strcmp(tipo[j-1], "float") == 0){
						if (strcmp(tipo[l-1], "float") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].numf == valor.numf){
								printf (">%12f<", mat3[i][j].numf);
							}
							else{
								printf (" %12f ", mat3[i][j].numf);
							}
						}
						else{
							printf(" %12f ", mat3[i][j].numf);
						}
					}
					else if(strcmp(tipo[j-1], "char") == 0){
						if(strcmp(tipo[l-1], "char") == 0 && (l-1) == (j-1)){
							if (mat3[i][j].letra == valor.letra){
								printf (">%12c<", mat3[i][j].letra);
							}
							else{
								printf(" %12c ", mat3[i][j].letra);
							}
						}
						else{
							printf(" %12c ", mat3[i][j].letra);
						}
					}
					else if(strcmp(tipo[j-1], "string") == 0){
						if(strcmp(tipo[l-1], "string") == 0 && (l-1) == (j-1)){
							if (strcmp(mat3[i][j].string, valor.string) >= -3){
								printf(">%12s<", mat3[i][j].string);
							}
							else{
								printf(" %12s ", mat3[i][j].string);
							}
						}
						else{
							printf(" %12s ", mat3[i][j].string);
						}
					}
					else if(strcmp(tipo[j-1], "double") == 0){
						if(strcmp(tipo[l-1], "double") == 0 && (l-1) == (j-1)){	
							if (mat3[i][j].numd == valor.numd){
								printf(">%12lf<", mat3[i][j].numd);
							}
							else{
								printf(" %12lf ", mat3[i][j].numd);
							}
						}
						else{
							printf(" %12lf ", mat3[i][j].numd);
						}
					}
				}			
			}
			printf("\n");
		}
		printf("\n");
	}
	else{
		printf ("Opcao invalida. \n");
	}

	for(i=0; i<linha; i++){
		free(mat3[i]);
	}
	free(mat3);
	for(j=0; j<(coluna-1); j++){
		free(tipo[j]);
	}
	free(tipo);
	strcpy(idTab, "");
	strcpy(id, "");

}