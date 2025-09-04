/* Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data. */

#include <fcntl.h>   
#include <unistd.h>  
#include <stdio.h>   

int main() {
    int fd;

    fd = open("test10.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
   
    write(fd, "ABCDEFGHIJ", 10);       
    lseek(fd, 10, SEEK_CUR);          
    write(fd, "1234567890", 10);      

    close(fd);
    return 0;
}

