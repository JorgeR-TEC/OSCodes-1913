#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv){
	char* argumentos[argc];
	int i=0;
	for(i=1; i<argc; i++){
		argumentos[i-1]=argv[i];
		//printf("%s\n", argumentos[i-1]);
	}
	argumentos[argc-1]=NULL;
	int a=execvp(argv[1], argumentos);
	printf("%d\n", a);
}
