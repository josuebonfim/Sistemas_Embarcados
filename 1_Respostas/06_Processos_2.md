1. Crie um código em C para gerar três processos-filho usando o `fork()`.

```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	pid_t child_pid_1, child_pid_2, child_pid_3;
	
	
	child_pid_1 = fork(); //criando o processo filho #1
	if (child_pid_1 == 0)
	{
		printf("Este e o processo filho #1, com pid = %d\n", (int) getpid());
		
	}
	else
	{
		sleep(1);
		child_pid_2 = fork(); //criando o processo filho #2
		if (child_pid_2 == 0)
		{
			printf("Este e o processo filho #2, com pid = %d\n", (int) getpid());
			
		}
		else
		{
			sleep(1);
			child_pid_3 = fork(); //criando o processo filho #3
			if (child_pid_3 == 0)
			{
				printf("Este e o processo filho #3, com pid = %d\n", (int) getpid());
				
			}	
		}
	}
	
	return 0;
}
```

2. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um sequencialmente usando `system()`. Por exemplo, considerando que o código criado recebeu o nome de 'serial_system', e que ele foi executado na pasta '/Sistemas_Embarcados/Code/06_Processos', que contem diversos arquivos:

```bash
$ ./serial_system pwd echo ls echo cal
$ ~/Sistemas_Embarcados/Code/06_Processos
$
$ Ex1.c    Ex2b.c   Ex4.c   Ex6.c
$ Ex2a.c   Ex3.c    Ex5.c   serial_system
$
$     Março 2017
$ Do Se Te Qu Qu Se Sá
$           1  2  3  4
$  5  6  7  8  9 10 11
$ 12 13 14 15 16 17 18
$ 19 20 21 22 23 24 25
$ 26 27 28 29 30 31
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, const char *argv[])
{
	int a, i;
	char *comando;

	for(i = 1; i < argc; i++)
	{
		a = system(argv[i]);
	}
	
	return 0;
}
```

3. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um usando `fork()` e `exec()`.

4. Crie um código em C que gera três processos-filho usando o `fork()`, e que cada processo-filho chama a seguinte função uma vez:

```C
int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual);

int main (int argc, const char *argv[])
{
	int a, i;
	char *comando[] = {"ls", NULL};
	pid_t pid_filho_1, pid_filho_2, pid_filho_3;

	pid_filho_1 = fork();

	if (pid_filho_1 == 0)
		Incrementa_Variavel_Global((int) getpid());
	else
	{
		pid_filho_2 = fork();
		if (pid_filho_2 == 0)
			Incrementa_Variavel_Global((int) getpid()); 
		else
		{
			pid_filho_3 = fork();
			if (pid_filho_3 == 0)
				Incrementa_Variavel_Global((int) getpid());
		}
	}
	return 0;
}

void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```

(Repare que a função `Incrementa_Variavel_Global()` recebe como entrada o ID do processo que a chamou.) Responda: a variável global `v_global` foi compartilhada por todos os processos-filho, ou cada processo enxergou um valor diferente para esta variável?

> Cada processo enxerga a váriável com um valor diferente.

5. Repita a questão anterior, mas desta vez faça com que o processo-pai também chame a função `Incrementa_Variavel_Global()`. Responda: a variável global `v_global` foi compartilhada por todos os processos-filho e o processo-pai, ou cada processo enxergou um valor diferente para esta variável?

```C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual);

int main (int argc, const char *argv[])
{
	int a, i;
	char *comando[] = {"ls", NULL};
	pid_t pid_filho_1, pid_filho_2, pid_filho_3;

	Incrementa_Variavel_Global((int) getpid()); 
	pid_filho_1 = fork();

	if (pid_filho_1 == 0)
	{
		Incrementa_Variavel_Global((int) getpid()); 
	}
	else
	{
		Incrementa_Variavel_Global((int) getpid());
		pid_filho_2 = fork(); 
		if (pid_filho_2 == 0)
		{
			Incrementa_Variavel_Global((int) getpid()); 
		}
		else
		{
			Incrementa_Variavel_Global((int) getpid());
			pid_filho_3 = fork();
			if (pid_filho_3 == 0)
			{
				Incrementa_Variavel_Global((int) getpid()); 
			}
		}
	}
	return 0;
}

void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}



```

> A variável global foi compartilhada entre os processos-pai e processos-filho.