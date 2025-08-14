/*Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
use dup
use dup2
use fcntl*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	int fd1,fd2,fd3;
	fd1=open("test11.txt",O_WRONLY|O_CREAT|O_APPEND,0644);
	fd2=dup(fd1);
	fd3=dup2(fd1,100);
	int fd4=fcntl(fd1,F_DUPFD,0);
	write(fd1, "Written from fd1\n",17);
    	write(fd2, "Written from fd2 copy From fd1\n",31);
    	write(fd3, "Written from fd3 copy from fd1\n",31);
    	write(fd4, "Written from fd4 copy from fd1\n",31);
	return 0;
}
