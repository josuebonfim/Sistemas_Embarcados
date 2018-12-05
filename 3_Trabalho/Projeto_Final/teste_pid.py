import os

f = open("kill.txt", "w")
f.write(str(os.getpid()))
f.close

print os.getpid()


a = 0

while(1):
	a = a + 1
	a = a - 1 
