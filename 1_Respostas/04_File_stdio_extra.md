1. Crie um código em C que escreve a sequência de Fibonacci em arquivo em formato binário. Comece a sequência com os valores 0 e 1, e grave suas primeiras 100 posições em arquivo.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *arquivo;
	int i;
	long int fibonacci[102];

	if ((arquivo = fopen("fibonacci.bin", "wb")) == 0)
		printf("nao foi possivel abrir o arquivo\n");

	fibonacci[0] = 0;
	if(fwrite(&fibonacci[0], sizeof(fibonacci[0]), 1, arquivo) != 1)
		printf("nao foi possivel gravar no arquivo\n");

	fibonacci[1] = 1;
	if(fwrite(&fibonacci[1], sizeof(fibonacci[1]), 1, arquivo) != 1)
		printf("nao foi possivel gravar no arquivo\n");


	for(i = 2; i < 102; i++)
	{
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
		if(fwrite(&fibonacci[i], sizeof(fibonacci[i]), 1, arquivo) != 1)
			printf("nao foi possivel gravar no arquivo\n");
	}	
	fclose(arquivo);
	return 0;
}
```

2. Crie um código em C que lê o arquivo da questão anterior e escreve os valores lidos da sequência de Fibonacci na tela.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARADA 102

int main(int argc, char const *argv[])
{
	FILE *arquivo;
	int i;	
	long int buffer;

	if ((arquivo = fopen("fibonacci.bin", "rb")) == 0)
		printf("nao foi possivel abrir o arquivo\n");

	
	while(!feof(arquivo))
	{
		if (fread(&buffer, sizeof(long int), 1, arquivo) != 1)
			printf("nao foi possivel ler o arquivo\n");
		if(!feof(arquivo))
			printf("%ld\n", buffer);
	}




	fclose(arquivo);
	
}
```
