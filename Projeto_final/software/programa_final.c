#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curses.h>

//Struct do Usuário
typedef struct 
{
	char nome[60];
	char data_aniversario[40];
	char email[50];
	int numero;
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
		opcao = getchar();
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
		opcao = getchar();
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

	/*printf("Nome: ");
	scanf("%s", temp.nome);
	fflush(stdin);

	printf("Data de Nascimento: ");
	scanf("%s", temp.data_aniversario);
	fflush(stdin);

	printf("e-mail: ");
	scanf("%s", temp.email);
	fflush(stdin);*/

	i = 0;

	arquivo = fopen("test.txt", "r");
	while(!feof(arquivo))
	{
		fseek(arquivo, ftell(arquivo), SEEK_SET);
		fgets(temp.nome, sizeof(temp.nome), arquivo);
		//
		fgets(temp.data_aniversario, sizeof(temp.data_aniversario), arquivo);
		fgets(temp.email, sizeof(temp.email), arquivo);
	}
	printf("%s\n", temp.nome);
	printf("%s\n", temp.data_aniversario);
	printf("%s\n", temp.email);
	fclose(arquivo);

	system("sleep 5");
	//system("python3 novoUsuario.py");
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