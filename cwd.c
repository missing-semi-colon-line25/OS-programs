#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define BUFF_LEN 1000

int main(int argc,char * argv[])
{
    char *cwd = getcwd(NULL,0);
    if(!getcwd(cwd,BUFF_LEN))
    {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }
    printf("\nCurrent Working Directory  = %s\n",cwd);
    free(cwd);
    return 0;
}
