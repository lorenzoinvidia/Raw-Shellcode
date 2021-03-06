#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void) {
   int sockfd, new_sockfd;
   struct sockaddr_in host_addr, client_addr;
   socklen_t sin_size;

   sockfd = socket(AF_INET, SOCK_STREAM, 0);  //(0x2, 0x1, 0x0)

   host_addr.sin_family = AF_INET;
   host_addr.sin_port = htons(31337);
   host_addr.sin_addr.s_addr = INADDR_ANY;
   memset(&(host_addr.sin_zero), '\0', 8);

   bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr));

   listen(sockfd, 4);

   sin_size = sizeof(struct sockaddr_in);
   new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
}
