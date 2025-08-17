/*
create the following types of a files using (i) shell command (ii) system call
 a. soft link (symlink system call)
 b. hard link (link system call)
 c. FIFO (mkfifo Library Function or mknod system call
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {

    FILE *fp = fopen("original.txt", "w");
    fprintf(fp, "This is the original file.\n");
    fclose(fp);

    symlink("original.txt", "soft_link.txt");
    printf("Soft link created: soft_link.txt -> original.txt\n");

    link("original.txt", "hard_link.txt");
    printf("Hard link created: hard_link.txt -> original.txt\n");

    mkfifo("myfifo", 0666);
    printf("FIFO created: myfifo\n");

    return 0;
}
