#include <pthread.h>
#include <stdio.h>

pthread_mutex_t m;
pthread_cond_t cond;
int count = 0;

void *printOdd(void *arg)
{
  int *max = (int *)arg;
  while (1)
  {
    pthread_mutex_lock(&m);
    if (count % 2 == 0)
    {
      pthread_cond_wait(&cond, &m);
    }
    printf("%d ", count++);
    if (count > *max)
      break;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&m);
  }
}

void *printEven(void *arg)
{
  int *max = (int *)arg;
  while (1)
  {
    pthread_mutex_lock(&m);
    if (count % 2)
    {
      pthread_cond_wait(&cond, &m);
    }
    printf("%d ", count++);
    if (count > *max)
      break;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&m);
  }
}

int main()
{
  pthread_t t1, t2;
  int max = 100;
  pthread_create(&t1, NULL, printOdd, &max);
  pthread_create(&t1, NULL, printEven, &max);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}