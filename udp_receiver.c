#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;
    char buffer[100];
    struct sockaddr_in server_addr, client_addr;
    socklen_t len = sizeof(client_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8081);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr *)&client_addr, &len);

    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}
