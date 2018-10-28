import os

file = open("nome.txt", "r")
nome = file.read()
os.system("./move.sh")
os.system("mv fingerprint.bmp /home/pi/pc3_embarcados/" + nome)
