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
    // Create an original file to link to
    FILE *fp = fopen("original.txt", "w");
    if (!fp) {
        perror("Error creating original file");
        return 1;
    }
    fprintf(fp, "This is the original file.\n");
    fclose(fp);

    // Create soft link
    if (symlink("original.txt", "soft_link.txt") == -1) {
        perror("Error creating soft link");
    } else {
        printf("Soft link created: soft_link.txt -> original.txt\n");
    }

    // Create hard link
    if (link("original.txt", "hard_link.txt") == -1) {
        perror("Error creating hard link");
    } else {
        printf("Hard link created: hard_link.txt -> original.txt\n");
    }

    // Create FIFO
    if (mkfifo("myfifo", 0666) == -1) {
        perror("Error creating FIFO");
    } else {
        printf("FIFO created: myfifo\n");
    }

    return 0;
}
