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
	hints.ai_socktype = SOCK_STREAM; //UDP Socket
	hints.ai_flags = AI_NUMERICSERV;
	
	n= getaddrinfo("guadiana.tecnico.ulisboa.pt",PORT, &hints, &res);
	if(n!=0){
		fprintf(stderr,"error : getaddrinfo : %s\n", gai_strerror(n));
		exit(1);
	}
	

	fd = socket(res->ai_family, res->ai_socktype,res->ai_protocol);
	if(fd == -1) {
		fprintf(stderr,"error : socket : %s\n", gai_strerror(fd));
		exit(1);
	 }


	n= connect (fd,res->ai_addr,res->ai_addrlen);
	if(n == -1) {
		fprintf(stderr,"error : connect : %s\n", gai_strerror(n));
		exit(1);
	 }

	n= write (fd,"Hello!\n",7);
	if(n == -1) {
		fprintf(stderr,"error : write : %s\n", gai_strerror(n));
		exit(1);
	 }
	
	nread = read (fd,buffer,128); //nread or n
	
	if(nread == -1) {
		fprintf(stderr,"error : read : %s\n", gai_strerror(nread));
		exit(1);
	 }

	write(1,"echo: ",6);
	write(1,buffer,nread);
	
	

	
	freeaddrinfo(res);
	close(fd);

	exit (0);
}

