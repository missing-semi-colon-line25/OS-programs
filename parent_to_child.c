#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

#define BUFF_SIZE 25

int main()
{
	char read_msg[BUFF_SIZE];
	char write_msg[BUFF_SIZE] = "Hello world";
	int fd[2];
	pid_t pid;
	
	if(pipe(fd)==-1)
	{
		fprintf(stderr,"Pipe failed");
		return 1;
	}
	pid = fork();
	if(pid<0)
	{
		write(2,"Fork failed",11);
		return 1;
	}
	if(pid>0)
	{
		close(fd[0]);
		write(fd[1],write_msg,strlen(write_msg)+1);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0],read_msg,BUFF_SIZE);
		printf("message read by child: %s ",read_msg);
		close(fd[0]);
	}
	return 0;
}
