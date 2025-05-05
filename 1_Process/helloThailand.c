#include <stdio.h>    /* printf              */
#include <stdlib.h>   /* exit                */
#include <string.h>   /* strcpy              */
#include <unistd.h>   /* fork, getpid, sleep */
#include <sys/wait.h> /* wait                */

int main(void) 
{
  int pid;
  char word[10] = "World";

  pid = getpid();
  printf("parent: pid = %d\n", pid);
  
  pid = fork();
  
  if (pid == 0) /* child process is always 0 */
  {
    printf("child: Hello %s\n", word); 
    strcpy(word, "Thailand");
    printf("child: Hello %s\n", word);
    printf("child: child exiting\n");
    exit(0);
  }
  else /* parent process is non-zero (child's pid) */
  { 
    sleep(1);
    printf("parent: child pid = %d\n", pid);
    printf("parent: waiting for child\n");
    wait(NULL);
    printf("parent: child terminated\n"); 
    printf("parent: Hello %s\n", word); 
  }
  printf("parent: parent exiting\n");
  
  return 0;
}