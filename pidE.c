#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int a=0;
	pid_t newPid=fork();
	if(newPid>0){
		sleep(100);
		wait(NULL);
		pid_t myPid=getpid();
		printf("I am process %d and my child is %d\n", myPid, newPid);
		printf("Value of variable a in parent is %d\n", a);
	}else{
		a=1;
		pid_t myPid=getpid();
		printf("I am process %d and my child is %d\n", myPid, newPid);
		printf("Value of variable a in child is %d\n", a);
		
		//execl("/mnt/c/Users/L03040561/oscodes/pid2", "pid2", "jorge", NULL);
	}
	return 0;
}