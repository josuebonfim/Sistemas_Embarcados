#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curses.h>
#include <stdio_ext.h>
#include <wiringPi.h>         
#include <lcd.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

//USE WIRINGPI PIN NUMBERS
#define LCD_RS  25               //Register select pin
#define LCD_E   24               //Enable Pin
#define LCD_D4  23               //Data pin 4
#define LCD_D5  22               //Data pin 5
#define LCD_D6  21               //Data pin 6
#define LCD_D7  14               //Data pin 7

//Struct do Usuário
typedef struct 
{
	char nome[60];
	char data_aniversario[40];
	char email[50];
	char numero[3];
}dados_usuario;

char etapa;
int contagem = 0, controle = 0;


//Declaração das Funções
char validaOpcao(char opcao);
void novoUsuario();
int deletaUsuario();
void mostraUsuarios();

void *le_digital (void *arg)
{
	int fp;
	fp = open("out.txt", O_WRONLY);
	close(fp);
	if(controle == 0)
	{
		system("rm out.txt");
	}
	do
	{
		system("python le_digital.py | pidof python >> out.txt");
		system("rm out.txt");
	}
	while(1);
	return NULL;
}

void tratamento_alarme(int sig)
{
	char pid[50], c, comando[] = "kill ";
	int fp, i;
	alarm(1);
	i = 0;
	fp = open("out.txt",O_RDONLY);
	if(fp == -1)
		printf("O arquivo nao pode ser aberto");
	else
	{
		
		while((read(fp, &c, 1)) != 0)
		{
			pid[i] = c;
			i++;
		}
		
		close(fp);
		pid[i] = '\0';
		strcat(comando, pid);
		system(comando);
		
		system("rm out.txt");
		pid[0] = '\0';
	}
	
	
}



int main(int argc, char const *argv[])
{
	//Declarações
	char opcao;
	FILE *arquivo;
	int lcd, i, fp;
	char pid[10], c, comando[] = "kill ";
	
	signal(SIGALRM, tratamento_alarme);
	
	pthread_t t;


	//Instruções

	//Apresenta o Menu
	wiringPiSetup();
	lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);
	
	lcdClear(lcd);
	
	lcdPosition(lcd, 0, 0);
	lcdPuts(lcd, " Acesso ao LEI");
	lcdPosition(lcd, 0, 1);
	lcdPuts(lcd, "   UnB - FGA");
	
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
		pthread_create(&t, NULL, le_digital, NULL);
		controle++;
		lcdClear(lcd);
		lcdPosition(lcd, 0, 0);
		lcdPuts(lcd, " Acesso ao LEI");
		lcdPosition(lcd, 0, 1);
		lcdPuts(lcd, "   UnB - FGA");
	
		__fpurge(stdin);
		opcao = 0;
		//printf("%c\n", opcao);
		system("clear");
		printf("\t\t\t Menu de Opcoes: \n");
		contagem = 0;
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
		//system("python3 opcao_menu.py");
		//arquivo = fopen("pipe.txt", "r");
		//opcao = fgetc(arquivo);
		//fclose(arquivo);
		//system("rm pipe.txt");
		if(!contagem)
		{
			printf("Digite a opcao desejada: ");
			opcao = validaOpcao(fgetc(stdin));
			
		}
		printf("\n\n\n\n");
		contagem = 1;
		__fpurge(stdin);
		//clean_buffer();
		switch(opcao)
		{
			case 'N':
			{
				system("./kill_teste");
				pthread_cancel(t);
				//pthread_join(t, NULL);
				novoUsuario();
				break;
			}
			case 'D':
			{
				system("./kill_teste");
				pthread_cancel(t);
				deletaUsuario();
				break;
			}
			case 'M':
			{
				system("./kill_teste");
				pthread_cancel(t);
				mostraUsuarios();
				break;
			}
		}
	}while(opcao != 'S');
	lcdClear(lcd);
	system("./kill_teste");
	pthread_cancel(t);
	return 0;
}

void novoUsuario()
{
	//Declaracao de variaveis
	FILE *arquivo;
	int fp;
	dados_usuario temp;
	char string[] = "mkdir ", temporaria[50], temporaria2[50];
	int i, j = 0;
	char c, nome[50];
	int lcd;
	signal(SIGALRM, tratamento_alarme);
	
	wiringPiSetup();
    lcd = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);
	
	lcdClear(lcd);
	
	lcdPosition(lcd, 0, 0);
	lcdPuts(lcd, "  Cadastro de");
	lcdPosition(lcd, 0, 1);
	lcdPuts(lcd, "    Usuarios");
	
	
	//Menu de apresentacao
	__fpurge(stdin);
	__fpurge(stdout);
	system("clear");
	printf("Cadastro de Usuario - Laboratorio Lei - UnB Gama\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
	//Digitar o nome do usuario
	printf("\n\n\nDigite o nome no formato\n");
	printf("NOME SOBRENOME: ");
	fgets(temp.nome, 60*sizeof(char), stdin);
	if(temp.nome[strlen(temp.nome)-1] == '\n')
		temp.nome[strlen(temp.nome)-1] = '\0';
	__fpurge(stdin);
	__fpurge(stdout);
	
	//Digitar o email do usuario
	printf("\n\n\nDigite o email: ");
	fgets(temp.email, 50*sizeof(char), stdin);
	__fpurge(stdin);
	__fpurge(stdout);
	
	//Digitar a data de nascimento do usuario
	printf("\n\n\nDigite a data de nascimento\n");
	printf("no formato DD/MM/AAAA: ");
	fgets(temp.data_aniversario, 40*sizeof(char), stdin);
	__fpurge(stdin);
	__fpurge(stdout);
	
	
	/*
	system("python3 move_python.py");
	system("./upload.sh");
	*/
	system("python nova_digital.py");
	
	fp = open("position.txt", O_RDONLY);
	//fp = fopen("position.txt", "r");
	temp.numero[0] = '\0';
	i = 0;
	while(read(fp, &c, 1) != 0)
	{
		temp.numero[i] = c;
		i++;
	}
	temp.numero[i] = '\0';
	
	close(fp);
	system("rm position.txt");
	
	
	//Salva os dados do usuario no arquivo geral ".bin"
	if((arquivo = fopen("dados_usuario.bin", "ab")) == NULL)
	{
		printf("O arquivo nao pode ser aberto.");
		fclose(arquivo);
	}
	else
		fwrite(&temp, sizeof(temp), 1, arquivo);
	fclose(arquivo);
	
	//Cria a pasta do usuario
	strcpy(temporaria, temp.nome);


	//strncpy(temporaria, temporaria, strlen(temporaria)-1);
		

	for(i = 0; temporaria[i]; i++)
	{
		if(temporaria[i] == ' ')
			temporaria[i] = '_';
	}
	strcat(string, temporaria);
	system(string);
	
	//Salva os dados do usuario no arquivo ".txt"
	strcpy(temporaria2, temporaria);
	strcpy(temp.nome, temporaria2);
	
	
	strcat(temporaria2, ".txt");
	arquivo = fopen(temporaria2, "w");
	if(!arquivo)
	{
		printf("O arquivo nao pode ser aberto");
		exit(-1);
	}
	for(i = 0; temp.nome[i]; i++)
		fputc(temp.nome[i], arquivo);
	fputc('\n', arquivo);
	
	for(i = 0; temp.email[i]; i++)
		fputc(temp.email[i], arquivo);
	
	for(i = 0; temp.data_aniversario[i]; i++)
		fputc(temp.data_aniversario[i], arquivo);
	
	for(i = 0; temp.numero[i]; i++)
		fputc(temp.numero[i], arquivo);
		
	fclose(arquivo);
	
	
	
	//Salva o arquivo de dados do usuario na pasta do usuario
	strcpy(string, "mv ");
	strcat(string, temporaria2);
	strcat(string, " ");
	strcat(string, temporaria);
	system(string);	
	
	//system("move.sh");
	strcpy(string, "mv /tmp/fingerprint.bmp ~/pc3_embarcados/");
	strcat(string, temporaria);
	
	system(string);
	
	temp.nome[0] = '\0';
	temp.email[0] = '\0';
	temp.data_aniversario[0] = '\0';
	temp.numero[0] = '\0';
	
	system("./upload.sh");
}

int deletaUsuario()
{
	//Declaracoes
	FILE *arquivo, *temp_file;
	char nome[60], confirma, nome_usuario[60], comando[] = "rm -r ", deletar[] = "echo ";
	int posicao, position_cpy, i;	
	dados_usuario temp, usuario;
	
	//Instrucoes
	signal(SIGALRM, tratamento_alarme);
	
	//Pede o nome do usuario
	system("clear");
	printf("Digite o nome do usuario que sera apagado: ");
	fgets(nome, sizeof(nome), stdin);
	__fpurge(stdin);
	if(nome[strlen(nome)-1] == '\n')
		nome[strlen(nome)-1] = '\0';
		
	puts(nome);
	
	
	
	strcpy(nome_usuario, nome);
	
	for(i = 0; nome[i]; i++)
	{
		if(nome_usuario[i] == ' ')
			nome_usuario[i] = '_';
	}
	
	//Abre o arquivo
	arquivo = fopen("dados_usuario.bin", "rb");
	if(!arquivo)
		puts("O arquivo nao pode ser aberto");
	else
	{
		rewind(arquivo);
		posicao = ftell(arquivo);
		while(!feof(arquivo) && posicao == 0)
		{
			//Se o usuario existir, encontramos a posicao dele no arquivo.
			fread(&temp, sizeof(dados_usuario), 1, arquivo);
			if((strcmp(nome, temp.nome)) == 0)
				posicao = ftell(arquivo);
		}
		fclose(arquivo);
		if(!posicao)
		{
			printf("nao deveria entrar aqui se %d nao e igual a zero", posicao);
			//Senão, sai fora!
			printf("O usuario nao existe\n\n\n");
			system("sleep 2");
			system("clear");
			return 0;
		}
		else
		{
			arquivo = fopen("dados_usuario.bin", "rb");
			rewind(arquivo);
			//Administrador verifica se este usuario e o que deve ser excluido
			printf("\n\n\n\n");
			system("clear");
			fseek(arquivo, posicao-sizeof(dados_usuario), SEEK_SET);
			fread(&usuario, sizeof(dados_usuario), 1, arquivo);
			fclose(arquivo);
			
			printf("Nome: %s\n", usuario.nome);
			printf("E-mail: %s\n", usuario.email);
			printf("Data de Nascimento: %s\n", usuario.data_aniversario);
			printf("Numero: %s\n", usuario.numero);
			printf("\n\n");
			printf("Deseja mesmo excluir este usuario?\n");
			printf("Digite 'S' para sim e 'N' para nao.");
			
			scanf("%c", &confirma);
			__fpurge(stdin);
			
			
			if(toupper(confirma) == 'S')
			{
				temp_file = fopen("temp.bin", "wb");
				fclose(temp_file);
				arquivo = fopen("dados_usuario.bin", "rb");
				//Se sim, copiamos todo o arquivo, exceto o usuario a ser excluido
				while(!feof(arquivo))
				{
					fread(&temp, sizeof(dados_usuario), 1, arquivo);
					if(strcmp(nome, temp.nome) != 0)
					{
						temp_file = fopen("temp.bin", "a+b");
						if(!temp_file)
						{
							printf("O arquivo nao pode ser aberto");
							exit(1);
						}
						fwrite(&temp, sizeof(temp), 1, temp_file);
						fclose(temp_file);
					}
				}
				fclose(arquivo);
				//Remove o arquivo atual
				remove("dados_usuario.bin");
				
				//Renoemia o arquivo temporario
				rename("temp.bin", "dados_usuario.bin");
				
				//Deleta a pasta do usuario do diretório do projeto
				strcpy(nome_usuario, usuario.nome);
				for(i = 0;i < strlen(nome_usuario)-1; i++)
				{
					if(nome_usuario[i] == ' ')
						nome_usuario[i] = '_';
				}
				strcat(comando, nome_usuario);
				system(comando);
				
				arquivo = fopen("dados_usuario.bin", "rb");
				fseek(arquivo, posicao - sizeof(dados_usuario), SEEK_SET);
				fread(&temp, sizeof(dados_usuario), 1, arquivo);
				fclose(arquivo);
				
				/*
				arquivo = fopen("pipe_delete.txt", "w");
				for(i = 0; temp.numero[i]; i++)
					if(temp.numero[i] > '0' && temp.numero[i] < '9')
					{
						fputc(temp.numero[i], arquivo);
					}
				fclose(arquivo);
				*/
				puts(temp.numero);
				if(atoi(temp.numero) < 0)
				{
					system("echo 0 >> pipe_delete.txt");
				}
				else{
					strcat(deletar, temp.numero);
					strcat(deletar, " >> pipe_delete.txt");
				}
				system(deletar);
				
				system("python deleta_digital.py");
				system("rm pipe_delete.txt");
				
				system("clear");
				printf("O usuario %s foi deletado com sucesso.\n\n\n", usuario.nome);
				system("sleep 2");
				system("clear");
				
				temp.nome[0] = '\0';
				temp.email[0] = '\0';
				temp.data_aniversario[0] = '\0';
				temp.numero[0] = '\0';
				
				usuario.nome[0] = '\0';
				usuario.email[0] = '\0';
				usuario.data_aniversario[0] = '\0';
				usuario.numero[0] = '\0';
				
				return 0;
					
			}else
			{
				//Senão, sai fora!
				fclose(arquivo);
				return 0;
			}
		}
	}
}

void mostraUsuarios()
{
	FILE *fp;
	char c;
	dados_usuario temp;
	
	
	fp = fopen("dados_usuario.bin", "rb");
	while(!feof(fp))
	{
		if(!feof(fp))
		{
			fread(&temp, sizeof(dados_usuario), 1, fp);
			puts(temp.nome);
			puts(temp.email);
			puts(temp.data_aniversario);
			puts(temp.numero);
		}
	}
	fclose(fp);
	
	scanf("%c", &c);
	
}

char validaOpcao(char opcao)
{
	signal(SIGALRM, tratamento_alarme);
	while(opcao != 'M' && opcao != 'N' && opcao != 'D' && opcao != 'S')
	{
		printf("Opcao invalida, digite novamente: ");
		opcao = fgetc(stdin);
		__fpurge(stdin);
	}
	
}
