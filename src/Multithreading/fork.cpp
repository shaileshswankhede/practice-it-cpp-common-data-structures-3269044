#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int globalVar = 5;

int main2()
{
  int pid = fork();
  globalVar++;
  printf("addr of globalVar: %p\n", &globalVar);
  if (pid == 0)
  {
    sleep(3);
    globalVar++;
    printf("running child thread with pid: %d, tid: %lu\n", getpid(), pthread_self());
    // Though child process gets new pid, thread id remains same within process context
    // as in child process, parent process's code, memory, file descriptor, thread context gets copied
    printf("addr of globalVar in child context: %p, value: %d\n", &globalVar, globalVar);
    // Since address we print is virtual address, it will show up as same as child process inherits paranets address space
    // Physical address will defer after either of thread tries to modify global variable (copy-on-write)
  }
  else
  {
    // modifying global variable in parent's address space doesn't have any effect on child process's global variable
    // as child process will have copy of global variable
    globalVar++;
    printf("running parent thread with pid: %d, tid: %lu\n", getpid(), pthread_self());
    printf("addr of globalVar in parent context: %p, value: %d\n", &globalVar, globalVar);
  }
  return 0;
}