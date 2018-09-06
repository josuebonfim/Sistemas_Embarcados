Para todas as questões, utilize as funções da norma POSIX (`open()`, `close()`, `write()`, `read()` e `lseek()`). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	int fp, i;
	char string[100] = "Ola mundo!";

	fp = open ("ola_mundo.txt", O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	
	write(fp, "\n", 1);
	close(fp);

	return 0;
}
```

2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
	int fp, i;
	char string[20];


	fp = open ("ola_usuario_10.txt", O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}

	strcpy(string, "Nome: ");

	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	

	printf("Digite o seu nome: ");
	gets(string);
	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	
	write(fp, "\n", 1);



	strcpy(string, "Idade: ");

	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	


	printf("Digite a sua idade: ");
	gets(string);
	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	
	write(fp, " ", 1);

	strcpy(string, "anos");

	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	



	write(fp, "\n", 1);


	close(fp);

	return 0;
}
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
	int fp, i;
	char string[20];


	fp = open ("ola_usuario_2.txt", O_WRONLY | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}

	strcpy(string, "Nome: ");

	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	

	strcpy(string, argv[1]);
	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	
	write(fp, "\n", 1);



	strcpy(string, "Idade: ");

	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	


	strcpy(string, argv[2]);
	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	
	write(fp, " ", 1);

	strcpy(string, "anos");

	for(i=0; string[i]; i++)
		write(fp, &(string[i]), 1); // Grava a string, caractere a caractere	



	write(fp, "\n", 1);


	close(fp);

	return 0;
}
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

```C
//bib_arqs.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
	char c;
	int i = 0, fp;

	fp = open (nome_arquivo, O_RDONLY);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	while(read(fp, &c, 1) != 0)
		i++;
	close(fp);

	return i;
}

//bib_arqs.h
int tam_arq_texto(char *nome_arquivo);
```

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `void le_arq_texto(char *nome_arquivo, char *conteúdo);` Repare que o conteúdo do arquivo é armazenado no vetor `conteudo[]`. Ou seja, ele é passado por referência. Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

```C
//bib_arqs.c

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
	char c;
	int i = 0, fp;

	fp = open (nome_arquivo, O_RDONLY);
	if(fp==-1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}
	while(read(fp, &c, 1) != 0)
		i++;
	close(fp);

	return i;
}

char* le_arq_texto(char *nome_arquivo)
{
	int fp, i = 0;
	char *string, c;

	string = (char*)malloc(tam_arq_texto(nome_arquivo)*sizeof(char));

	fp = open(nome_arquivo, O_RDONLY);
	if (fp == -1)
	{
		printf ("Erro na abertura do arquivo.\n");
		exit (1);
	}

	while(read(fp, &c, 1) != 0)
	{
		string[i] = c;
		i++;	
	}

	close(fp);

	return string;
}

//bib_arqs.h
int tam_arq_texto(char *nome_arquivo);
char* le_arq_texto(char *nome_arquivo);
```

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
	int fp, tamanho;
	char c;

	fp = open(argv[1], O_RDONLY);
	if (fp == -1)
	{
		printf("Erro na abertura do arquivo.\n");
	}

	while(read(fp, &c, 1) != 0)
		printf("%c", c);
	return 0;
}
```

7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```

```C
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int main(int argc, const char * argv[])
{
	int fp, tamanho, i, ocorrencia = 0;
	char *conteudo, *palavra;

	tamanho = tam_arq_texto((char*)argv[2]);

	conteudo = (char*)malloc(tamanho*sizeof(char));

	conteudo = le_arq_texto((char*)argv[2]);

	printf("%s\n", conteudo);

	for (i = 0; i < tamanho*sizeof(char); i++)
	{
		if (conteudo[i] == 'O')
		{
			if (conteudo[i+1] == 'l')
			{
				if (conteudo[i+2] == 'a')
				{
					ocorrencia++;
				}
			}
		}
	}

	printf("'%s' ocorre %d vezes no arquivo '%s'\n", argv[1], ocorrencia, argv[2]);

	return 0;
}
```
