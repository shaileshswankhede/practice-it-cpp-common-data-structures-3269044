#include "process.h"

int main()
{
  Process p[3] = {
      {0, 0, 5, 0, 0},
      {1, 1, 3, 0, 0},
      {2, 2, 1, 0, 0}
  };

  int numProcesses = sizeof(p) / sizeof(p[0]);

  // runFCFS(p, numProcesses);
  runSJFS(p, numProcesses);

  return 0;
}