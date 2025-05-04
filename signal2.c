#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
void handler(int num)
	{
		static int count = 0;
		if(count>=2)
		{
			printf("Tried to exit 3 times ,  killing process");
			exit(EXIT_SUCCESS);
		}
		char* msg = "Ha ha ,I will not diee!!!";
		write(STDOUT_FILENO,msg,strlen(msg));
		sleep(3);
		count++;
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
		}
		return 0;
	}
