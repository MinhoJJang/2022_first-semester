# As#1

```c
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 5
int nums[SIZE] = {0,1,2,3,4};

int main(){

    int i;
    pid_t pid;

            pid = fork();

            if(pid == 0){
                    for(i=0; i<SIZE; i++){
                            nums[i] *= -i;
                            printf("CHILD: %d ", nums[i]); // LINE X
                    }
            }
            else if(pid>0){
                    wait(NULL);
                    for(i=0; i<SIZE; i++){
                            printf("PARENT: %d ",nums[i]); // LINE Y
                    }
            }
            return 0;
}
```

1. WAIT(NULL) 때문에, parent process가 child 프로세스가 끝나는 것을 기다리는 상태가 된다. 따라서 LINE X 가 전부 실행된 후에 LINE Y가 실행된다. 따라서 LINE X은 아래와 같은 결과를 도출한다.
   `CHILD: 0 CHILD: -1 CHILD: -4 CHILD: -9 CHILD: -16`
   이때, LINE X에서 nums 배열의 값을 바꿔놓았지만 fork() 함수는 부모와 자식 간에 독립적인 공간을 생성하기 때문에 자식에서의 nums[] 변경은 부모에게 영향을 미치지 않는다. 따라서 LINE Y는 아래와 같은 결과를 도출한다.
   `PARENT: 0 PARENT: 1 PARENT: 2 PARENT: 3 PARENT: 4`

Due to WAIT (NULL), the parent process is in a state waiting for the child process to end. Therefore, LINE Y is executed after LINE X is terminated. Therefore, LINE X shows the following results.
`CHILD: 0 CHILD: -1 CHILD: -4 CHILD: -9 CHILD: -16`
At this time, the values of the numbers in nums[] were changed in LINE X, but since the fork() function creates an independent space between parents and child, the changes in nums[] in child do not affect parents. Therefore, LINE Y shows the following results.
`PARENT: 0 PARENT: 1 PARENT: 2 PARENT: 3 PARENT: 4`

2. WAIT(NULL); 이 없어지면, parent process 는 child process가 끝날 때까지 기다릴 이유가 없어진다. 그렇게 되면 parent와 child 중 누가 먼저 실행되느냐 라는 문제는 CPU scheduler 가 결정한다. 결과를 살펴보면 부모 프로세스가 먼저 끝난 것을 확인할 수 있다. 따라서 LINE Y의 결과는 `PARENT: 0 PARENT: 1 PARENT: 2 PARENT: 3 PARENT: 4` 이고, 이어서 자식 프로세스가 종료되었고 LINE X의 결과는 `CHILD: 0 CHILD: -1 CHILD: -4 CHILD: -9 CHILD: -16` 이다.

When WAIT (NULL) is gone, there is no reason for the parent process to wait until the child process is terminated. Then, the CPU scheduler determines the question of who runs first, parent or child. Looking at the results, it can be seen that the parent process has terminated first. Therefore, the result of LINE Y is `PARENT: 0 PARENT: 1 PARENT: 2 PARENT: 3 PARENT: 4` , followed by the child process terminated, and the result of LINE X is `CHILD: 0 CHILD: -1 CHILD: -4 CHILD: -9 CHILD: -16`.
