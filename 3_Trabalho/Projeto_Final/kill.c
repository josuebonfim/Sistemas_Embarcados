#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main ()
{
	int fp, i;
	char pid[10], c, comando[] = "kill ";
	
	i = 0;
	fp = open("out.txt",O_RDONLY);
	while((read(fp, &c, 1)) != 0)
	{
		pid[i] = c;
		i++;
	}
	close(fp);
	pid[i] = '\0';
	
	strcat(comando, pid);
	system(comando);
	system("rm out.txt");
}
