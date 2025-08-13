/*  Write a program to print the following information about a given file.
 a. inode
 b. number of hard links
 c. uid
 d. gid
 e. size
 f. block size
 g. number of blocks
 h. time of last access
 i. time of last modification
 j. time of last change
  */ 

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(){
	struct stat fileStat;

	if(stat("test.txt",&fileStat)==-1){
		perror("error to getting file:");
		return 1;
	}
	printf("File: test.txt\n");
	printf("Inode: %ld\n", (long)fileStat.st_ino);
	printf("Hard Links: %ld\n", (long)fileStat.st_nlink);
	printf("User ID(UID): %d\n", fileStat.st_uid);
	printf("Group ID(GID): %d\n", fileStat.st_gid);
	printf("Size: %ld bytes\n", (long)fileStat.st_size);
    	printf("Block size: %ld\n", (long)fileStat.st_blksize);
	printf("Number of blocks: %ld\n", (long)fileStat.st_blocks);
	printf("Last Access: %s\n", ctime(&fileStat.st_atime));
    	printf("Last modification: %s", ctime(&fileStat.st_mtime));
    	printf("Last status change: %s", ctime(&fileStat.st_ctime));
	return 0;
}
