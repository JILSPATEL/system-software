#include <stdio.h>      
#include <fcntl.h>      
#include <unistd.h>     

int main(){
	int fd;
	fd=open("txtFile.txt",O_RDWR);
	if(fd==-1){
		perror("file already exists");
	}
	else{
		printf("file created. FD: %d\n",fd);
		close(fd);
	}

	// Try opening with O_EXCL (only works with O_CREAT)
	fd=open("txtFile.txt",O_CREAT | O_EXCL | O_RDWR,0644);
	if(fd==-1){
		perror("O_EXCL failed");
	}
	else{
		printf("O_EXCL succeeded. FD = %d\n",fd);
		close(fd);
	}
	return 0;
}
