1. Por que o Linux recebeu esse nome?

  >Porque foi criado por Linus Torvalds e é a junção do nome "Linus" com o nome do sistema operacional "UNIX", formando então o Linux. 

2. O que são daemons?
  
  >São programas de computador que executam como um processo em plano de fundo, em vez de estar sob o controle direto de um usuário interativo. Ou seja, são programas que executam automaticamente para o bom funcionamento do sistema operacional e que são controlados diretamente pelo usuário.

3. O que é o shell?

  >É uma interface de usuário onde o mesmo tem acesso às ferramentas do sistema operacional. Para o caso do linux, o shell é cohecido como bash ou terminal. 

4. Por que é importante evitar executar o terminal como super-usuário?
  
  >Porque o super-usuário permite que ferramentas que não estão disponíveis para os demais usuários possam ser acessadas. Uma vez que o usuário entra nesse modo, ele pode realizar tarefas que um usuário normal não conseguiria. Isso pode acarretar em possíveis mudanças acidentais ou não e que podem ou não ser reversíveis. 

5. Qual botão do teclado completa o que o usuário escreve no terminal, de acordo com o contexto?

  >TAB.

6. Quais botões do teclado apresentam instruções escritas anteriormente?

  >Pressionando a tecla UP. Para pesquisar um comando digitado executado anteriormente, deve-se pressionar "ctrl+r" ou "ctrl+s" e digitar o começo do comando para pesquisar.

7. Apresente os respectivos comandos no terminal para: <br/>
  (a) Obter mais informações sobre um comando.
    ```bash
    $ man comando
    ```
    ou 
    ```bash
    $ comando --help
    ```

  (b) Apresentar uma lista com os arquivos dentro de uma pasta.
    
```bash
    $ comando --help
```

  (c) Apresentar o caminho completo da pasta.
```bash
    $ pwd
```
  (d) Trocar de pasta.
   
```bash
    $ cd [caminho da pasta]
```

  (e) Criar uma pasta.

```bash
    $ mkdir [nome da pasta]
```

  (f) Apagar arquivos definitivamente.
```bash
    $ rm [nome do arquivo]
```

  (g) Apagar pastas definitivamente.
    
```bash
    $ rm [caminho da pasta]
```

  (h) Copiar arquivos.
    
```bash
    $ cp [origem do arquivo] [destino do arquivo]
```

  (i) Copiar pastas.
    
```bash
    $ cp -r [origem da pasta] [destino da pasta]
```

  (j) Mover arquivos.
    
```bash
    $ mv [origem do arquivo] [destino do arquivo]
```

  (k) Mover pastas.
    
```bash
    $ mv -t [origem da pasta] [destino da pasta]
```

  (l) Renomear pastas.


  (m) Apresentar o conteúdo de um arquivo.
    
```bash
    $ cat [nome_do_arquivo]
```

  (n) Apresentar o tipo de um arquivo.
```bash
    $  [origem] [destino]
```

  (o) Limpar a tela do terminal.
```bash
    $ clear
```

  (p) Encontrar ocorrências de palavras-chave em um arquivo-texto.
```bash
    $ grep -c palavra-chave arquivo.extensão
```  

  (q) Ordenar informações em um arquivo-texto.


  (r) Substituir ocorrências de palavras-chave em um arquivo-texto.
```bash
    $ sed -e palavra-chave arquivo.extensão
```

  (s) Conferir se dois arquivos são iguais.
```bash
	$ diff arquivo1 arquivo 2
```


  (t) Escrever algo na tela.
```bash
	$ echo texto
```


