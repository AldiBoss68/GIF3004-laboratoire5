#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#define MAX 80 
#define PORT 4059 
#define SA struct sockaddr 
void func(int sockfd) 
{ 
	char buff[MAX]; 
	int i; 
	
	while(1) { 
		bzero(buff, MAX); 

		// Lecture et copie du message du client
		read(sockfd, buff, sizeof(buff)); 
		 
		printf("%s", buff); 
		//bzero(buff, MAX); 
		//i = 0; 
		// copie du message ddu serveur dans le buffer 
		//while ((buff[i++] = getchar()) != '\n') 
			; 

		// Envoie du buffer au client 
		//write(sockfd, buff, sizeof(buff)); 

		// Condition pour sortir du serveur 
		//if (strncmp("exit", buff, 4) == 0) { 
		//	printf("Fermeture du serveur\n"); 
		//	break; 
		//} 
	} 
} 

int main() 
{ 
	int sockfd, nouveauSocket; 
	struct sockaddr_in servaddr, cli; 

	// création su socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		perror("Erreur de création\n"); 
		exit(1); 
	} 
	else
		printf("le socket a été créé\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("10.248.141.125"); 
	servaddr.sin_port = htons(PORT); 

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("Impossible de se connectr au serveur\n"); 
		exit(0); 
	} 
	else
		printf("connexion au serveur réussi\n"); 

	// function for chat 
	func(sockfd); 

	// close the socket 
	close(sockfd); 
} 

