#include <fcntl.h>   
#include <unistd.h>  

#define BUF_SIZE 1024

int main() {
    int fd_src = open("file1.txt", O_RDONLY);
    int fd_dest = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buffer[BUF_SIZE];
    int bytesRead;

    while ((bytesRead = read(fd_src, buffer, BUF_SIZE)) > 0) {
        write(fd_dest, buffer, bytesRead);
    }

    close(fd_src);
    close(fd_dest);
    return 0;
}

