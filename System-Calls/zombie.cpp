#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed!\n");
        exit(1);
    }else if (pid == 0) {
        printf("Child process started (PID: %d)\n", getpid());
        printf("Child exiting immediately...\n");
        exit(0);
    } else {
        printf("Parent process (PID: %d) sleeping...\n", getpid());
        sleep(10);  
        printf("Parent finished sleeping. Now exiting.\n");
    }
    return 0;
}
