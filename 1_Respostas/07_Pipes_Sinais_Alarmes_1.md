1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```

> Neste formato, é criado um pipe, que, depois do fork() é duplicado e os dois processos, pai e filho, podem acessá-lo.

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```

> Neste formato, apenas o processo pai pode acessar o pipe, uma vez que o mesmo foi criado após a utilização do fork().

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?

>* **SIGKILL** - Mata os processos. Não pode ser ignorada, tampouco interceptada

>* **SIGILL** - Instrução Ilegal: emitido quando uma instrução ilegal é detectada

>* **SIGHUP** - Corte: sinal emitido aos processos associados a um terminal quando este se "desconecta". Este sinal també é emitido a cada processo de um grupo quando o chege termina sua execução.

>* **SIGQUIT** - Abandono: sinal emitido aos processos do terminal quando com a tecla de abandono(QUIT ou CRTL+d) do teclado são acionadas.

>* **SIGIOT** - Problemas de instrução de E/S: emitido em caso de problemas de hardware.

3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?

> Dependendo da aplicação, a contagem de 1s é dada por 1001ms. Para aplicações em tempo real essa contagem é imprecisa, gerando erros de temporização.