#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int *a;
int main(){
	pid_t processID=getpid();
	a=malloc(1);
	*a=5;
	
	printf("The parent process id is:%d\n", processID);
	pid_t childID=fork();
	if (childID>0){
		*a=3;
		printf("I am the parent with pid %d and a child with pid %d", processID, childID);
		
		wait(NULL);
		printf("%d\n", *a);
		//execl("/mnt/c/Users/L03040561/oscodes/pid2", "pid2", "jorge", NULL);
	}else{
		printf("i am the child");
		*a=7;
		printf("%d\n", *a);
		sleep(1);
	}
	
	return 0;
}