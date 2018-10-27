nome = input("Nome: ")
data_nascimento = input("Data de Nascimento: ")
email = input("e-mail: ")

file = open("test.txt", "a")
file.write(nome + "\n")
file.write(data_nascimento + "\n")
file.write(email + "\n")
file.write("\n")

file.close()