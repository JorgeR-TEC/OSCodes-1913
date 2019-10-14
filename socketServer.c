#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){
  int sock=socket(AF_INET, SOCK_STREAM,0);
  struct sockaddr_in address;
  int addrlen=sizeof(address);
  address.sin_family=AF_INET;
  address.sin_addr.s_addr=INADDR_ANY;
  address.sin_port=htons(1024);
  char buffer[1024]; 
  bind(sock, (struct sockaddr*)&address, addrlen);
  listen(sock, 2); 	
  int new=accept(sock, (struct sockaddr*)&address, (socklen_t *)&addrlen);
  read(new, buffer, 1024);
  printf("%s\n", buffer);
  close(new);
  close(sock);
  return 0;
}

