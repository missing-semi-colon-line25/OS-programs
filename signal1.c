#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<signal.h>
#include<string.h>

void handler(int num)
	{
		char* msg = "Ha ha ,I will not diee!!!";
		write(STDOUT_FILENO,msg,strlen(msg));
		sleep(3);
	}
	
void stp_handler(int num)
{
	char* msg = "Caught SIGTSTP";
	write(STDOUT_FILENO,msg,strlen(msg));
	sleep(3);
}

int main(void)
	{
		signal(SIGINT,handler);
		signal(SIGTSTP,stp_handler);
		int n=0;
		while(1)
		{
			printf("\n %d Hello Pid = %d ",n++,getpid());
			sleep(2);
		}
		return 0;
	}
