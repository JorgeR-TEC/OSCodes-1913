#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

int main(){
	char* parent_message = "hello";  
	char* child_message = "goodbye";
	char *string=(char *)mmap(NULL, 10, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	strcpy(string, parent_message);
	pid_t id= fork();
	if(id>0){
		wait(NULL);
		printf("Parent message: %s\n", (char *)string);
	}else{
		strcpy(string, child_message);
		printf("child message: %s\n", (char *)string);
	}
	
	
}