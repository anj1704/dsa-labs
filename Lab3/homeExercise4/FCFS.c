#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"
#include "process.h"

Process maker(int pid, int arrival_time, int burst_time)
{
    Process p;
    p.pid = pid;
    p.arrival_time = arrival_time;
    p.burst_time = burst_time;
    return p;
}

int main()
{   
    FILE *fp;
    fp = fopen("fcfs_input.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    char *line = (char*) malloc(100); 
    int n;
    if (fgets(line, 100, fp) != NULL){

        n = atoi(line);

    }

    Queue *q = createQueue();

    int pid = 0;
    int arrival_time = 0;
    int burst_time = 0;
    int time = 0;

    do
    {
        while (fgets(line, 100, fp) != NULL){
            
            char *token;
            token = strtok(line, " ");
            pid = atoi(token);
            token = strtok(NULL, " ");
            arrival_time = atoi(token);
            token = strtok(NULL, " ");
            burst_time = atoi(token);
            printf("pid: %d, arrival_time: %d, burst_time: %d \n", pid, arrival_time, burst_time);
            token = strtok(NULL, " ");
            Process p = maker(pid, arrival_time, burst_time);
            enqueue(q,p);

        }

        if (!isEmpty(q)){

            if (time >= front(q)->arrival_time){

                 printf("Process %d started at time %d\n", front(q)->pid, time);
                while (front(q)->burst_time > 0) {
                    time++;
                    front(q)->burst_time--;
                }
                printf("Process %d finished at time %d\n", front(q)->pid, time);
                dequeue(q);

            }
            else{

                time++;

            }
        }
        else time++;
        
    }
    while(!isEmpty(q));
    fclose(fp);
    destroyQueue(q);

    return 0;

}
