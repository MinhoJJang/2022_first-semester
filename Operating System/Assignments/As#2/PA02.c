#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 100
#define AVERAGE 0
#define MINIMUM 1
#define MAXIMUM 2

int average = 0;
int minimum = 0;
int maximum = 0;

// 대략적으로 MAX개의 데이터가 들어온다고 가정하여 만들었다. 데이터 수가 증가하면 MAX부분만 수정하면 된다.
int num[MAX] = {0};

// 입력하려는 숫자 개수
int N;

void *runner(void *param)
{
    // 형변환 뒤 역참조하여 내부값을 가져왔다.
    int select = *(int *)param;

    printf("start = tid[%d]\n", select);
    /*
        #define AVERAGE 0
        #define MINIMUM 1
        #define MAXIMUM 2
    */

    if (select == AVERAGE)
    {
        for (int i = 0; i < N; i++)
        {
            average += num[i];
        }
        average /= N;
    }
    else if (select == MINIMUM)
    {
        minimum = num[0];
        for (int i = 1; i < N; i++)
        {
            if (minimum > num[i])
            {
                minimum = num[i];
            }
        }
    }
    else if (select == MAXIMUM)
    {
        maximum = num[0];
        for (int i = 1; i < N; i++)
        {
            if (maximum < num[i])
            {
                maximum = num[i];
            }
        }
    }
    pthread_exit(0);
}

int main()
{
    // 3개의 thread를 만들어서 실행할 것이므로 배열로 선언해준다.
    pthread_t tid[3];
    pthread_attr_t attr[3];

    printf("입력할 숫자 개수:");
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_attr_init(&attr[i]);
    }

    int param[3] = {0};
    void *ptr;

    for (int i = 0; i < 3; i++)
    {
        param[i] = i;
        ptr = &param[i];
        pthread_create(&tid[i], &attr[i], runner, ptr);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(tid[i], NULL);
    }

    printf("The average value is %d\n", average);
    printf("The minimum value is %d\n", minimum);
    printf("The maximum value is %d\n", maximum);

    // 90 81 78 95 79 72 85
}
