/*  Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls  */
#include <unistd.h>

int main(){
	char c;
	while(read(0,&c,1)>0){
		write(1,&c,1);
	}
	return 0;
}
