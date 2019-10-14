#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
int main(){
	mkfifo("data", 0666);
	int fd = open("./data", O_WRONLY);
	char *message="hello";
	write(fd, message, strlen(message)+1);
	close(fd);

}