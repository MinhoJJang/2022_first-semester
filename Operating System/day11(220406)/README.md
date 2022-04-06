# Quiz & Debate

## (1) Explain the difference between preemptive and non-preemptive scheduling. What are the pros/cons?

preemptive scheduling은 중간에 interrupt가 발생하여 강제로 CPU에서 꺼낼 수 있으나 non-preemptive 는 프로세스가 자연스럽게 종료할때까지 interrupt가 불가능하다. preemtive의 장점은 time-sharing이 잘 된다는 것이고 단점은 race condition이 발생하여 interrupt된 위치에 따라 결과가 바뀔수도 있다는 것이다. non-preemptive 같은 경우 context switch overhead가 줄어든다는 장점이 있지만, response time이 길어지는 단점이 있다.

## (2) Why does FCFS result in convoy effect?

pass

## (3) Explain how SJF can predict the CPU burst length.

pass

## (4) What are the benefits of Round-robin scheduling, compared with (i) FCFS, (ii) SJF? What are the pro/cons of frequent context switching?

FCFS: Low response time, Low waiting time
SJF: CPU bound jobs 에 대해서 Starvation이 줄어든다.
pros: 위의 세가지
cons: 같은 사이즈 작업에 대해서 오히려 turnaround time이 FCFS에 비해 늘어나게 된다.
