#define _GNU_SOURCE
#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi */
#include <math.h>     /* floor */
#include <pthread.h>  /* thread create/join/exit */
#include <sched.h>

int Count = 0;

void Increment(void)
{
  int i;
  int loops = 1000 * 1000;
  for (i = 0; i < loops; i++)
    Count++;
}

void *thread(void *n)
{
  int N = *(int *)n; // convert argument to integer
  int i;

  for (i = 0; i < N; i++)
    Increment();

  return NULL;
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: %s <xxx>\n", argv[0]);
    return 1;
  }

  int N = 100 + atoi(argv[1]); // convert first argument to integer
  int n0 = floor(N / 2), n1 = N - n0; // split N into two parts
  pthread_t thread_id[2];
  cpu_set_t cpu1;
  pthread_attr_t attr;

  CPU_SET(1, &cpu1); /* set to use CPU1 only */
  pthread_attr_init(&attr);
  pthread_attr_setaffinity_np(&attr, sizeof(cpu1), &cpu1);
  
    /* create thread0 and thread1 and run them concurrently on CPU1 */
  pthread_create(&thread_id[0], &attr, thread, &n0);
  pthread_create(&thread_id[1], &attr, thread, &n1);

  /* wait until thread0 and thread1 are completed */
  pthread_join(thread_id[0], NULL);
  pthread_join(thread_id[1], NULL);

  printf("Count = %i\n", Count);

  return 0;
}
