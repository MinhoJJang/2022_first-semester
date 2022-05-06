#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct _PCB
{
    int pid;
    int priority;
    int arrival_time;
    int burst_time;
    struct _PCB *next;
} PCB;

PCB job_queue[MAX];
PCB ready_queue[MAX];

int main(int argc, char *argv[])
{
}