#include <iostream>
#include <unistd.h>

int main()
{
  int pid;
  if (pid = fork() == 0)
  {
    printf("A: I am a child, my pid is %d\n", getpid());
    exit(0);
  }
  printf("B: I am the parent, my pid is %d\n", getpid());
  printf("C: I just created a child whose pid is %d\n", pid);
  return 0;
}