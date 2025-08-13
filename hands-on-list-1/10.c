#include <fcntl.h>   
#include <unistd.h>  
#include <stdio.h>   

int main() {
    int fd;

    fd = open("test10.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, "ABCDEFGHIJ", 10);       
    lseek(fd, 10, SEEK_CUR);          
    write(fd, "1234567890", 10);      

    close(fd);
    return 0;
}

