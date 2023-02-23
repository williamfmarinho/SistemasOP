#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void procurarCaminho(){
		int pid = fork (); // cria um novo processo.
		
		if (pid < 0){ //checa se o processo foi criado com sucesso.
		fprintf (stderr, "fork falhou"); //Se der erro na criação manda uma msg indicando que  falhou.
		return;
		}
		
		else if (pid == 0){
		printf ("Sou o novo processo, meu id é: %d\n", pid); //o ID igual a zero indica que estamos no novo processo, ou processo "filho".
		execlp ("/home/williamfreire/Área de Trabalho/diretorio","", NULL); //executa o programa "diretorio" que printa na tela o diretorio atual
		}
		else {
		printf ("Sou o processo inicial, ID do filho %d\n", pid); //Aqui estamos no processo atual, ou "pai"
		wait (NULL); //Caso o sistema dê prioridade pro pai, aqui ele espera o "filho" terminar de executar.
		printf ("Filho completou\n");
		}
	return;
}

void esperarComando(){
	printf ("\nDigite o comando: \n");
	char comando[5]; 
	scanf ("%s", comando); //Armazenando o comando do usuario em uma variável.
	printf ("Comando digitado: %s\n", comando);
	
	if (strcmp(comando, "sair") == 0)
		exit(0);
	if (strcmp(comando, "pwd") == 0) //Se o comando digitado for o pwd, chama o comando pra criar o fork.
		procurarCaminho();
	else
		printf ("Comando invalido!\n"); //Caso não seja um comando válido, mostra um erro e retorna pro main.
	return;
}

int main(void){
	while(1){ //Loop infinito pra sempre aguardar um novo comando do usuário
	esperarComando();
	}
	return 0;
}
