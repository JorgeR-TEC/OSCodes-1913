#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msgbuf {
 long type;       /* message type, must be > 0 */
 char text[100];    /* message data */
}message;


int main(){
 key_t key=ftok("queue", 11);
 int queue=msgget(key, 0666|IPC_CREAT);
 msgrcv(queue, &message, sizeof(message), 0,0);
 printf("client received: %s\n", message.text);
 return 0;
}