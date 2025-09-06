/*
=======================================================================================
Name:30.c
Author:Jils Patel
Description:Write a program to run a script at a specific time using a Daemon process.
Date: 07 September 2025
=======================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>
#include <syslog.h>

#define LOGGING "Start Logging my task = %d\n"

int main()
{
    pid_t pid;
    int x_fd;

    pid = fork();
    if (pid > 0)
        exit(EXIT_SUCCESS);

    if (setsid() < 0)
        exit(EXIT_FAILURE);

    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    pid = fork();
    if (pid > 0)
    {
        printf("Daemon PID: %d\n", pid);
        exit(EXIT_SUCCESS);
    }

    umask(077);


    chdir("/");


    for (x_fd = sysconf(_SC_OPEN_MAX); x_fd >= 0; x_fd--)
        close(x_fd);

  
    int count = 0;
    openlog("Logs", LOG_PID, LOG_USER);
    while (1)
    {
        sleep(2);
        syslog(LOG_INFO, LOGGING, count++);
    }
    closelog();
    return 0;
}

/*
==========================================================================
Output: jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1$ Daemon PID: 631
        ls
        1.c   15.c     18a.c  22.c  28.c  7.c    file1.txt     record.txt
        10.c  16a.c    18b.c  23.c  3.c   8.c    file2.txt     test10.txt
        11.c  16b.c    19.c   24.c  30.c  9.c    file3.txt     test11.txt
        12.c  17db.c   2.c    25.c  4.c   a.out  file4.txt     test12.txt
        13.c  17tkt.c  20.c   26.c  5.c   c      file5.txt
        14.c  18.c     21.c   27.c  6.c   db     output22.txt
        jils@Inspiron-3593:/mnt/e/SS/hands-on-list-1$
==========================================================================
*/
