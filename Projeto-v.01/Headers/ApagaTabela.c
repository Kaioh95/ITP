#include "ApagaTabela.h"

void ApagaTabela () {
	char nome[20];
	printf ("\t\t Tabelas Disponiveis: ");
	setbuf(stdin, NULL);
	system("cd tabelas/ && ls *.txt -1 && cd ..");
	printf ("\n Digite o nome da tabela: ");
	setbuf(stdin, NULL);
	scanf ("%s", &nome);
	char Comando[38] = ("rm tabelas/");
	strcat(Comando,nome);
	strcat (Comando, ".txt");
	system (Comando);
	strcpy(nome, "");
	strcpy(Comando, "");
}
