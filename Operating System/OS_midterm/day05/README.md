# day05 퀴즈&토론

## Debates/Discussions – Week 3

### (1) Explain the two benefits of multi-tasking.

핵심은 CPU를 놀지 않게 하는 것. CPU의 속도를 최대한 이용하기 위해!

-

1. CPU Utilization : scheduling과 switch를 통해서 동시에 여러가지 일을 수행할 수 있게 해주고 CPU를 놀지 않게 해줌으로써 작업 효율이 증가한다.

2. TimeSharing : CPU는 한번에 하나씩의 프로세스를 처리하지만, switch를 너무나 빠르게 진행하기 때문에 마치 동시에 여러가지 프로그램을 실행하는 것 처럼 보이게 된다. 즉, 한번에 여러 유저가 컴퓨터를 동시에 사용할 수 있게 된다. 또한 CPU Job Scheduling을 통해서 여러가지 작업 중에서 우선순위를 정해 실행할 수 있게 해준다.

### (2) Why do we need so many types of memories (e.g., CPU register, cache, RAM)? What is the advantage?

CPU가 정보처리하는 속도는 매우 빠르기 때문에, CPU의 속도와 맞먹는 메모리를 사용하기에는 너무나 비싸다는 단점이 있다. 따라서 Disk, RAM, Cache, Register 등등을 사용해서, 넓은 용량과 빠른 속도를 모두 잡는 것이다.

~~(3) Explain the difference between high-level language (HLL), assembly language, and machine language~~
<제외됨>

### (4) When your program reads a file from disk, then what happens? Use the following terms for your explanation: I/O request, device driver, device controller, interrupt.

1. 유저 프로그램이 OS에서 I/O request를 device driver을 통해 보낸다
2. device driver가 보낸 I/O request를 Disk의 device Controller가 받는다.
3. device는 해당되는 명령을 수행하고 CPU는 그동안 다른 일을 진행한다.
4. device가 명령을 수행하면 CPU에게 interrupt를 보내고, CPU는 즉시 interrupt된 명령을 수행한다.

### (5) What is dual-mode (CPU mode) operation, and why do we need this? Also, explain why system call is used.

유저 프로그램은 위험할 수 있으나, OS 프로그램은 믿을 수 있기 때문에 따로 모드를 만들어 명령을 수행한다. 이때 사용되는것이 Mode bit 이고, 0 은 Kernel mode, 1 은 user mode 이다. 이때 Kernel mode에서만 사용되어야 하는 명령은 바로 privileged instruction 이다. 이것은 소프트웨어에 손상을 입힐 수도 있는 중요한 명령이기 때문에 반드시 Kernel mode에서만 실행시켜야 한다. 이때 user program이 privileged instruction을 실행시키고 싶을 때, System Calls을 통해서 OS에게 허락을 맡고 실행시키게 된다.
