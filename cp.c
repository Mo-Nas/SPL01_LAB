#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
        int fd_source, fd_dest, openFlags;
        ssize_t numRead;
        char buf[BUF_SIZE];

        if (argc != 3 || strcmp(argv[1], "--help") == 0)
        {
                printf("Usage: %s old-file new-file\n", argv[0]);
                return 1;
        }

        fd_source = open(argv[1], O_RDONLY);
        if (fd_source < 0)
        {
                perror("cannot open source file\n");
                return 2;
        }

        openFlags = O_CREAT | O_WRONLY | O_TRUNC;
        mode_t filePerms = S_IRUSR | S_IWUSR | 
                S_IRGRP | S_IWGRP | S_IROTH;

        fd_dest = open(argv[2], openFlags, filePerms);

        if (fd_dest < 0)
        {
                perror("cannot open destination file\n");
                close(fd_source);
                return 3;
        }

        while ((numRead = read(fd_source,buf,BUF_SIZE)) > 0)
        {
                if (write(fd_dest, buf, numRead) != numRead){
                        perror("couldn't write whole buffer\n");
                        close(fd_source);
                        close(fd_dest);
                        return 4;
                }
        }

        if (numRead == -1)
        {
                perror("cannot read\n");
                close(fd_source);
                close(fd_dest);
                return 5;
        }

        if(close(fd_source) == -1)
        {
                perror("cannot close source file\n");
                return 6;
        }

        if(close(fd_dest) == -1)
        {
                perror("cannot close distination file\n");
                return 7;
        }

        return 0;
}
