#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>

#define FIFO_PATH "/tmp/myfifo"

void writer_process()
{
	int fd;
	char msg[]="Hellow world\n";
	fd = open(FIFO_PATH,O_WRONLY);
	if(fd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	write(fd,msg,strlen(msg)+1);
	printf("\n Message sent : %s ",msg);
	close(fd);
}

void reader_process()
{
	int fd;
	char buff[100];
	fd = open(FIFO_PATH,O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	read(fd,buff,sizeof(buff));
	printf("\n message recieved : %s ",buff);
	close(fd);
}

int main()
{
	pid_t pid;
	mkfifo(FIFO_PATH,0666);
	pid=fork();
	if(pid==-1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid==0)
	{
		writer_process();
	}
	else
	{
		reader_process();
		wait(NULL);
		unlink(FIFO_PATH);
	}	
	return 0;
}
