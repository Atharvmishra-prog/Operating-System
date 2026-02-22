#include <stdio.h>
#include <unistd.h>

int main() 
{
    pid_t pid;
    pid = fork(); // Create a new process
    if (pid < 0) 
    {
        printf("Fork failed!\n");
    }
    else if (pid == 0) 
    {
        printf("This is the child process.\n");
        printf("Child PID: %d\n", getpid());
    }
    else 
    {
        printf("This is the parent process.\n");
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
    }
return 0;
}
