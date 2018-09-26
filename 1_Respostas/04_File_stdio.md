Para todas as questões, utilize as funções da biblioteca `stdio.h` de leitura e de escrita em arquivo (`fopen()`, `fclose()`, `fwrite()`, `fread()`, dentre outras). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *arquivo;
	char frase[50] = "Ola mundo!\n";

	if ((arquivo = fopen("ola_mundo.txt", "wb")) == 0)
	{
		printf("nao foi possivel abrir o arquivo\n");
	}

	if(fwrite(frase, sizeof(frase), 1, arquivo) != 1)
		printf("nao foi possivel gravar no arquivo\n");
	fclose(arquivo);

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
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *arquivo;
	char nome[20], idade[30], nome_s[40] = "Nome: ", idade_s[40] = "Idade: ";

		printf("Digite o seu nome: ");
	scanf("%s", nome);
	printf("Digite a sua idade: ");
	scanf("%s", idade);

	strcat(nome_s, nome);
	strcat(nome_s, "\n");
	strcat(idade_s, idade);
	strcat(idade_s, "\n");

	if ((arquivo = fopen("ola_usuario_1.txt", "wb")) == 0)
		printf("nao foi possivel abrir o arquivo\n");

	if(fwrite(nome_s, sizeof(nome_s), 1, arquivo) != 1)
		printf("nao foi possivel gravar no arquivo\n");

	if(fwrite(idade_s, sizeof(idade_s), 1, arquivo) != 1)
		printf("nao foi possivel gravar no arquivo\n");

	fclose(arquivo);
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
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *arquivo;
	char nome_s[40] = "Nome: ", idade_s[40] = "Idade: ";


	strcat(nome_s, argv[1]);
	strcat(nome_s, "\n");
	strcat(idade_s, argv[2]);
	strcat(idade_s, "\n");

	if ((arquivo = fopen("ola_usuario_2.txt", "wb")) == 0)
		printf("nao foi possivel abrir o arquivo\n");

	if(fwrite(nome_s, sizeof(nome_s), 1, arquivo) != 1)
		printf("nao foi possivel gravar no arquivo\n");

	if(fwrite(idade_s, sizeof(idade_s), 1, arquivo) != 1)
		printf("nao foi possivel gravar no arquivo\n");

	fclose(arquivo);
	return 0;
}
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

```C
#include <stdlib.h>
#include <stdio.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo)
{
	FILE *arquivo;
	int tamanho = 0;
	char c;

	if ((arquivo = fopen(nome_arquivo, "rb")) == 0)
		printf("Não foi possivel abrir o arquivo\n");

	while((c = getc(arquivo)) != EOF)
		tamanho += sizeof(c);

	fclose(arquivo);

	return tamanho;
}
```

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `void le_arq_texto(char *nome_arquivo, char *conteudo);` Repare que o conteúdo do arquivo é armazenado no vetor `conteudo[]`. Ou seja, ele é passado por referência. Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *arquivo;
	int i;
	char string[50];

	if ((arquivo = fopen("ola_usuario_2.txt", "w")) == 0)
		printf("nao foi possivel abrir o arquivo\n");

	strcpy(string, "Nome: ");

	for(i = 0; string[i]; i++)
		fputc(string[i], arquivo);

	strcpy(string, argv[1]);

	for(i = 0; string[i]; i++)
		fputc(string[i], arquivo);

	strcpy(string, "\n");

	for(i = 0; string[i]; i++)
		fputc(string[i], arquivo);

	strcpy(string, "Idade: ");

	for(i = 0; string[i]; i++)
		fputc(string[i], arquivo);

	strcpy(string, argv[2]);

	for(i = 0; string[i]; i++)
		fputc(string[i], arquivo);

	strcpy(string, "\n");

	for(i = 0; string[i]; i++)
		fputc(string[i], arquivo);

	fclose(arquivo);
	return 0;
}
```

6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int tam_arq_texto(char *nome_arquivo);

int main(int argc, char const *argv[])
{
	char nome[30] = "ola_usuario_2.txt", conteudo[1000];
	int tamanho;

	tamanho = tam_arq_texto(nome);
	le_arq_texto(nome, conteudo);

	printf("%s\n", conteudo);

	return 0;
}
```

7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
