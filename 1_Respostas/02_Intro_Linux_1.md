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
  (b) Apresentar uma lista com os arquivos dentro de uma pasta.<br/>
  
    ```bash
    $ ls
    ```
    
  (c) Apresentar o caminho completo da pasta.<br/>
  
    ```bash
    $ pwd
    ``` 
   <br/>
  (d) Trocar de pasta.<br/>
  
    ```bash
    $ cd [caminho da pasta]
    ```
   <br/>
    
  (e) Criar uma pasta.<br/>
    ```bash
    $ mkdir [nome da pasta]
    ```
   <br/>
  (f) Apagar arquivos definitivamente.<br/>
    ```bash
    $ rm [nome do arquivo]
    ```<br/>
  (g) Apagar pastas definitivamente.<br/>
    ```bash
    $ rm [caminho da pasta]
    ```
    <br/>
  (h) Copiar arquivos.<br/>
    ```bash
    $ cp [origem do arquivo] [destino do arquivo]
    ```
    <br/>
  (i) Copiar pastas.<br/>
    ```bash
    $ cp -r [origem da pasta] [destino da pasta]
    ```
    <br/>
  (j) Mover arquivos.<br/>
    ```bash
    $ mv [origem do arquivo] [destino do arquivo]
    ```
    <br/>
  (k) Mover pastas.<br/>
    ```bash
    $ mv -t [origem da pasta] [destino da pasta]
    ```
    <br/>
  (l) Renomear pastas.<br/>


  (m) Apresentar o conteúdo de um arquivo.<br/>
    ```bash
    $ cat [nome_do_arquivo]
    ```
    <br/>
  (n) Apresentar o tipo de um arquivo.<br/>
    ```bash
    $  [origem] [destino]
    ```
    <br/>
  (o) Limpar a tela do terminal.<br/>
    ```bash
    $ clear
    ```
    <br/>
  (p) Encontrar ocorrências de palavras-chave em um arquivo-texto.<br/>
    ```bash
    $ grep -c palavra-chave arquivo.extensão
    ``` 
    <br/>
  (q) Ordenar informações em um arquivo-texto.<br/>

<br/>
  (r) Substituir ocorrências de palavras-chave em um arquivo-texto.<br/>
	```bash
	$ sed -e palavra-chave arquivo.extensão
	```
	<br/>
	
  (s) Conferir se dois arquivos são iguais.
	```bash
	$ diff arquivo1 arquivo 2
    	```
	<br/>

  (t) Escrever algo na tela.
  <br/>
  <br/>


