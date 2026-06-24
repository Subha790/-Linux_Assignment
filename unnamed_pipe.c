#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    char message[] = "Hello Child";
    char buffer[100];

    pipe(fd);

    if(fork() == 0)
    {
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    }
    else
    {
        write(fd[1], message, strlen(message) + 1);
    }

    return 0;
}
