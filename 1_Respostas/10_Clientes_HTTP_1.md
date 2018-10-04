1. Especifique algumas portas importantes pré-definidas para o protocolo TCP/IP.

* Porta 21 - FTP
* Porta 23 - Telnet
* Porta 25 - SMTP
* Porta 53 - Domain Name(Nome do domínio do sistema)
* Porta 63 - Whois
* Porta 70 - Gophher
* Porta 79 - Finger
* Porta 80 - HTTP
* Porta 110 - POP3
* Porta 119 - NNTP

2. Com relação a endereços IP, responda:

(a) Qual é a diferença entre endereços IP externos e locais?

> O IP local é usado para identificar um dispositivo conectado à uma rede local. O IP externo é usado para identificar um dispositivo conectado à internet.

(b) Como endereços IP externos são definidos? Quem os define?

> 

(c) Como endereços IP locais são definidos? Quem os define?

> 

(d) O que é o DNS? Para que ele serve?

> É um sistema para getencar os nomes hierárquico e distribuído para computadores e outras plataformas de acesso à internet. Ele vai funcionar para qualquer tipo de serviço que necessite da internet para funcionar. Seu trabalho é traduzir para os números de IP todo e qualquer site que procuramos. 

3. Com relação à pilha de protocolos TCP/IP, responda:

(a) O que são suas camadas? Para que servem?

> São os conjuntos de protocolos, onde cada camada é responsável por um grupo de tarefas, fornecendo um conjunto de serviços bem defnidos para o protocolo de camada superior.

(b) Quais são as camadas existentes? Para que servem?

São: 

* Camada de aplicação, onde encontramos os protolocos SMTP (usado para e-mail), FTP(para transferẽncia de arquivos), HTTP(para navegar na internet), etc; 

* Camada de transporte, onde esta é responsável por pegar o dado enviado pela camada de aplicação e transportá-lo para as camadas inferiores; 

* Camada da Internet, onde temos o protocolo IP que pega os dados recebidos da camada de Transporte e adiciona uma informação de endereço virtual; 

* Camada de Interface de Rede. responsáveis por enviar os dados das camadas superiores pela rede.

(c) Quais camadas são utilizadas pela biblioteca de sockets?

> Utilizam a camade de transporte. aplicação. ip e de rede, onde este faz a interface entre as camadas.

(d) As portas usadas por servidores na função bind() se referem a qual camada?

> Utiliza a camada de IP e de transporte

(e) Os endereços usados por clientes na função connect() se referem a qual camada?

> Utiliza a cama de rede.

4. Qual é a diferença entre os métodos `GET` e `POST` no protocolo HTTP?

> GET é usado para requisitar dados de uma fonte específica. POST é usado para enviar dada para um servidor para criar uma fonte.