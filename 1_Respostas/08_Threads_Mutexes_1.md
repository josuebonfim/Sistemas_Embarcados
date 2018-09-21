1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?

> Com a função `fork()`, pode se criar uma cópia exata do processo, levando consigo todas a variáveis e chamadas de funções realizadas anteriormente ao comando `fork()`. Isso faz com que mais memória seja ocupada no processo.

(b) threads?

> Com a thread, podemos colocar o programa para executar várias tarefas enquanto o programa principal ainda está sendo executado.

2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)

```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

> 3 threads, a thread principal, a thread t1 e a threadt2. Coexitirão todas as 3. 

(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

> 3 threads, a thread principal, a thread t1 e a threadt2. Coexistirão, num primeiro momento a principal e t1. Quando a thread t1 for destruída, então será criada a thread t2, coexistindo com a thread principal. 

3. Apresente as características e utilidades das seguintes funções:

(a) `pthread_setcancelstate()`

```C
//chamada
int pthread_setcancelstate(int state, int *oldstate);
```

> A função pthread_setcancelstate() habilita o estado de cancelabilidade da thread para um dado valor no parâmeto state .O estado de cancelabilidade anterior da thread é retornado no buffer de estado anterior, ou seja, no ponteiro `*oldstate`. 

(b) `pthread_setcanceltype()`

```C
//chamada
int pthread_setcanceltype(int type, int *oldtype);
```

> A função pthread_setcanceltype() habilita o tipo de cancelabilidade da thread para um dado valor no parâmeto state .O tipo de cancelabilidade anterior da thread é retornado no buffer de tipo anterior, ou seja, no ponteiro `*oldtype`.

(DICA: elas são relacionadas à função pthread_cancel().)
