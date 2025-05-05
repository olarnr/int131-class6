#include <stdio.h>    /* printf       */
#include <stdlib.h>   /* exit         */
#include <unistd.h>   /* fork, getpid */

int main(void){
        pid_t pid;

        pid = fork();

        if (pid == 0) {
                sleep(1);
                printf("a\n");
        } else {
                sleep(1);
                printf("b\n");
        }
        return 0;
}

