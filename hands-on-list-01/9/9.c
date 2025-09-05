/*  
===================================================================================
Name:9.c
Author:Jils Patel
Description:Write a program to print the following information about a given file.
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
Date: 07 September 2025
===================================================================================
 */

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    struct stat fileStat;
    const char *filename = "file1.txt";

    if (stat(filename, &fileStat) < 0) {
        perror("stat");
        exit(1);
    }

    printf("File: %s\n", filename);
    printf("Inode: %ld\n", (long)fileStat.st_ino);
    printf("Number of hard links: %ld\n", (long)fileStat.st_nlink);
    printf("UID: %ld\n", (long)fileStat.st_uid);
    printf("GID: %ld\n", (long)fileStat.st_gid);
    printf("Size: %ld bytes\n", (long)fileStat.st_size);
    printf("Block size: %ld\n", (long)fileStat.st_blksize);
    printf("Number of blocks: %ld\n", (long)fileStat.st_blocks);

    printf("Time of last access: %s", ctime(&fileStat.st_atime));
    printf("Time of last modification: %s", ctime(&fileStat.st_mtime));
    printf("Time of last change: %s", ctime(&fileStat.st_ctime));

    return 0;
}

/*
========================================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/9$ cc 9.c
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/9$ echo "sample text" > file1.txt
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/9$ ./a.out
        File: file1.txt
        Inode: 281474976710963
        Number of hard links: 1
        UID: 1000
        GID: 1000
        Size: 12 bytes
        Block size: 512
        Number of blocks: 0
        Time of last access: Fri Sep  5 11:10:28 2025
        Time of last modification: Fri Sep  5 11:10:28 2025
        Time of last change: Fri Sep  5 11:10:28 2025
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1/9$
=========================================================================================
*/
