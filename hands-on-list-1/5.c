#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd[5];
	for(int i=0;i<5;i++){
		char filename[20];
		sprintf(filename,"file%d.txt",i+1);
		fd[i]=open(filename,O_CREAT | O_RDWR, 0644);
		if(fd[i]==-1){
			perror("error occur");
			return 1;
		}
		printf("created %s with fd= %d\n",filename,fd[i]);
	}
	printf("process ID: %d\n",getpid());

	while(1){
		
	}
	return 0;
}
