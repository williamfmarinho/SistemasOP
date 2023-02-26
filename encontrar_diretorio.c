#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(void){
	printf ("\tDiretorio atual: %s\n", getenv("PWD")); //Printa o diretorio atual. 
	return 0;
}
