#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int n;
    int filedes[2];
    char buffer[1025];
    char *message;

    message = "Hello World!";
    n = pipe(filedes);
    n = write(filedes[1], message, strlen(message));

    // if ((n = read ( filedes[0], buffer, 1024 ) ) >= 0) {
    //     buffer[n] = 0;  //terminate the string
    //     printf("read %d bytes from the pipe: %s\n", n, buffer);
    // }
	n = read (filedes[0], buffer, 1024);
	if (n >= 0) 
	{
        	//buffer[n] = 0;  //terminate the string
        	printf("read %d bytes from the pipe: %s\n", n, buffer);
    	}  
    else
        perror("read");
    //exit(0);
}