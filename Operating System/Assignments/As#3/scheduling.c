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

PCB job_queue[MAX];
PCB ready_queue[MAX];
PCB process[MAX_PROCESS];

int numberOfJobs = 0;              // 입력받은 전체 프로세스 개수
int processNumberInReadyQueue = 0; // ready_queue에 들어간 프로세스 개수
int ready_idx = 0;                 // ready_queue의 idx
int numberOfFinishedProcess = 0;   // 종료된 프로세스 개수
int finishedFlag = NO;             // 모든 프로세스가 종료되었는지 여부
int runningState = NO;             // 현재 running state에 있는 프로세스가 있는지 여부
int currentTime = 0;               // 전역변수로 설정. 현재시간을 의미한다.

// 아래 변수들은 FCFS의 cpu usage, waiting time, response time, turnaround time 을 계산하기 위해 존재한다.
int numberOfIdle = 0;          // cpu가 idle 된 횟수
int arrivalTimeSum = 0;        // 프로세스가 도착한 시간의 합
int contextSwitchTimeSum = 0;  // 프로세스가 context switch된 시간의 합
int numberOfContextSwitch = 0; // contextSwitch 한 횟수
int finishTimeSum = 0;         // 프로세스가 끝난 시간의 합

void checkIfProcessArrive();

// =================================================

// job_queue에 있는 process들을 arrival time 을 기준으로 정렬해준다. process 개수가 기껏해야 10개밖에 되지 않으므로 단순하게 sort 해준다. 오름차순 정렬.
void sortJobQueue()
{
    for (int i = 0; i < numberOfJobs - 1; i++)
    {

        for (int j = i + 1; j < numberOfJobs; j++)
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
        numberOfIdle++;
        break;
    case NEW_ARRIVAL:
        printf("[new arrival] process %d\n", p.pid);
        arrivalTimeSum += currentTime;
        break;
    case RUNNING:
        printf("process %d is running\n", p.pid);
        break;
    case FINISHED:
        printf("process %d is finished\n", p.pid);
        processNumberInReadyQueue--; // 프로세스가 종료했으므로 1 감소시켜준다.
        numberOfFinishedProcess++;
        runningState = NO;
        finishTimeSum += currentTime;
        break;
    case CONTEXT_SWITCH:
        printf("--------------------------------- (Context-Switch)\n");
        contextSwitchTimeSum += currentTime;
        numberOfContextSwitch++;
        currentTime += 1;
        break;
    case ALL_FINISHED:
        printf("all processes finish\n");
        finishedFlag = YES;
    default:
        break;
    }
}

void calculateCriteria()
{
    double averageCpuUsage;
    double averageWaitingTime;
    double averageResponseTime;
    double averageTurnaroundTime;
    int finalTime = currentTime; // 모든 실행을 마치고 난 뒤에 계산한다.

    averageCpuUsage = ((double)(finalTime - numberOfIdle - numberOfContextSwitch) / finalTime) * 100;
    averageWaitingTime = (double)(contextSwitchTimeSum - arrivalTimeSum) / numberOfJobs;
    averageResponseTime = (double)(contextSwitchTimeSum - arrivalTimeSum) / numberOfJobs;
    averageTurnaroundTime = (double)(finishTimeSum - arrivalTimeSum) / numberOfJobs;
    // TODO conSTsum 고치기

    printf("Average cpu usage : %.2f %\n", averageCpuUsage);
    printf("Avarage waiting time : %.1f\n", averageWaitingTime);
    printf("Avarage response time : %.1f\n", averageResponseTime);
    printf("Avarage turnaround time: %.1f\n", averageTurnaroundTime);
}
int noMoreArrival = NO;
// 프로세스를 실행시키는 함수. 실행 과정에서 발생할 수 있는 일들에 대해 모두 표현해놓았다.
void runProcess(PCB p)
{
    if (processNumberInReadyQueue > 0)
    {
        int burstTime = p.burst_time;
        int maxArrivalCount = numberOfJobs - numberOfFinishedProcess;
        while (noMoreArrival != YES || maxArrivalCount > 0) // 혹시 다른 프로세스가 도착했는지 확인한다.
        {
            checkIfProcessArrive();
            maxArrivalCount--;
        }

        for (int i = 0; i < burstTime; i++)
        {
            printTimeFlow(RUNNING, p);
            currentTime++;
            checkIfProcessArrive();
        }
        printTimeFlow(FINISHED, p); // burst Time이 모두 종료되면 finish시킨다.

        // 만약 모든 프로세스에 대해 작업이 끝났다면 즉시 종료한다.
        if (numberOfFinishedProcess == numberOfJobs)
        {
            printTimeFlow(ALL_FINISHED, p);
        }

        // 이때, 만약 readyQueue에 하나 이상의 프로세스가 대기 상태일 경우 context switch 와 함께 다음 프로세스를 실행시켜주면 된다. 만약 아닐 경우 idle 상태이다.
        if (processNumberInReadyQueue > 0)
        {
            printTimeFlow(CONTEXT_SWITCH, p);
            runningState = YES;
            runProcess(ready_queue[numberOfFinishedProcess]);
        }
    }
}
// 프로세스가 도착했는지 체크하고, 도착했을 경우 ready_queue에 프로세스를 넣는 함수.
void checkIfProcessArrive()
{
    if (numberOfFinishedProcess >= numberOfJobs)
    {
        finishedFlag = YES;
        return;
    }

    PCB arriveProcess = job_queue[ready_idx]; // 미리 정렬해놓았기 때문에 맨 앞의 job_queue가 가장 먼저 도착한다고 예상할 수 있다.

    if (arriveProcess.arrival_time == currentTime)
    {
        ready_queue[ready_idx] = arriveProcess;
        printTimeFlow(NEW_ARRIVAL, arriveProcess);
        processNumberInReadyQueue++;
        ready_idx++;
        if (runningState == NO)
        {
            runningState = YES;
            runProcess(ready_queue[numberOfFinishedProcess]);
        }
    }
    else if (runningState == NO)
    {
        printTimeFlow(IDLE, arriveProcess);
    }
    else
    {
        noMoreArrival = YES;
    }
}

// 스케줄링 진행하는 함수
void FCFS_scheduling()
{
    printf("Scheduling : FCFS\n");
    printf("=============================================\n");

    sortJobQueue();
    while (finishedFlag == NO)
    {
        checkIfProcessArrive();
        currentTime++;
    }
    printf("=============================================\n");
    calculateCriteria();
}

int main(int argc, char *argv[])
{
    // 먼저, 유저가 입력하는 값들을 정제하여 사용 할 수 있는 데이터로 가공하는 작업을 해준다.
    FILE *openFile = fopen(argv[1], "r");
    // FILE *writeFile = fopen(argv[2], "w");
    int userData[MAX];
    int userData_idx = 1;

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
            job_queue[numberOfJobs] = process[process_idx];
            process_idx++;
            numberOfJobs++;
            break;
        default:
            break;
        }
    }

    /*
        FCFS Scheduling

        arrival time기준으로 작은 것을 우선으로 실행시키면 된다.
        job_queue의 arrival time을 가져와서, 순서를 정하고 실행시킨다.

        - process가 arrive 했을 때
        - process가 종료하였을 때
        - process가 context-switch 되었을 때
        - 모든 process가 종료되었을 때
        - 아무런 process가 아직 도착하지 않았을 때
        - process가 실행 중일때

        모든 동작은 time을 기준으로 동작한다. 1millisecond 당 어떤 일이 발생하는지 print해야 한다.
    */

    FCFS_scheduling();

    /*
        CPU usage = 전체 사용 time에서 cpu idle 시간을 뺀 값
        waiting time = 프로세스가 ready queue에서 기다린 시간
        response time = 프로세스가 ready queue에 들어와서, 처음으로 running 되기까지 걸린 시간
        turnaround time = 프로세스가 arrive 한 후 finish 하기까지 걸린 시간
    */
}
