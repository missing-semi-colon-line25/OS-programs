#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
//#include<sysltypes.h>
#include<unistd.h>

int main()
{
	char filename[100];
	printf("Enter the filename to open for reading: ");
	scanf("%s", filename);
	int fp = open(filename,O_RDONLY);
	char* c = (char*)calloc(100, sizeof(char));
	int sz = read(fp, c, 50);
//	c[sz] = '\0';
	printf("% s\n", c);
	fp = open("copied_file.txt",O_WRONLY|O_CREAT|O_TRUNC);
	sz = write(fp,c,sizeof(sz));
	
}

