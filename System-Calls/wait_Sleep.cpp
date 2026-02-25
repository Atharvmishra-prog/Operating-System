#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
	pid_t pid;
	pid = fork(); 
	if (pid < 0) {
		printf("Fork failed!\n");
	}else if (pid == 0) {
		printf("Child process started (PID: %d)\n", getpid());
		printf("Child is going to sleep for 5 seconds...\n");
		sleep(5);  
		printf("Child process woke up and is terminating.\n");
	}else {
		printf("Parent process (PID: %d) waiting for child...\n", getpid());
		wait(NULL);  
		printf("Child process finished. Parent resuming execution.\n");
	}
	return 0;
}