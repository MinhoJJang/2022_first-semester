# 문제 조건 파악

궁극적인 목표->
FCFS, RR, Preemptive Priority Scheduling with Aging.
이 세 가지 스케줄링 기법을 시뮬레이션 할 수 있는 코드를 만들어라.

이때, 실제로 프로세스를 만들 필요는 없다. "시뮬레이션" 이기 때문이다.

시뮬레이터의 출력은 간트 차트와 비슷할 것이다.

1. PCB block 만들기
   - PCB block 자체에 linked List를 구현
2. job queue에는 10개의 프로세스들이 있다고 가정한다.
3. 모든 프로세스는 NEW state에 있다.
4. 프로세스들의 모든 동작은, user input에 따라 달라진다.

user input

pid
1-10
priority
larger, the higher.
arrival_time
task arrive time, the unit of milliseconds
burst_time
CPU burst time, the unit of milliseconds

For each algorithm, calculate

1. Average Waiting time of each process (pid)
2. Average Response time of each process (pid)
3. Average Turnaround time of each process
4. overall CPU usage (0~100%)

```
Scheduling : FCFS
==========================================
<time 0> ---- system is idle ----
<time 1> ---- system is idle ----
<time 2> [new arrival] process 1
<time 2> process 1 is running
<time 3> process 1 is running
<time 4> process 1 is running
<time 5> process 1 is running
<time 6> [new arrival] process 2
<time 6> process 1 is running
<time 7> process 1 is finished
------------------------------- (Context-Switch)
<time 8> process 2 is running
…
<time 50> all processes finish
==========================================
Avarage cpu usage : 92.00 %
Avarage waiting time : 15.2
Avarage response time : 12.1
Avarage turnaround time: 21.0

Scheduling : RR
==========================================
<time 0> ---- system is idle ----
<time 1> ---- system is idle ----
<time 2> [new arrival] process 1
<time 2> process 1 is running
<time 3> process 1 is running
<time 4> process 1 is running
<time 5> process 1 is running
<time 6> [new arrival] process 2
<time 6> process 1 is running
<time 7> process 1 is finished
------------------------------- (Context-Switch)
<time 8> process 2 is running
…
<time 50> all processes finish
==========================================
Avarage cpu usage : 92.00 %
Avarage waiting time : 7.2
Avarage response time : 7.1
Avarage turnaround time: 18.0
```

The priority of a process =
Base priority + f(waiting time t of the process)
f( t ) = alpha \* t

```
your_sched_name
[input_filename] [output_filename]
[time_quantum_for_RR] [alpha_for_PRIO]
Example:
> os22 scenario1.dat output1.txt 5 0.2
```

```
Recommendation
You can use a data structure similar to a Process Control Block (PCB) for each task,
though yours will be much simpler.
Two queues are maintained; one for the job queue and one for the ready queue


The job queue may be implemented simply with an Array!
and the ready queue with a linked-list
Simulator
The simulator first initializes the job queue and the data structure of PCB information for
10 processes (which are set to be in the NEW state – this is our assumption)
The simulator then reads the task information from the input file and stores all data in a
data structure.
Then, start simulating a scheduling algorithm in a time-driven manner.
At each time unit (or slot), it adds any newly arrived task(s) into the ready queue and
runs a specific scheduler algorithm in order to select appropriate task from ready queue.
When a task is chosen to run, the simulator prints out a message indicating what
process ID is chosen to execute for this time slot. If no task is running (i.e. empty ready
queue), it prints out an “idle” message.
Before advancing to the next time unit, the simulator should make all necessary
changes in job and ready queue status.
```
