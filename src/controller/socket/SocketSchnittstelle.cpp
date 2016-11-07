/*
 * SocketSchnittstelle.cpp
 *
 *  Created on: 06.11.2016
 *      Author: hrs
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "SocketSchnittstelle.h"
using namespace std;


void SocketSchnittstelle::run(){
}

double SocketSchnittstelle::recvLiveValue(){
	int sockfd, newsockfd;
	socklen_t addrlen;
	struct sockaddr_in srv, clnt;
	char buf[256];

	if((sockfd=socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("Kann Socket nicht öffnen\n");
	}
	memset((void *) buf, '\0', 256);
	memset(&srv, 0, sizeof(struct sockaddr_in));
	srv.sin_family = AF_INET;
	srv.sin_addr.s_addr = htonl(INADDR_ANY);
	srv.sin_port = htons(19999);
	if(bind(sockfd, (struct sockaddr *) &srv, sizeof(srv)) < 0){
	    printf("Kann Port nicht binden\n");
	}
	if(listen(sockfd, 5) < 0){
	    printf("Fehler in der Warteschlange\n");
	}
	//for(;;){
		addrlen = (socklen_t) sizeof(clnt);
		newsockfd = accept(sockfd, (struct sockaddr *) &clnt, &addrlen);
		if(newsockfd < 0){
			printf("Fehler beim Verbindungsaufbau\n");
		}else{
			if(read(newsockfd, buf, 256) < 0){
			  	printf("Fehler beim Lesen\n");
			}
		}
	//}
	double returnValue;
	if (sscanf(buf,"%lf",&returnValue)==1){
		return returnValue;
	}

	return 0;
}


SocketSchnittstelle::~SocketSchnittstelle() {
	// TODO Auto-generated destructor stub
}
