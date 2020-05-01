#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 256 
#define PORT 4059 
#define SA struct sockaddr 


void func(int sockfd) 
{ 
	char buff[MAX]; 
	int i; 
	while(1) { 
		bzero(buff, sizeof(buff)); 
		printf("Enter the string : "); 
		i = 0; 
		while ((buff[i++] = getchar()) != '\n'); 
		
		
			write(sockfd, buff, sizeof(buff)); 
			 
		
		//bzero(buff, sizeof(buff)); 
		//read(sockfd, buff, sizeof(buff)); 
		//printf("From Server : %s", buff); 
		if ((strncmp(buff, "exit", 4)) == 0) { 
			printf("Fermeture du client\n"); 
			break; 
		} 
	} 
	//
	
} 


int main() 
{ 
	int sockfd, nouveauSocket, len; 
	struct sockaddr_in servaddr, cli; 

	// Creation du socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		perror("erreur de création du socket"); 
		exit(1); 
	} 
	else
		printf("Le socket a été créé\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 

	// Bind
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		perror("Erreur du bind\n"); 
		exit(1); 
	} 

	else
		printf("Le bind a été effectué\n"); 

	// Listen
	if ((listen(sockfd, 5)) != 0) { 
		perror("Erreur du Listen\n"); 
		exit(1); 
	} 
	else
		printf("Serveur en attente de connexion.....\n"); 
	len = sizeof(cli); 

	// Accept
	nouveauSocket = accept(sockfd, (SA*)&cli, &len); 
	if (nouveauSocket < 0) { 
		perror("erreur de accept\n"); 
		exit(1); 
	} 
	else
		printf("La connexion entre le serveur et le  client a été établi \n"); 

	// Function for chatting between client and server 
	func(nouveauSocket); 

	// After chatting close the socket 
	close(sockfd); 
} 
