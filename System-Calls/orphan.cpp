#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed!\n");
    } 
    else if (pid == 0) {
        printf("Child process started (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        sleep(5);  
        printf("After sleep, Child PID: %d, New Parent PID: %d (Orphan adopted by init/systemd)\n",
               getpid(), getppid());
    } 
    else {
        printf("Parent process exiting (PID: %d)\n", getpid());
    }
    return 0;
}
