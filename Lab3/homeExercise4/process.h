#ifndef PROCESS
#define PROCESS

typedef struct process Process;

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
};

#endif
