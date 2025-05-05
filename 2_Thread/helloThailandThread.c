#include <stdio.h>    /* printf              */
#include <string.h>   /* strcpy              */
#include <unistd.h>   /* fork, getpid, sleep */
#include <pthread.h> /* thread create/join/exit */

char word[10] = "World";

void *hello(void *p)
{
    printf("hello: pid = %d\n", getpid());
    printf("hello: Hello %s\n", word); 
    strcpy(word, "Thailand");
    printf("hello: Hello %s\n", word);
    printf("hello: terminating\n");
    //return NULL;
}


int main(void) 
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    printf("main: pid = %d\n", pid);
    
    pthread_create(&tid, NULL, hello, NULL);
    printf("main: waiting for hello thread to terminate\n");
    pthread_join(tid, NULL);  
    printf("main: hello thread terminated\n"); 
    printf("main: Hello %s\n", word); 
    printf("main: terminating\n");
  
    return 0;
}