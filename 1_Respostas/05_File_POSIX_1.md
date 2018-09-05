1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

```C
FILE *fopen (char *nome_do_arquivo, char *modo) //abrir
int fclose(FILE *ponteiro_para_arquivo) //fechar
```

(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

```C
void fputc (int caractere, FILE *fluxo);
void fputs (char *string, FILE *fluxo);
void fprintf (FILE *fluxo, char *formatação, ...);
int fwrite (void *dados, int tamanho_do_elemento, int num_elementos, FILE *fluxo);
```

(c) Quais são as funções (e seus protótipos) para ler arquivos?

```C
int fgetc (FILE *fluxo);
void fgets (char *string, int tamanho, FILE *fluxo);
void fscanf (FILE *fluxo, char *formatação, ...);
int fread (void *dados, int tamanho_do_elemento, int num_elementos, FILE *fluxo);
```

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

```C
int fseek ( FILE * stream, long int offset, int origin );
int rewind (FILE * stream);
```

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

```C
#include <stdio.h>
#include <stdlib.h>
```

2. O que é a norma POSIX?

> POSIX (um acrônimo para: Portable Operating System Interface, que pode ser traduzido como Interface Portável entre Sistemas Operacionais) é uma família de normas definidas pelo IEEE para a manutenção de compatibilidade entre sistemas operacionais, e designada formalmente por IEEE 1003. POSIX define a interface de programação de aplicações (API), juntamente com shells de linha e comando e interfaces utilitárias, para compatibilidade de software com variantes de Unix e outros sistemas operacionais.

3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

```C
int open(const char* path, int oflag, …) //abrir
int close(int fildes) //fechar
```

(c) Quais são as funções (e seus protótipos) para ler arquivos?

```C
ssize_t read(int fildes, void *buf, size_t nbyte);
```

(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

```C
off_t lseek(int fd, off_t offset, int whence);
```

(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

```C
#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()
```
