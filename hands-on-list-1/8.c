#include <fcntl.h>   // open()
#include <unistd.h>  // read(), write(), close()

int main(int argc, char *argv[]) {
    int fd;
    char c;

    if (argc != 2) {
        write(1, "Usage: ./task8 <filename>\n", 27);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) return 1;

    while (read(fd, &c, 1) > 0) {
        write(1, &c, 1); // print character
        if (c == '\n') { // line ended
            // we could do something special here if needed
        }
    }

    close(fd);
    return 0;
}

