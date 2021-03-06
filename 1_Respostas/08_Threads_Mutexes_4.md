1. Crie um programa em C que preenche matrizes `long int A[60][60]` e `long int B[60][60]` completamente com valores aleatórios (use a função `random()`), e que calcula a soma das duas matrizes por dois métodos:

(a) De forma sequencial;

(b) De forma paralela.

Ao final do programa principal, compare os resultados obtidos pelos dois métodos.

```C
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define PARADA 60	
 
struct matriz
{
	long int A[PARADA][PARADA];
	long int B[PARADA][PARADA];
	long int soma_parcial_1[15][PARADA];
	long int soma_parcial_2[15][PARADA];
	long int soma_parcial_3[15][PARADA];
	long int soma_parcial_4[15][PARADA];
};

void* soma_por_thread_1 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < PARADA/4; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_1[i][j] = temp->A[i][j] + temp->B[i][j];
	}
	return NULL;
}

void* soma_por_thread_2 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_2[i][j] = temp->A[15 + i][j] + temp->B[15 + i][j];
	}
	return NULL;
}

void* soma_por_thread_3 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_3[i][j] = temp->A[30 + i][j] + temp->B[30 + i][j];
	}
	return NULL;
}

void* soma_por_thread_4 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_4[i][j] = temp->A[45 + i][j] + temp->B[45 + i][j];
	}
	return NULL;
}


int main ()
{
	int i, j; 
	pthread_t thread_id1;
	pthread_t thread_id2;
	pthread_t thread_id3;
	pthread_t thread_id4;
	struct matriz random_matriz;
	long int soma[60][60], soma_parcial[60][60];

	for(i = 0; i < PARADA; i++)
	{
		for(j = 0; j < PARADA; j++)
		{
			random_matriz.A[i][j] = rand();
			random_matriz.B[i][j] = rand();
		}
	}

	pthread_create (&thread_id1, NULL, &soma_por_thread_1, &random_matriz);
	pthread_create (&thread_id2, NULL, &soma_por_thread_2, &random_matriz);
	pthread_create (&thread_id3, NULL, &soma_por_thread_3, &random_matriz);
	pthread_create (&thread_id4, NULL, &soma_por_thread_4, &random_matriz);

	for(i = 0; i < PARADA; i++)
	{
		for(j = 0; j < PARADA; j++)
			soma[i][j] = random_matriz.A[i][j] + random_matriz.B[i][j];
	}

	pthread_join (thread_id1, NULL);
	pthread_join (thread_id2, NULL);
	pthread_join (thread_id3, NULL);
	pthread_join (thread_id4, NULL);


	for (i = 0; i < 15; i++)
	{
		for(j = 0; j < 60; j++)
		{
			soma_parcial[0  + i][j] = random_matriz.soma_parcial_1[i][j];
			soma_parcial[15 + i][j] = random_matriz.soma_parcial_2[i][j];
			soma_parcial[30 + i][j] = random_matriz.soma_parcial_3[i][j];
			soma_parcial[45 + i][j] = random_matriz.soma_parcial_4[i][j];
		}
	}

	printf("\nsoma sequencial\n");
	for(i = 0; i < 60; i++)
	{
		for(j = 0; j < 60; j++)
			printf("%ld ", soma[i][j]);
		printf("\n");
	}

	printf("\nsoma paralela\n ");

	for(i = 0; i < 60; i++)
	{
		for(j = 0; j < 60; j++)
			printf("%ld ", soma_parcial[i][j]);
		printf("\n");
	}



	return 0;
}
```

> Deu certo!!

2. Repita o exercício anterior, mas calcule o produto matricial `A*B`.

```C
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define PARADA 60	
 
struct matriz
{
	long int A[PARADA][PARADA];
	long int B[PARADA][PARADA];
	long int soma_parcial_1[15][PARADA];
	long int soma_parcial_2[15][PARADA];
	long int soma_parcial_3[15][PARADA];
	long int soma_parcial_4[15][PARADA];
};

void* soma_por_thread_1 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < PARADA/4; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_1[i][j] = temp->A[i][j] + temp->B[i][j];
	}
	return NULL;
}

void* soma_por_thread_2 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_2[i][j] = temp->A[15 + i][j] + temp->B[15 + i][j];
	}
	return NULL;
}

void* soma_por_thread_3 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_3[i][j] = temp->A[30 + i][j] + temp->B[30 + i][j];
	}
	return NULL;
}

void* soma_por_thread_4 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_4[i][j] = temp->A[45 + i][j] + temp->B[45 + i][j];
	}
	return NULL;
}


int main ()
{
	int i, j; 
	pthread_t thread_id1;
	pthread_t thread_id2;
	pthread_t thread_id3;
	pthread_t thread_id4;
	struct matriz random_matriz;
	long int soma[60][60], soma_parcial[60][60];

	for(i = 0; i < PARADA; i++)
	{
		for(j = 0; j < PARADA; j++)
		{
			random_matriz.A[i][j] = rand();
			random_matriz.B[i][j] = rand();
		}
	}

	pthread_create (&thread_id1, NULL, &soma_por_thread_1, &random_matriz);
	pthread_create (&thread_id2, NULL, &soma_por_thread_2, &random_matriz);
	pthread_create (&thread_id3, NULL, &soma_por_thread_3, &random_matriz);
	pthread_create (&thread_id4, NULL, &soma_por_thread_4, &random_matriz);

	for(i = 0; i < PARADA; i++)
	{
		for(j = 0; j < PARADA; j++)
			soma[i][j] = random_matriz.A[i][j] + random_matriz.B[i][j];
	}

	pthread_join (thread_id1, NULL);
	pthread_join (thread_id2, NULL);
	pthread_join (thread_id3, NULL);
	pthread_join (thread_id4, NULL);


	for (i = 0; i < 15; i++)
	{
		for(j = 0; j < 60; j++)
		{
			soma_parcial[0  + i][j] = random_matriz.soma_parcial_1[i][j];
			soma_parcial[15 + i][j] = random_matriz.soma_parcial_2[i][j];
			soma_parcial[30 + i][j] = random_matriz.soma_parcial_3[i][j];
			soma_parcial[45 + i][j] = random_matriz.soma_parcial_4[i][j];
		}
	}

	printf("\nsoma sequencial\n");
	for(i = 0; i < 60; i++)
	{
		for(j = 0; j < 60; j++)
			printf("%ld ", soma[i][j]);
		printf("\n");
	}

	printf("\nsoma paralela\n ");

	for(i = 0; i < 60; i++)
	{
		for(j = 0; j < 60; j++)
			printf("%ld ", soma_parcial[i][j]);
		printf("\n");
	}

	return 0;
}
```

3. Repita o exercício anterior, mas calcule o produto da matriz `long int A[60][60]` por um escalar `long int x`.

```C
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define PARADA 60	
 
struct matriz
{
	long int A[PARADA][PARADA];
	long int B[PARADA][PARADA];
	long int soma_parcial_1[15][PARADA];
	long int soma_parcial_2[15][PARADA];
	long int soma_parcial_3[15][PARADA];
	long int soma_parcial_4[15][PARADA];
	long int x;
};

void* soma_por_thread_1 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < PARADA/4; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_1[i][j] = temp->A[i][j] * temp->x;
	}
	return NULL;
}

void* soma_por_thread_2 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_2[i][j] = temp->A[15 + i][j] * temp->x;
	}
	return NULL;
}

void* soma_por_thread_3 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_3[i][j] = temp->A[30 + i][j] * temp->x;
	}
	return NULL;
}

void* soma_por_thread_4 (void *vetor)
{
	struct matriz* temp = (struct matriz *) vetor;
	int i, j;

	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < PARADA; j++)
			temp->soma_parcial_4[i][j] = temp->A[45 + i][j] * temp->x;
	}
	return NULL;
}


int main ()
{
	int i, j; 
	pthread_t thread_id1;
	pthread_t thread_id2;
	pthread_t thread_id3;
	pthread_t thread_id4;
	struct matriz random_matriz;
	long int soma[60][60], soma_parcial[60][60];

	for(i = 0; i < PARADA; i++)
	{
		for(j = 0; j < PARADA; j++)
		{
			random_matriz.A[i][j] = rand();
			random_matriz.B[i][j] = rand();
		}
	}

	random_matriz.x = rand();

	pthread_create (&thread_id1, NULL, &soma_por_thread_1, &random_matriz);
	pthread_create (&thread_id2, NULL, &soma_por_thread_2, &random_matriz);
	pthread_create (&thread_id3, NULL, &soma_por_thread_3, &random_matriz);
	pthread_create (&thread_id4, NULL, &soma_por_thread_4, &random_matriz);

	for(i = 0; i < PARADA; i++)
	{
		for(j = 0; j < PARADA; j++)
			soma[i][j] = random_matriz.A[i][j] * random_matriz.x;
	}

	pthread_join (thread_id1, NULL);
	pthread_join (thread_id2, NULL);
	pthread_join (thread_id3, NULL);
	pthread_join (thread_id4, NULL);


	for (i = 0; i < 15; i++)
	{
		for(j = 0; j < 60; j++)
		{
			soma_parcial[0  + i][j] = random_matriz.soma_parcial_1[i][j];
			soma_parcial[15 + i][j] = random_matriz.soma_parcial_2[i][j];
			soma_parcial[30 + i][j] = random_matriz.soma_parcial_3[i][j];
			soma_parcial[45 + i][j] = random_matriz.soma_parcial_4[i][j];
		}
	}

	printf("\nsoma sequencial\n");
	for(i = 0; i < 60; i++)
	{
		for(j = 0; j < 60; j++)
			printf("%ld ", soma[i][j]);
		printf("\n");
	}

	printf("\nsoma paralela\n ");

	for(i = 0; i < 60; i++)
	{
		for(j = 0; j < 60; j++)
			printf("%ld ", soma_parcial[i][j]);
		printf("\n");
	}

	return 0;
}
```
