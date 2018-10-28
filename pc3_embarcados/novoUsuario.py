import os

nome = input("Nome: ")
data_nascimento = input("Data de Nascimento: ")
email = input("e-mail: ")

file = open("test.txt", "a")
file.write(nome + "\n")
file.write(data_nascimento + "\n")
file.write(email + "\n")

file.close()

fn = nome.split(" ")
nome1 = fn[0]
nome2 = fn[1]

nome_da_pasta = nome1 + "_" + nome2

a = "mkdir " + nome_da_pasta
b = os.popen(a, "r")

file = open(nome_da_pasta + "_dados.txt", "w")
file.write(nome + "\n")
file.write(data_nascimento + "\n")
file.write(email + "\n")
file.close()

a = "mv "+ nome_da_pasta + "_dados.txt ~/pc3_embarcados/" + nome_da_pasta
os.system(a)

file = open("nome.txt", "w")
file.write(nome_da_pasta)
file.close()
