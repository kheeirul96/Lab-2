#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>


int main(int argc,char **argv)
{
	int sockfd,n;
	struct sockaddr_in servaddr;

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof servaddr);

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(22000);
	inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));

	connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	
	char ch[100];
	int n1=0,n2=0,newch,loop=1;
	while(loop>0){
	scanf("%s",&ch);
	scanf("%d",&n1);
	scanf("%d",&n2);
	
	if ((strcmp(ch,"ADD")==0)||(strcmp(ch,"add")==0))
		newch =1;
	else if ((strcmp(ch,"SUB")==0)||(strcmp(ch,"sub")==0))
		newch=2;
	else if ((strcmp(ch,"MUL")==0)||(strcmp(ch,"mul")==0))
		newch=3;
	else if ((strcmp(ch,"DIV")==0)||(strcmp(ch,"div")==0))
		newch=4;
	else 
		loop = 0;

	int nchoice=htonl(newch);
	int nn1 = htonl(n1);
	int nn2 = htonl(n2);
	
	write(sockfd,&nchoice,sizeof(nchoice));
	write(sockfd,&nn1,sizeof(nn1));
	write(sockfd,&nn2,sizeof(nn2));
	}
	close(sockfd);
}
