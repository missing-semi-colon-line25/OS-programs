#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
    struct dirent *entry;
//    char *path;
    char fname[256],dname[256];
    DIR *dir;
    struct stat st;
    int tmp=0;
//    fname=argv[2];
    printf("Enter directory name to be searched\n");
    scanf("%s",dname);
    printf("Enter file name to be searched\n");
    scanf("%s",fname);
/*    if (argc!=2)
    {
        fprintf(stderr,"Not enough arguments");
        return 1;
    }
    path=argv[1];
    stat(path,&st);
 */
    dir=opendir(dname);
    if(!dir)
    {
        printf("%s does not exist",dname);
        return 1;
    }
    else
    {
        while((entry=readdir(dir))!=NULL)
        {
//            tmp=strcmp(entry->d_name,fname);
	    if (entry->d_name == fname) tmp=1;
//            printf("%s",entry->d_name);
        }
        if(tmp == 0)
        {
            printf("File found");
        }
        else
        {
            printf("File not found");
        }
        closedir(dir);
    }
    return 0;
}

