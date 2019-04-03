#include<stdio.h>
#include<string.h>  
#include<sys/socket.h>
#include<arpa/inet.h> 
#include<unistd.h>
#include<time.h>

int main()
{
   int socket_desc , client_sock, c;
   struct sockaddr_in server , client;
   time_t masa;
   char str[100];
   
   

   //Create socket
   socket_desc = socket(AF_INET , SOCK_STREAM , 0);
   if (socket_desc == -1)
   {
       printf("Could not create socket");
   }
   puts("Socket created");

   //Prepare the sockaddr_in structure
   server.sin_family = AF_INET;
   server.sin_addr.s_addr = INADDR_ANY;
   server.sin_port = htons( 8883 );

   //Bind
   if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
   {
       //error message
       printf("bind failed. Error");
       return 1;
   }
   puts("bind done");

   //Listen
   listen(socket_desc , 3);

   //Accept and incoming connection
   puts("Waiting for incoming connections...");
   c = sizeof(struct sockaddr_in);

   //accept connection from an incoming client
   client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
   if (client_sock < 0)
   {
       printf("accept failed");
       return 1;
   }
   puts("Connection accepted");

  masa = time(NULL);
  snprintf(str,sizeof(str),"%s",ctime(&masa));
  printf("%s",str);
  write(client_sock,str,100);

   return 0;
}