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
	char sendline[100];
	int sock, conn;
	struct sockaddr_in servaddr;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	bzero( &servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(22000);

	bind(sock, (struct sockaddr *) &servaddr, sizeof(servaddr));

	listen(sock, 10);

	conn = accept(sock, (struct sockaddr*) NULL, NULL);

	while(1)
	{
		bzero( sendline, 100);
		read(conn,sendline,100);
		printf("Server: %s",sendline);
		write(conn,sendline, strlen(sendline)+1);
	}
	return 0;
}
