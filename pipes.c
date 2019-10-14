#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int fd[2];
	pipe(fd);
	pid_t childId=fork();
	if(childId>0){//padre
		char *message=malloc(20);
		strcpy(message, "goodbye");
		close(fd[1]);//cerrar escritura para el padre
		wait(NULL);
		read(fd[0], message, 20);
		printf("received %s from child\n", message);
	}else{//hijo
		close(fd[0]);
		char *message="hello";
		printf("sent %s to parent\n", message);
		write(fd[1], message, strlen(message));
		close(fd[1]);
	}
}