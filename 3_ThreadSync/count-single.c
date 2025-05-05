#include <stdio.h> /* printf */
#include <stdlib.h> /* atoi */

int Count = 0;

void Increment(void)
{
  int i;
  int loops = 1000 * 1000;
  for (i = 0; i < loops; i++)
    Count++;
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: %s <xxx>\n", argv[0]);
    return 1;
  }
  
  int N = 100 + atoi(argv[1]); // convert first argument to integer
  int i;

  for (i = 0; i < N; i++)
    Increment();

  printf("Count = %i\n", Count);

  return 0;
}
