#include <bits/stdc++.h>
#include "process.h"

using namespace std;

bool cmpArrival(const Process &p1, const Process &p2)
{
  return p1.arrival < p2.arrival; // sort in ascending order of process arrival. FCFS
}

void runSJFS(Process p[], int num)
{
  sort(p, p + num, cmpArrival);
  // wait queue to maintain process with min service time at top
  priority_queue<Process> pq;

  uint32_t idx = 0;
  uint64_t currTime = 0;
  while (pq.size() || idx < num)
  {
    // while task's arrival time is less than current time, add it to pq
    while (idx < num and p[idx].arrival <= max(p[0].arrival, (uint32_t)currTime))
      pq.push(p[idx++]);

    // if queue is empty start with next process
    if (pq.size() == 0)
      pq.push(p[idx++]);
  }
}