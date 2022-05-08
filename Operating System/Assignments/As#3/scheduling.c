#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200
#define EXIST 1
#define NOTEXIST 0
#define DECIMAL 10

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
    // 먼저, 유저가 입력하는 값들을 정제하여 사용 할 수 있는 데이터로 가공하는 작업을 해준다.

    // 1. dat 파일 가공

    FILE *openFile = fopen(argv[1], "r");
    // FILE *writeFile = fopen(argv[2], "w");
    int user_data[MAX] = {0};
    int user_idx = 1; // user_data 배열의 idx를 나타내는 변수

    if (openFile == 0)
    {
        printf("Could not open file\n");
    }
    else
    {
        int x;
        int input[MAX];
        int idx = 0;
        // while ((x = fgetc(openFile)) != EOF)
        // {
        //     input[idx++] = x;
        //     printf("%c", x);
        // }

        // input[0] = 1;
        // input[2] = 3;
        // input[3] = 4;

        // input[5] = 1;
        // input[6] = 0;

        // user_data 배열에 데이터를 넣자. user_data[1] = 1, user_data[2] = 50, 이런식으로 넣자는 것. 그렇게 하기 위해서는 공백판별도 해야 하고 자리수 계산도 해야 하며 자료형 역시 atoi를 통해 바꿔주어야 한다.

        int flag = NOTEXIST; // EXIST, NOTEXIST 구별용

        while ((x = fgetc(openFile)) != EOF)
        {
            if (strcmp(x, " ") != 0)
            {
                int data = atoi(x);
                if (flag == EXIST)
                {
                    user_data[user_idx] = user_data[user_idx] * DECIMAL + data;
                    flag = EXIST;
                }
                else
                {
                    user_data[user_idx] = data;
                    if (data == 0)
                    {
                        flag = NOTEXIST;
                    }
                    flag = EXIST;
                }
            }
            else
            {
                // 만약 NULL을 만나면, user_idx을 1 올려주고 flag = NOTEXIST로 변경해준다.
                printf("%d", user_data[user_idx]);
                user_idx++;
                flag = NOTEXIST;
            }
        }

        fclose(openFile);
    }

    // 데이터 들어오는지 확인
    printf("argv[2] 값은? : %s\n", argv[2]);
    int t = atoi(argv[3]);
    printf("argv[3] 값은? : %d\n", t);
}