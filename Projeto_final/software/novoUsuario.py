nome = input("Nome: ")
data_nascimento = input("Data de Nascimento: ")
email = input("e-mail: ")

file = open("test.txt", "a")
file.write("Nome: " + nome + "\n")
file.write("Data de Nascimento: " + data_nascimento + "\n")
file.write("e-mail: " + email + "\n")
file.write("\n")

file.close()