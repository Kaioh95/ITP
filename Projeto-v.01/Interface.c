#include <stdio.h>
#include <stdlib.h>
#include "Headers/CriaTabela.h"
#include "Headers/CriaLinha.h"
#include "Headers/ListaDados.h"
#include "Headers/ProcuraString.h"
#include "Headers/ApagaValor.h"
#include "Headers/ApagaTabela.h"
#include "Headers/CriaColuna.h"

int main(void){
	/*	funcionalidades extras
	criar coluna na tabela e adicionar a nova info em cada linha
	Apagar linha ou conluna de uma tabela
	*/
	int n;
	system("clear");
	while(n){
		printf("\t\t\t\tSGBD ITP\n");
		printf("\t\t(1)Criar tabela\n");
		printf("\t\t(2)Listar tabelas\n");
		printf("\t\t(3)Criar uma nova linha na tabela\n");
		printf("\t\t(4)Listar todos os dados de uma tabela\n");
		printf("\t\t(5)Pesquisar um valor na tabela\n");
		printf("\t\t(6)Apagar valor de uma tabela\n");
		printf("\t\t(7)Apagar tabela\n");
		printf("\t\t(8)Cria Coluna\n");
		printf("\t\t(0)Fechar o programa\n");
		printf("\t\t\t\tVersao 1.0\n");
		printf("\t------------------------------------------------------\n");
		printf("\t\tDigite uma opcao: ");
		scanf("%d", &n);

		
		if(n==1){
			criar();
			printf("\t------------------------------------------------------\n");
		}
		if(n==2){
			printf("\t\t\t\tTABELAS\n");
			setbuf(stdin, NULL);
			system("cd tabelas/ && ls *.txt -1 && cd ..");
			printf("\t------------------------------------------------------\n");
		}		
		if(n==3){
			criarLinha();
			printf("\t------------------------------------------------------\n");		
		}
		if(n==4){
			listarDados();
			printf("\t------------------------------------------------------\n");
		}
		
		if(n==5){
			ProcuraString();
			printf("\t------------------------------------------------------\n");
		}
		if(n==6){
			apagarValor();
			printf("\t------------------------------------------------------\n");
		}
		if(n==7){
			ApagaTabela();
			printf("\t------------------------------------------------------\n");
		}
		if(n==8){
			CriaColuna();
			printf("\t------------------------------------------------------\n");
		}	
	}

	return 0;
}