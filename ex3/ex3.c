// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int status;
    int f = fork();
    if (f < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (f == 0)
    {
        printf("hello\n");
    }
    else
    {
        int wc = waitpid(f, &status, 0);
        printf("goodbye\n");
    }

    return 0;
}
