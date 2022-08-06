#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int ft;
    char fn[] = "creat.txt";
    char text[] = "This is a test";
    ft = creat(fn, S_IRWXG);
    if (ft == -1)
    {
        printf("opening file error %d", ft);
    }
    else
    {
        ft = write(ft,text);
    }
    return 0;
}