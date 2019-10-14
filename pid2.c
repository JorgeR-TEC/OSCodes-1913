#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	pid_t processID=getpid();
	printf("Hello %s, i am process :%d\n", argv[1], processID);
}	