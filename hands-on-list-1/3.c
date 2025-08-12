#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	// Permissions: 0644 = rw-r--r-- (owner can read/write, others can read)
    int fd = creat("myfile.txt", 0644);

    if(fd==-1){
    	perror("error occurs");
	return 1;
    }

    printf("File created : %d\n",fd);
    close(fd);
    return 0;
}
