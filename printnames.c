#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    struct dirent *entry;
    char *path,fname;
    DIR *dir;
    struct stat st;
    path=argv[1];
    stat(path,&st);
    if (argc!=2)
    {
        fprintf(stderr,"Not enough arguments");
        return 1;
    }
    dir=opendir(path);
    if(!dir)
    {
        printf("%s does not exist",path);
        return 1;
    }
    else
    {
        while((entry=readdir(dir))!=NULL)
        {
            printf("%s\n",entry->d_name);
/*            if(strcmp(entry->dname,filename) = 0)
            {
                printf("File found");
            }
            else
            {
                printf("File not found");
            }*/

        }
       closedir(dir);
    }
    return 0;
}

