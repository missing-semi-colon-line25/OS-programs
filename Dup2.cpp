#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main() {
    int fd1 = open("file11_4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char* line;
    
    if (fd1 < 0) {
        perror("open file1");
        exit(EXIT_FAILURE);
    }

    int fd2 = open("file12_4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        perror("open file2");
        close(fd1);
        exit(EXIT_FAILURE);
    }

    // Duplicate fd1 into fd2
    if (dup2(fd1, fd2) < 0) {
        perror("dup2");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }

    // Now fd2 also refers to file11_4.txt
    //after dup2(fd1, fd2), both fd1 and fd2 refer to the same file, but they share the same file offset, so writes will appear one after the other, not starting from the beginning each time.
    
    line = "This is from fd1 ****\n";
    write(fd1,line , strlen(line));
    
     line = "This is from fd2 *** \n";
    write(fd2, line , strlen(line));

    close(fd1);
    close(fd2);

    return 0;
}
