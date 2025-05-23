#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
    struct stat sb;
    int ret;
    if(argc!=2)
    {
        fprintf(stderr,"Usage: %s <file> \n",argv[0]);
        return 1;
    }
    ret=stat(argv[1],&sb);
    if(ret)
    {
        perror("stat");
        return 1;
    }
    printf("Size of %s is %ld Bytes\n",argv[1],sb.st_size);
    return 0;
}
