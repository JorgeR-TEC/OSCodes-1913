#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int fd = open("data", O_RDONLY);
	char *message=malloc(20);
	read(fd, message, 20);
	printf("%s\n", message);
	close(fd);
}