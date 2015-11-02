#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>


int listenfd;

int parse_msg(char* msg){

}

int main_game_loop(connfd, A_size, B_size, C_size){
	printf("in game loop\n");
	char* message = "";
	//initiate connection - Length and announcment of a new game
	// msg[0]=length, msg[2]=msg type
	message = "0001#1";




	close(connfd);
	close(listenfd);
	exit(0) ;

}


int main(int argc, char** argv){
	char* hostname = "localhost";
	int connfd = 0;
	int port = 6444;
	struct sockaddr_in server_addr;
	int A_size = 10, B_size = 10, C_size = 10;


	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	//add error check

	memset(&server_addr, '0', sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(port);

	if(bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr))){
		printf("\nError bind)");
		return 0;
	}

	if(listen(listenfd, 5)){
		printf("\n error listening");
		return 0;
	}


	while(1){
		connfd = accept(listenfd, NULL, NULL);
		if(connfd < 0){
			printf("\n error");
			return 0;
		}
		main_game_loop(connfd, A_size, B_size, C_size);
	}

}