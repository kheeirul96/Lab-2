#include<stdio.h>   
#include<string.h>  
#include<sys/socket.h>  
#include<arpa/inet.h>   
#include<netinet/in.h>

int main(int argc , char *argv[])
{
    int sock,num,len;
    struct sockaddr_in server;
    char buffer[100];
    

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("cound'n create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8883);

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        printf("connection error");
        return 1;
    }

    puts("Connected\n");

    //loop untuk communicate ngan server
    
    if(num = recv(sock,buffer,100,0) <0)
     {
	printf("Read Error");
     }
    else
      {
	buffer[num] ='\0';
	printf("%s",buffer);
      }

    close(sock);
    return 0;
}