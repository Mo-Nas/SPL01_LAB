#include <unistd.h> 
#include <stdio.h>

#define buf_size 1024

int main()
{
        char buf[buf_size];
        if(getcwd(buf,  buf_size) != NULL){
                printf("%s\n",buf);
                return 0;
        }
        else {
                perror("smth went wrong");
                return 1;
        }
}
