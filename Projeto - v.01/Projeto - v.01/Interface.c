#include <stdio.h>
#include <stdlib.h>
#include "CriaTabela.h"

int main(void){
	/*	funcionalidades extras
	criar coluna na tabela e adicionar a nova info em cada linha
	Apagar linha ou conluna de uma tabela
	*/
	int n;
	system("clear");
	printf("\t\t\t\tSGBD ITP\n");
	printf("\t\t(1)Cria tabela\n");
	printf("\t\t(2)Lista tabelas\n");
	printf("\t\t(3)Cria uma nova linha na tabela\n");
	printf("\t\t(4)Lista todos os dados de uma tabela\n");
	printf("\t\t(5)Pesquisa um valor na tabela\n");
	printf("\t\t(6)Apaga valor de uma tabela\n");
	printf("\t\t(7)Apaga tabela\n");
	printf("\t\t\t\tVersao 0.01\n");
	printf("\t------------------------------------------------------\n");
	printf("\t\tDigite uma opcao: ");
	scanf("%d", &n);

	
	if(n==1)
		criar();

	if(n==2)
		printf("\t\t\t\tTABELAS\n");
		setbuf(stdin, NULL);
		system("ls *.txt");
		printf("\n");
	/*		
	if(n==3)
		criarLinha();
	if(n==4)
		listDados();
	if(n==5)
		pesquisa();
	if(n==6)
		apagaValor();
	if(n==7)
		apagaTabela();
	*/


	return 0;
}