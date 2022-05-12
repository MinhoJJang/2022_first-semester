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

#define FRONT 0

typedef struct _PCB
{
    int pid;

    int priority;
    double aging_priority;
    int current_waiting_time;

    int arrival_time;

    int burst_time;
    int cpu_burst_time;

    int firstServedTime;
    int isFirstServed;
    int finishTime;

    double waitingTime;
    double responseTime;
    double turnaroundTime;
} PCB;

PCB job_queue[MAX];
PCB ready_queue[MAX];
PCB process[MAX_PROCESS];

double alpha;                      // aging 기법 사용 시 필요한 변수값이다.
int job_idx = 0;                   // job_queue의 idx
int numberOfJobs = 0;              // 입력받은 전체 프로세스 개수
int processNumberInReadyQueue = 0; // ready_queue에 들어간 프로세스 개수
int ready_idx = 0;                 // ready_queue의 idx
int numberOfFinishedProcess = 0;   // 종료된 프로세스 개수
int finishedFlag = NO;             // 모든 프로세스가 종료되었는지 여부
int runningState = NO;             // 현재 running state에 있는 프로세스가 있는지 여부
int currentTime = 0;               // 전역변수로 설정. 현재시간을 의미한다.
int numberOfIdle = 0;              // cpu가 idle 된 횟수
int numberOfContextSwitch = 0;     // contextSwitch 한 횟수
int allFinishTime = 0;             // 모든 프로세스가 종료된 시간

int noMoreArrival = NO; // 더 도착할 수 있는 프로세스가 있는지 여부
PCB runningProcess;     // 현재 실행중인 프로세스

void runProcess(PCB *p);
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

// 한 프로세스가 running 상태일 때 ready_queue에 있는 프로세스들의 waiting_time을 올려주는 함수
void setReadyQueueProcessPriority()
{
    for (int i = 0; i < ready_idx; i++)
    {
        ready_queue[i].current_waiting_time++;
        ready_queue[i].aging_priority = ready_queue[i].priority + alpha * ready_queue[i].current_waiting_time;
    }
}

// 현재 ready_queue를 priority에 따라 재정렬하는 함수
void sortReadyQueueByAgingPriority()
{
    for (int i = 0; i < ready_idx - 1; i++)
    {
        for (int j = i + 1; j < ready_idx; j++)
        {
            if (ready_queue[j - 1].aging_priority < ready_queue[j].aging_priority)
            {
                PCB temp = ready_queue[j - 1];
                ready_queue[j - 1] = ready_queue[j];
                ready_queue[j] = temp;
            }
        }
    }
}

PCB preemptProcess;
int preemptFlag = NO;
// 현재 running process의 priority와 ready queue의 priority를 비교하여, preempt 상태인지 체크한다.
void comparePriority()
{
    if (ready_queue[FRONT].aging_priority > runningProcess.aging_priority)
    {
        preemptProcess = ready_queue[FRONT];
        preemptFlag = YES;
        printf("preempted!\n");
    }
}

// TimeFlow를 출력하는 함수
void printTimeFlow(int state, PCB *p)
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
        printf("[new arrival] process %d\n", p->pid);
        for (int i = 0; i < numberOfJobs; i++)
        {
            if (job_queue[i].pid == p->pid)
            {
                job_queue[i].current_waiting_time = 0;
                job_queue[i].aging_priority = job_queue[i].priority;
                job_queue[i].arrival_time = currentTime;
                job_queue[i].cpu_burst_time = job_queue[i].burst_time;
                job_queue[i].isFirstServed = YES;
                break;
            }
        }
        break;
    case RUNNING:
        printf("process %d is running\n", p->pid);
        p->burst_time--;
        preemptFlag = NO;
        for (int i = 0; i < numberOfJobs; i++)
        {
            if (job_queue[i].pid == p->pid)
            {
                // 여기서 현재 running state의 프로세스의 current waiting time 을 초기화해준다.
                p->current_waiting_time = 0;
                p->aging_priority = job_queue[i].priority;
                if (job_queue[i].isFirstServed == YES)
                {
                    job_queue[i].isFirstServed = NO;
                    job_queue[i].firstServedTime = currentTime;
                    break;
                }
            }
        }
        setReadyQueueProcessPriority();
        comparePriority();
        break;
    case FINISHED:
        printf("process %d is finished\n", p->pid);
        numberOfFinishedProcess++;
        runningState = NO;
        for (int i = 0; i < numberOfJobs; i++)
        {
            if (job_queue[i].pid == p->pid)
            {
                job_queue[i].finishTime = currentTime;
                break;
            }
        }
        break;
    case CONTEXT_SWITCH:
        printf("------------------------- (Context-Switch)\n");
        preemptFlag = NO;
        numberOfContextSwitch++;
        break;
    case ALL_FINISHED:
        printf("all processes finish\n");
        finishedFlag = YES;
        allFinishTime = currentTime;
        break;
    default:
        break;
    }
}

void restructReadyQueue()
{
    for (int i = 0; i < ready_idx; i++)
    {
        ready_queue[i] = ready_queue[i + 1];
    }
    memset(&ready_queue[ready_idx], 0, sizeof(PCB));
}

// 도착한 프로세스가 있는지 찾는 함수
void checkIfProcessArrive()
{
    if (numberOfFinishedProcess >= numberOfJobs)
    {
        finishedFlag = YES;
        return;
    }

    // 현재 도착할 수 있는 프로세스
    // job_queue는 arrival time으로만 정렬된 배열이다.
    PCB arriveProcess = job_queue[job_idx];

    // 현재 시간과, 도착할 수 있는 프로세스의 arrival time이 같다면 현재 실행시킬 수 있는 프로세스가 있다는 의미이다.
    if (currentTime == arriveProcess.arrival_time && ready_idx + 1 < numberOfJobs)
    {

        printTimeFlow(NEW_ARRIVAL, &arriveProcess);
        ready_queue[ready_idx] = job_queue[job_idx];

        job_idx++;
        ready_idx++;
        if (runningState == NO)
        {
            runningState = YES;
            // 현재 시간동안 동시에 들어오는 프로세스들을 체크한다.

            while (noMoreArrival != YES)
            {
                checkIfProcessArrive();
            }
            sortReadyQueueByAgingPriority();

            runningProcess = ready_queue[FRONT];
            runProcess(&runningProcess); // 항상 ready_queue의 맨 앞에 있는 프로세스를 선택해 돌려야 한다.
        }
    }
    else if (runningState == NO && ready_idx == 0)
    {
        printTimeFlow(IDLE, NULL);
    }
    else
    {
        noMoreArrival = YES;
    }
}

void runProcess(PCB *p)
{
    int runningProcessPid = p->pid;
    ready_idx--;
    runningState = YES;
    // 여기서 ready_queue에서 하나를 running 시켰으므로 ready queue를 다시 정리해준다.
    restructReadyQueue();
    int isProcessFinished = NO;
    preemptFlag = NO;
    // 누군가 preempt 하거나 스스로 종료하기 전까지는 계속 run 시킬 수 있다.
    while (preemptFlag == NO && isProcessFinished == NO)
    {
        if (p->burst_time == 0 && isProcessFinished == NO)
        {
            isProcessFinished = YES;
            printTimeFlow(FINISHED, p);
        }
        else
        {
            printTimeFlow(RUNNING, p);
        }
        // 만약 모든 프로세스가 종료되었을 경우 즉시 끝낸다.
        if (numberOfFinishedProcess == numberOfJobs)
        {
            printTimeFlow(ALL_FINISHED, NULL);
            return;
        }
        currentTime++;
        checkIfProcessArrive();
    }

    // 만약 preempt 되었을 경우
    if (isProcessFinished == NO)
    {
        ready_queue[ready_idx] = *p;
        ready_idx++;
    }

    if (ready_idx > 0)
    {
        sortReadyQueueByAgingPriority();
        runningProcess = ready_queue[FRONT];

        printTimeFlow(CONTEXT_SWITCH, &runningProcess);
        noMoreArrival = NO;
        runProcess(&runningProcess);
    }
}

// ready_queue에 누군가 기다리고 있었을 경우 그것을 context switch 해준다.

void calculateCriteria()
{
    double averageCpuUsage;
    double averageWaitingTime = 0;
    double averageResponseTime = 0;
    double averageTurnaroundTime = 0;

    // 1. cpu usage
    // allFinishedTime - (idle + switch 횟수) / allFinishedTime
    averageCpuUsage = ((double)(allFinishTime - (numberOfIdle + numberOfContextSwitch)) / allFinishTime) * 100;

    for (int i = 0; i < numberOfJobs; i++)
    {
        // 2. waiting time
        // for each process, waitingTime = finishedTime - arrivedTime - burstTime
        job_queue[i].waitingTime = (double)(job_queue[i].finishTime - job_queue[i].arrival_time - job_queue[i].cpu_burst_time);

        // 3. response time
        // firstServedTime - arrivedTime
        job_queue[i].responseTime = (double)(job_queue[i].firstServedTime - job_queue[i].arrival_time);

        // 4. turnaround time
        // finishedTime - arrivedTime
        job_queue[i].turnaroundTime = (double)(job_queue[i].finishTime - job_queue[i].arrival_time);

        averageResponseTime += job_queue[i].responseTime;
        averageTurnaroundTime += job_queue[i].turnaroundTime;
        averageWaitingTime += job_queue[i].waitingTime;

        // jobCheck(job_queue[i]);
    }

    averageResponseTime /= numberOfJobs;
    averageTurnaroundTime /= numberOfJobs;
    averageWaitingTime /= numberOfJobs;

    printf("Average cpu usage : %.2f\n", averageCpuUsage);
    printf("Average waiting time : %.1f\n", averageWaitingTime);
    printf("Average response time : %.1f\n", averageResponseTime);
    printf("Average turnaround time : %.1f\n", averageTurnaroundTime);
}

void priority_scheduling()
{
    printf("Scheduling : Priority - Aging\n");
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
    // {0, 1, 50, 10, 5, 2, 50, 0, 4, 3, 30, 20, 5, 5, 10, 7, 5}
    int userData_idx = 1;

    // alpha = 0.2;
    alpha = atof(argv[2]); // argv값을 int 타입으로 변경

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
    // for (int i = 1; i <= 16; i++)
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

    priority_scheduling();
    // priority scheduling는 매번 current time 증가시마다 현재 runningProcess와 ready_queue의 프로세스의 priority를 비교하는 과정이 필요하다.
}