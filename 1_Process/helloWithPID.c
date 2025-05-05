#include <stdio.h>    /* printf       */
#include <stdlib.h>   /* exit         */
#include <unistd.h>   /* fork, getpid */
#include <sys/wait.h> /* wait         */

int main(void){
	pid_t pid;

	pid = fork();

	if (pid == 0) {
		printf("[PID: %i] Hello from child process!\n", getpid());
		sleep(10);
	} else {
		printf("[PID: %i] Hello from parent process!\n", getpid());
		sleep(10);
	}
	return 0;
}