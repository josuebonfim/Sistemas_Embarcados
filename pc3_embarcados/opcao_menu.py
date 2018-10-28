def valida_opcao(c):
	c = c.upper()

	while(c != 'S' and c != 'N' and c != 'E' and  c != 'D'):
		c = input("Opcao invalida. Digite novamente: ")

	return c


c = input("Digite a opcao desejada: ")
c = valida_opcao(c)

file = open("pipe.txt","w")
file.write(c)
file.close()

