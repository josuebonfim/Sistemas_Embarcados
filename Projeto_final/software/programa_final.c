#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curses.h>
//#include <conio.h>

//Struct do Usuário
typedef struct 
{
	char nome[60];
	char data_aniversario[40];
	char email[50];
	char numero[3];
}dados_usuario;

//Declaração das Funções
char validaOpcao(char opcao);
void novoUsuario();
void editaUsuario();
void deletaUsuario();


int main(int argc, char const *argv[])
{
	//Declarações
	char opcao;

	//Instruções

	//Apresenta o Menu
	system("clear");
	printf("Bem vindo ao Sistema de Controle de Acesso do LEI\n");
	printf("Laboratorio de Engenharia e Inovacao - UnB Gama\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	system("sleep 2");
	do
	{
		fflush(stdin);
		printf("%c\n", opcao);
		system("clear");
		printf("\t\t\t Menu de Opcoes: \n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("N - Novo Usuario\n");
		printf("E - Editar Usuario\n");
		printf("D - Deletar Usuario\n");
		printf("S - Sair do Menu\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("Digite a opcao de acordo com o menu acima: ");
		opcao = getche();
		fflush(stdin);
		opcao = validaOpcao(opcao);
		switch(opcao)
		{
			case 'N':
			{
				novoUsuario();
				break;
			}
			case 'E':
			{
				editaUsuario();
				break;
			}
			case 'D':
			{
				deletaUsuario();
			}
		}
	}while(opcao != 'S');
	return 0;
}

char validaOpcao(char opcao)
{
	while(toupper(opcao)!= 'N' && toupper(opcao) != 'E' && toupper(opcao) != 'D' && toupper(opcao) != 'S')
	{
		printf("\nOpcao invalida. Digite novamente: ");
		opcao = getche();
	}
}


void novoUsuario()
{
	FILE *arquivo;
	dados_usuario temp;
	int i;
	char teste;
	system("clear");
	printf("Cadastro de Usuario - Laboratorio Lei - UnB Gama\n");
	printf("\n");
	printf("\n");
	printf("\n");

	system("python3 novoUsuario.py");
}

void editaUsuario()
{
	system("clear");
	printf("Sistema em Manutencao. Contate a administração do laboratorio.\n");
	system("sleep 3");
}

void deletaUsuario()
{
	system("clear");
	printf("Sistema em Manutencao. Contate a administração do laboratorio.\n");
	system("sleep 3");
}