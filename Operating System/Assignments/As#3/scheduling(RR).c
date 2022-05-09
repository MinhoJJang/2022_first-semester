#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS 15
#define MAX 200

#define IDLE 0
#define NEW_ARRIVAL 1
#define RUNNING 2
#define FINISHED 3
#define CONTEXT_SWITCH 4
#define ALL_FINISHED 5

#define YES 1
#define NO 0

typedef struct _PCB
{
    int pid;
    int priority;
    int arrival_time;
    int burst_time;

} PCB;

typedef struct _Time
{
    int waiting_time;

} Time;

PCB job_queue[MAX];
PCB ready_queue[MAX];
PCB process[MAX_PROCESS];

int NumberOfJobs = 0; // 입력받은 전체 프로세스 개수

int currentTime = 0; // 전역변수로 설정. 현재시간을 의미한다.
int slice;           // RR의 time quantum을 의미한다.

void checkIfProcessArrive();

// =================================================

// job_queue에 있는 process들을 arrival time 을 기준으로 정렬해준다. process 개수가 기껏해야 10개밖에 되지 않으므로 단순하게 sort 해준다. 오름차순 정렬.
void sortJobQueue()
{
    for (int i = 0; i < NumberOfJobs - 1; i++)
    {

        for (int j = i + 1; j < NumberOfJobs; j++)
        {
            PCB frontProcess = job_queue[j - 1];
            PCB backProcess = job_queue[j];
            PCB temp;

            if (frontProcess.arrival_time > backProcess.arrival_time)
            {
                temp = backProcess;
                job_queue[j] = frontProcess;
                job_queue[j - 1] = temp;
            }
        }
    }
}

// TimeFlow를 출력하는 함수
void printTimeFlow(int state, PCB p)
{
    if (state != CONTEXT_SWITCH)
    {
        printf("<time %d> ", currentTime);
    }

    switch (state)
    {
    case IDLE:
        printf("---- system is idle ----\n");

        break;
    case NEW_ARRIVAL:
        printf("[new arrival] process %d\n", p.pid);

        break;
    case RUNNING:
        printf("process %d is running\n", p.pid);
        break;
    case FINISHED:
        printf("process %d is finished\n", p.pid);

        break;
    case CONTEXT_SWITCH:
        printf("------------------------- (Context-Switch)\n");

        break;
    case ALL_FINISHED:
        printf("all processes finish\n");

    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    // 먼저, 유저가 입력하는 값들을 정제하여 사용 할 수 있는 데이터로 가공하는 작업을 해준다.
    FILE *openFile = fopen(argv[1], "r");
    // FILE *writeFile = fopen(argv[2], "w");
    int userData[MAX];
    int userData_idx = 1;

    slice = atoi(argv[3]); // argv값을 int 타입으로 변경

    if (openFile == 0)
    {
        printf("Could not open file\n");
    }
    else
    {
        int data;
        while (!feof(openFile))
        {
            //공백으로 분리된 파일 읽기
            fscanf(openFile, "%d\n", &data);
            userData[userData_idx] = data;

            userData_idx++;
        }

        fclose(openFile);
    }

    // 이제 userData 내부의값들을 PCB에 넣어주어야 한다.

    int process_idx = 1;
    for (int i = 1; i <= userData_idx; i++)
    {
        int mod = i % 4;
        switch (mod)
        {
        case 1:
            process[process_idx].pid = userData[i];
            break;
        case 2:
            process[process_idx].priority = userData[i];
            break;
        case 3:
            process[process_idx].arrival_time = userData[i];
            break;
        case 0:
            process[process_idx].burst_time = userData[i];
            job_queue[NumberOfJobs] = process[process_idx];
            process_idx++;
            NumberOfJobs++;
            break;
        default:
            break;
        }
    }

    /*
         RR 방식은 FCFS에 비해 고려해야 할 것이 조금 많다.
         일단, 기본적으로 time slice 가 주어진다. 이 time slice마다, context-switch가 발생하여야 하는데 그 기준은 arrival-time 이다.

        - process가 arrive 했을 때
        - process가 종료하였을 때
        - process가 context-switch 되었을 때
        - 모든 process가 종료되었을 때
        - 아무런 process가 아직 도착하지 않았을 때
        - process가 실행 중일때

        모든 동작은 time을 기준으로 동작한다. 1millisecond 당 어떤 일이 발생하는지 print해야 한다.
    */

    /*
    CPU usage = 전체 사용 time에서 cpu idle 시간을 뺀 값
    waiting time = 프로세스가 ready queue에서 기다린 시간
    response time = 프로세스가 ready queue에 들어와서, 처음으로 running 되기까지 걸린 시간
    turnaround time = 프로세스가 arrive 한 후 finish 하기까지 걸린 시간
*/
}
