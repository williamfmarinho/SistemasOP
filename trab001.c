#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void procurarCaminho(){
		int pid = fork (); // cria um novo processo. Chamada do sistema fork() de gerenciamento de processo.
		
		if (pid < 0){ //checa se o processo foi criado com sucesso.
		fprintf (stderr, "Fork não foi criado"); //Se der erro na criação manda uma msg pro stderr indicando que  falhou.
		return;
		}
		
		else if (pid == 0){
		printf ("Sou o novo processo, meu id é: %d\n", pid); //o ID igual a zero indica que estamos no novo processo, ou processo "filho". printf() por sí só não é uma chamada de sistema, mas invoca write() que é uma chamada de sistema de gerenciamento de arquivo.
		execlp ("/home/williamfreire/Área de Trabalho/diretorio","", NULL); //executa o programa "diretorio" que printa na tela o diretorio atual. Chamada do sistema execlp() do tipo gerenciamento de processo.
		}
		else {
		printf ("Sou o processo inicial, ID do filho %d\n", pid); //Aqui estamos no processo atual, ou "pai"
		wait (NULL); //Chamada do sistema de gerenciamento de processo. Espera o processo filho terminar.
		printf ("Processo filho terminou de executar\n");
		}
	return;
}

void esperarComando(){
	printf ("\nDigite o comando: \n");
	char comando[5]; 
	scanf ("%s", comando); //Armazenando o comando do usuario em uma variável.
	printf ("Comando digitado: %s\n", comando);
	
	if (strcmp(comando, "sair") == 0) //strcmp() compara duas strings. "sair" para sair do programa.
		exit(0); //Sai do programa
	if (strcmp(comando, "pwd") == 0) //Se o comando digitado for o pwd, chama o comando pra criar o fork.
		procurarCaminho();
	else
		printf ("Comando invalido!\n"); //Caso não seja um comando válido, mostra um erro e retorna pro main.
	return;
}

int main(void){
	while(1){
		esperarComando(); //Loop infinito pra sempre aguardar um novo comando do usuário
	}
	return 0;
}
