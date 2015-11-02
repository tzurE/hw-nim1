#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>

int parse_msg(char* msg){

}

int main_client_loop(sockfd) { 
	printf("connected \n");
	close(sockfd);

}

int main(int argc, char** argv) {

	char* hostname = "localhost";
	int port = 6444;
	struct sockaddr_in server_addr;

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(port);

	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (sockfd < 0 ){
		printf("error in socket!\n");
	}

	if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
		printf("\nerror connecting!");
	}
	main_client_loop(sockfd);	
}