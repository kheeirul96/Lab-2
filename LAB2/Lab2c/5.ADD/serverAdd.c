#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>


int main()
{
	int listen_fd, comm_fd;

	struct sockaddr_in servaddr;

	listen_fd = socket(AF_INET, SOCK_STREAM, 0);

	bzero( &servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(22000);

	bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	listen(listen_fd, 10);

	comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);


	int nn1=0,nn2=0,nchoice=0,ans,loop=1;
	
	while(loop>0){
	read(comm_fd,&nchoice,sizeof(nchoice));
	read(comm_fd,&nn1,sizeof(nn1));
	read(comm_fd,&nn2,sizeof(nn2));

	int choice= ntohl(nchoice);
	int n1=ntohl(nn1);
	int n2=ntohl(nn2);
	if (choice == 1){
		ans = n1+n2;
		fprintf(stdout,"ANSWER: %d\n",ans);
	}
	else if(choice == 2){
		ans = n1-n2;
		fprintf(stdout,"ANSWER: %d\n",ans);}
	else if(choice == 3){
		ans = n1*n2;
		fprintf(stdout,"ANSWER: %d\n",ans);}
	else if(choice == 4){
		ans = n1/n2;
		fprintf(stdout,"ANSWER: %d\n",ans);
	}
	else 
		loop =0;
	}
	close(comm_fd);
}
