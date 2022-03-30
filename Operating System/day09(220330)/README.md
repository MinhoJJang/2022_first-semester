# Quiz & Debate

## (1) Which of the components of a process are shared across threads in a multithreaded process? Explain. (a. Register values b. Heap c. Data d. Stack)

-> Data , Heap
int \*a 에서, a의 주소값은 data에 저장되고 a가 가리키는 값은 Heap에 저장된다. 이때 우리는 thread 끼리 공유할 때 data를 공유한다고 했다. 그런데 a가 가리키는 값이 3이고, 그 3이 위치한 곳이 Heap 이기 때문에 Heap 역시 공유된다.

## (2) Explain why multithreading may allow continued execution even when a system call happens (aka Non-blocking system call)

하나의 쓰레드가 멈춰도, concurrent 덕분에 다른 Thread 를 바로바로 실행시켜 프로세스가 놀지 않게 해준다.

## (3) Consider Figure 4.16.

### (a) What is the output of Line C and Line P?

5, 0

### (b) What happens if pthread_join() was not used?

runner 가 먼저 실행되는지, printf가 먼저 실행되는지 모르기 때문에, value값이 0일수도 있고 5일수도 있다.

### (c) What happens if wait() was not used? Explain.

parent가 먼저 멈추든 멈추지 않든 간에 value 값이 0인 것은 변하지 않는다.

## (4) Discuss Possible output threads in chapter 4 slides pages 32-35. Explain how case 3 and case 4 can happen.
