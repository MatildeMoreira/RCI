/* Libraries */
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>

/* Parameters */
#define PORT "58001"

int main (void)
{
	
	int fd, addrlen, n ,nread;
	struct addrinfo hints;
	struct addrinfo *res;
	struct sockaddr_in addr;
	char buffer [128];
	
	memset(&hints,0,sizeof hints);
	hints.ai_family = AF_INET; //IPv4
	hints.ai_socktype = SOCK_DGRAM; //UDP Socket
	hints.ai_flags = AI_PASSIVE|AI_NUMERICSERV;
	
	n= getaddrinfo(NULL,PORT, &hints, &res);
	if(n!=0){
		fprintf(stderr,"error : getaddrinfo : %s\n", gai_strerror(n));
		exit(1);
	}
	

	fd = socket(res->ai_family, res->ai_socktype,res->ai_protocol);
	if(fd == -1) {
		fprintf(stderr,"error : socket : %s\n", gai_strerror(fd));
		exit(1);
	 }


	n= bind (fd,res->ai_addr,res->ai_addrlen);
	if(n == -1) {
		fprintf(stderr,"error : recvfrom : %s\n", gai_strerror(n));
		exit(1);
	 }

	addrlen = sizeof(addr);
	
	nread = recvfrom(fd,buffer,128,0,(struct sockaddr*)&addr,&addrlen);
	
	if(nread == -1) {
		fprintf(stderr,"error : recvfrom : %s\n", gai_strerror(nread));
		exit(1);
	 }

	write(1,"received: ",10);
	write(1,buffer,nread);
	
	n= sendto(fd, buffer,nread,0,(struct sockaddr*)&addr,addrlen);
	if(n == -1) {
		fprintf(stderr,"error : sendto : %s\n", gai_strerror(n));
		exit(1);
	 }


	
	freeaddrinfo(res);
	close(fd);

	exit (0);
}

