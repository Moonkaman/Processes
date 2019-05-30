// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int f = fork();

    if (f < 0)
    {
        fprintf(stderr, "fork failed\n");
    }
    else if (f == 0)
    {
        printf("\n");
        char *args[] = {"ls", "-l", (char *)NULL};
        char *path = "/bin/ls";
        execv(path, args);
    }
    else
    {
        int wc = waitpid(f, NULL, 0);
        printf("Child done\n");
    }
    return 0;
}
