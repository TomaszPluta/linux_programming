 #include <arpa/inet.h>
#include <netinet/in.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <unistd.h>
 #include <string.h>
 #define BUFLEN 80
 #define PCKT_TO_SEND 1
 #define PORT 9950
 #define SRV_IP "127.0.0.1"
 #define PORT_N 56872



void error_handler(char *s) {
     perror(s);
     _exit(1);
   }

int main(int argc, char * argv[]) {
   struct sockaddr_in serv_adr;
   int cli_socket;
   int slen;
   int send;
   int recv;

   int send_buff_size;
   int recv_buff_size;
   char send_buffer[BUFLEN];
   char recv_buffer[BUFLEN];
   send_buff_size = sizeof(send_buffer);
   recv_buff_size = sizeof(send_buffer);

   slen = sizeof(serv_adr);
   cli_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
   if(socket < 0){
	   error_handler("socket");
   }


   memset((char *) &serv_adr, 0, sizeof(serv_adr));
   serv_adr.sin_family = AF_INET;
   serv_adr.sin_port = 56872;
   inet_aton(SRV_IP, &serv_adr.sin_addr);

   printf("Gniazdo nr %d\n", cli_socket);
   printf("Port  nr %d\n", serv_adr.sin_port);
   printf("adres IP klienta:  %s\n",  inet_ntoa(serv_adr.sin_addr));

   int i;
   for (i=0; i<PCKT_TO_SEND; i++) {
      sprintf(send_buffer, "Hello from client nr  %d", i);
      send = sendto(cli_socket, &send_buffer, send_buff_size, 0, (struct sockaddr *)&serv_adr, (socklen_t)slen);
      if(send < 0){
    	  error_handler("sendto()");
      }
      printf("Wyslano komunikat: %s\n", send_buffer);

      printf("Czekam na odpowiedz...\n");
      recv = recvfrom(cli_socket, &recv_buffer, recv_buff_size, 0, (struct sockaddr *)&serv_adr, (socklen_t *) &slen);
      if(recv < 0) {
    	  error_handler("recvfrom()");
      }

      printf("Otrzymana odpowiedz: %s\n", recv_buffer);
      sleep(1);
   }
   close(cli_socket);
   return 0;
}

