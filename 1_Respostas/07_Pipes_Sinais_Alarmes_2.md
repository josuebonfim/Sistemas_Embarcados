1. Crie um programa em C que cria um processo-filho e um pipe de comunicação. Faça com que o processo-pai envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para o processo-filho, com intervalos de 1 segundo entre cada envio. Depois de o processo-pai enviar o número 10, ele aguarda 1 segundo e termina a execução. O processo-filho escreve na tela cada valor recebido, e quando ele receber o valor 10, ele termina a execução.

```C
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define PARADA 10

int main()
{
	int pid, inteiro;
	int fd[2];
	//cria o pipe
	pipe(fd);
	//duplica os processos
	pid = fork();
	if (pid == 0)//processo filho
	{
		for (int i = 0; i < PARADA; ++i)
		{
			if(read(fd[0], &inteiro, sizeof(inteiro)) < 0)
				printf("Erro na leitura do pipe\n");
			else
				printf("%d\n", inteiro);
		}
	}
	else//processo pai
	{
		int i;
		for(i = 0; i < PARADA; i++)
		{
			inteiro = (i+1);
			if (write(fd[1], &inteiro, sizeof(inteiro)) < 0)
			{
				printf("Erro na escrita do pipe\n");
				
			}
			sleep(1);
		}

	}

	return 0;

}
```

2. Crie um programa em C que cria um processo-filho e um pipe de comunicação. Utilize o pipe para executar a seguinte conversa entre processos:

```
FILHO: Pai, qual é a verdadeira essência da sabedoria?
PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.
FILHO: Mas até uma criança de três anos sabe disso!
PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define PARADA 2

int main()
{
	int pid, inteiro, fd[2], i = 0	, ordem = 0;
	//cria o pipe
	pipe(fd);
	//duplica os processos
	pid = fork();
	if(pid == 0)
	{
		char buffer_filho[100];
		char msg_1[100] = "PAI: Nao facais nada violento, praticai somente aquilo que e justo e equilibrado";
		char msg_2[100] = "PAI: Sim, mas e uma coisa dificil de ser praticado ate mesmo por um velho como eu..."; 

		if(read(fd[0], buffer_filho, sizeof(buffer_filho)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", buffer_filho);
		if (write(fd[1], msg_1, sizeof(msg_1)) < 0)
			printf("Erro na escrita do pipe\n");
		sleep(1);
		if(read(fd[0], buffer_filho, sizeof(buffer_filho)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", buffer_filho);
		if (write(fd[1], msg_2, sizeof(msg_2)) < 0)
			printf("Erro na escrita do pipe\n");
		sleep(1);
	}
	// Codigo do pai
	else
	{
		char buffer_pai[100];
		char msg_1[100] = "FILHO: Pai, qual e a verdadeira essencia da sabedoria?";
		char msg_2[100] = "FILHO: Mas ate uma crianca de tres anos sabe disso!";

		if (write(fd[1], msg_1, sizeof(msg_1)) < 0)
			printf("Erro na escrita do pipe\n");
		sleep(1);
		if(read(fd[0], buffer_pai, sizeof(buffer_pai)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", buffer_pai);
		sleep(1);
		if (write(fd[1], msg_2, sizeof(msg_2)) < 0)
			printf("Erro na escrita do pipe\n");
		sleep(1);
		if(read(fd[0], buffer_pai, sizeof(buffer_pai)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", buffer_pai);
	}


	return 0;
}
```

Neste exercício, quem recebe a mensagem via pipe é quem as escreve no terminal.

3. Crie um programa em C que cria dois processos-filhos e um pipe de comunicação. Utilize o pipe para executar a seguinte conversa entre processos:

```
FILHO1: Quando o vento passa, é a bandeira que se move.
FILHO2: Não, é o vento que se move.
PAI: Os dois se enganam. É a mente dos senhores que se move.
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define PARADA 2

int main()
{
	int pid, inteiro, fd[2], i = 0	, ordem = 0;
	//cria o pipe
	pipe(fd);
	//duplica os processos
	pid = fork();
	if(pid == 0)
	{
		char buffer_filho[100];
		sleep(1);
		if(read(fd[0], buffer_filho, sizeof(buffer_filho)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", buffer_filho);
	}
	// Codigo do pai
	else
	{
		int pid_2;
		pid_2 = fork();
		char buffer_pai[100];
		char msg_1[100] = "FILHO1: Quando o vento passa, e a bandeira que se move";
		char msg_2[100] = "FILHO2: Nao, e o vento que se move.";

		if (pid_2 == 0)
		{
			char buffer_filho2[100];
			char msg[100] = "PAI: Os dois se enganam. E a mente dos senhores que se move.";
			if(read(fd[0], buffer_pai, sizeof(buffer_pai)) < 0) 
				printf("Erro na leitura do pipe\n");
			else
				printf("%s\n", buffer_pai);
			sleep(1);
			if (write(fd[1], msg, sizeof(msg)) < 0)
				printf("Erro na escrita do pipe\n");
		}else
		{
			if (write(fd[1], msg_1, sizeof(msg_1)) < 0)
				printf("Erro na escrita do pipe\n");
			sleep(1);
			if (write(fd[1], msg_2, sizeof(msg_2)) < 0)
				printf("Erro na escrita do pipe\n");
			sleep(1);
			if(read(fd[0], buffer_pai, sizeof(buffer_pai)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", buffer_pai);

		}
	}


	return 0;
}
```

Neste exercício, quem recebe a mensagem via pipe é quem as escreve no terminal.

4. Crie um programa em C que cria um processo-filho e um pipe de comunicação. O processo-filho deverá pedir o nome do usuário, envia-lo para o pai via pipe, e o pai deverá escrever o nome do usuário no terminal.

```C
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define PARADA 2

int main()
{
	int pid, inteiro, fd[2], i = 0	, ordem = 0;
	//cria o pipe
	pipe(fd);
	//duplica os processos
	pid = fork();
	if(pid == 0)
	{
		char nome[100];
		printf("Digite seu nome: ");
		gets(nome);
		ordem = 1;
		if (write(fd[1], &ordem, sizeof(ordem)) < 0)
			printf("Erro na escrita do pipe\n");
		if (write(fd[1], nome, sizeof(nome))< 0)
			printf("Erro na escrita do pipe\n");
		
		
	}
	// Codigo do pai
	else
	{
		char buffer_pai[100];
		if(read(fd[0], &ordem, sizeof(ordem)) < 0)
			printf("Erro na escrita do pipe\n");
		if(ordem)
		{
			if(read(fd[0], buffer_pai, sizeof(buffer_pai)) < 0)
				printf("Erro na leitura do pipe\n");
			printf("Seu nome: %s\n", buffer_pai);
		}


	}

	return 0;
}
```

5. Utilize o sinal de alarme para chamar a cada segundo o comando `ps` ordenando todos os processos de acordo com o uso da CPU. Ou seja, seu código atualizará a lista de processos a cada segundo. Além disso, o código deverá tratar o sinal do CTRL-C, escrevendo "Processo terminado!" na tela antes de terminar a execução do processo.
