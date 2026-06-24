#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int fd;

    mkfifo("myfifo", 0666);

    fd = open("myfifo", O_WRONLY);

    write(fd, "Hello FIFO", strlen("Hello FIFO") + 1);

    close(fd);

    return 0;
}
