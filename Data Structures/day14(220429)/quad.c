#include <math.h>
#include <time.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
/*
    quad tree 만들기

    주어진 범위 내에 점이 주어질 것이다.
    범위는 사분면 중 1사분면이고, x, y값은 1부터 20까지의 양수이며 맵의 크기는 21x21이다.

    region quad tree이므로 기준점에서 4분할 하는것만 완료하면 나머지는 재귀적으로 처리하면 된다.
*/

#define MAP_SIZE 21
#define NODATA 0
#define NO 0
#define YES 1

// 점을 저장하기 위한 구조체
typedef struct _Point
{
    int x;
    int y;
} Point;

// 사각형을 표현하는 구조체
typedef struct _Map
{
    Point *top_right;
    Point *bottom_left;
    Point *center; // 사각형의 중앙점
    Point *point;  // 사각형 내부에 점이 1개일 경우 지정한다.
} Map;

// 트리를 표현하는 구조체
typedef struct _Tree
{
    Map *map;
    struct _Tree *top_left;
    struct _Tree *top_right;
    struct _Tree *bottom_left;
    struct _Tree *bottom_right;
} Tree;

Point *init_point(int x, int y)
{
    Point *point = (Point *)malloc(sizeof(Point));
    point->x = x;
    point->y = y;

    return point;
}

// map을 초기화하는 함수. 점 두개가 주어지면 map을 설정해준다.
Map *init_map(int x1, int y1, int x2, int y2)
{
    Map *newmap = (Map *)malloc(sizeof(Map));

    newmap->bottom_left = init_point(x1, y1);
    newmap->top_right = init_point(x2, y2);
    newmap->center = init_point((x1 + x2) / 2, (y1 + y2) / 2);
    newmap->point = NULL;

    return newmap;
}

void tree_init(Tree *tree)
{

    tree->map = init_map(0, 0, MAP_SIZE, MAP_SIZE);
    tree->bottom_left = NULL;
    tree->bottom_right = NULL;
    tree->top_left = NULL;
    tree->top_right = NULL;

    return;
}

#define TR 0
#define TL 1
#define BL 2
#define BR 3
#define MAX 400

int numberOfPrinted = 1;

// 해당 MAP 안에 몇개의 점이 존재하는지 파악하는 함수. 점이 1개일 경우 분열하지 않고, 점이 2개 이상일 경우 분열한다. 만약 0개면 아무것도 하지 않으면 된다.
void checkPoints(Tree *tree, Point data[])
{
    int numberOfPoints = _msize(data) / sizeof(Point);
    // printf("numberOfPoints : %d\n", numberOfPoints);

    // map 내부에 점이 0개일 경우
    if (numberOfPoints == NODATA)
    {
        tree = NULL;
        return;
    }
    else if (numberOfPoints == 1) // 점이 1개인 경우 더이상의 탐색은 종료하며 tree에 데이터를 넣는다.
    {
        Point *point = (Point *)malloc(sizeof(Point));
        tree->map->point = point;
        tree->map->point->x = data[0].x;
        tree->map->point->y = data[0].y;

        printf("%d point -> x: %d, y: %d\n", numberOfPrinted++, tree->map->point->x, tree->map->point->y);
    }
    else if (numberOfPoints > 1)
    {
        // map 안에 포인트가 2개 이상일 경우 tree의 map을 4등분 한 후 각 map에 대해서 다시 checkPoints를 실행한다. 이때, map 내부 Point배열 역시 4등분하여 각각의 배열을 만들어야 한다.

        // 각 점마다 사분면 중 어느 부분에 해당하는지 찾고, 그 해당하는 map의 data 배열에 넣어준다.
        // Point *bottom_left = (Point *)malloc(sizeof(Point) * numberOfBL);
        // #define TR 0
        // #define TL 1
        // #define BL 2
        // #define BR 3

        Point restructData[4][MAX] = {0};
        Point *map_data[4];
        Tree *newTree[4];
        int numberOf[4] = {0};

        for (int i = 0; i < numberOfPoints; i++)
        {
            int x = data[i].x;
            int y = data[i].y;
            int location;
            if (tree->map->bottom_left->x <= x && x < tree->map->center->x && tree->map->bottom_left->y <= y && y < tree->map->center->y)
            {
                location = BL;
            }
            else if (tree->map->center->x <= x && x < tree->map->top_right->x && tree->map->center->y <= y && y < tree->map->top_right->y)
            {
                location = TR;
            }
            else if (tree->map->center->x <= x && x < tree->map->top_right->x && tree->map->bottom_left->y <= y && y < tree->map->center->y)
            {
                location = BR;
            }
            else
            {
                location = TL;
            }

            restructData[location][numberOf[location]].x = x;
            restructData[location][numberOf[location]].y = y;
            numberOf[location]++;
        }

        for (int i = 0; i < 4; i++)
        {
            map_data[i] = (Point *)malloc(sizeof(Point) * numberOf[i]);
            newTree[i] = (Tree *)malloc(sizeof(Tree));
            for (int j = 0; j < numberOf[i]; j++)
            {
                map_data[i][j].x = restructData[i][j].x;
                map_data[i][j].y = restructData[i][j].y;
            }
        }

        if (numberOf[TR] > 0)
        {
            tree->top_right = newTree[TR];
            tree->top_right->map = init_map(tree->map->center->x, tree->map->center->y, tree->map->top_right->x, tree->map->top_right->y);
            checkPoints(tree->top_right, map_data[TR]);
        }

        if (numberOf[TL] > 0)
        {
            tree->top_left = newTree[TL];
            tree->top_left->map = init_map(tree->map->bottom_left->x, tree->map->center->y, tree->map->center->x, tree->map->top_right->y);
            checkPoints(tree->top_left, map_data[TL]);
        }

        if (numberOf[BL] > 0)
        {
            tree->bottom_left = newTree[BL];
            tree->bottom_left->map = init_map(tree->map->bottom_left->x, tree->map->bottom_left->y, tree->map->center->x, tree->map->center->y);
            checkPoints(tree->bottom_left, map_data[BL]);
        }

        if (numberOf[BR] > 0)
        {
            tree->bottom_right = newTree[BR];
            tree->bottom_right->map = init_map(tree->map->center->x, tree->map->bottom_left->y, tree->map->top_right->x, tree->map->center->y);

            checkPoints(tree->bottom_right, map_data[BR]);
        }
    }
    return;
}

void searchPoint(Tree *tree, Point *point)
{
    // root node 부터, node의 point 값이 존재할 경우 비교한다. 값이 없을 경우, map의 center 포인트를 기준으로 포인트의 위치를 1사분면부터 4사분면까지 잡는다. 그리고 그 사분면으로 이동하여 같은 로직을 수행한다. 만약 이동하는 사분면에 아무것도 존재하지 않는 NULL 상태인 경우 search fail 이다.

    // 해당 tree의 map에 point값이 존재하는가? 만약 값이 존재한다는 것은 그곳이 leaf 노드라는 뜻이고 여기서 못찾으면 그냥 search fail이다.
    if (tree->map->point != NULL)
    {
        // 이곳은 leaf node이며 quad tree 정의에 따라 이곳이 탐색의 마지막이다.
        if (tree->map->point->x == point->x && tree->map->point->y == point->y)
        {
            // search success
            printf("search success! point(%d, %d)\n", point->x, point->y);
        }
        else
        {
            // search fail
            printf("search fail\n");
        }
        return;
    }
    else
    {
        int center_x = tree->map->center->x;
        int center_y = tree->map->center->y;
        int x = point->x;
        int y = point->y;
        int isPointerNull = NO;

        if (center_x <= x && center_y <= y)
        {
            if (tree->top_right != NULL)
            {
                searchPoint(tree->top_right, point);
            }
            else
            {
                isPointerNull = YES;
            }
        }
        else if (x < center_x && center_y <= y)
        {
            if (tree->top_left != NULL)
            {
                searchPoint(tree->top_left, point);
            }
            else
            {
                isPointerNull = YES;
            }
        }
        else if (x < center_x && y < center_y)
        {
            if (tree->bottom_left != NULL)
            {
                searchPoint(tree->bottom_left, point);
            }
            else
            {
                isPointerNull = YES;
            }
        }
        else
        {
            if (tree->bottom_right != NULL)
            {
                searchPoint(tree->bottom_right, point);
            }
            else
            {
                isPointerNull = YES;
            }
        }

        if (isPointerNull == YES)
        {
            printf("search fail\n");
            return;
        }
    }
}

void CheckSameData(Point *point, int *idx, int *reset)
{
    int num = *idx;
    int x = point[num].x;
    int y = point[num].y;
    for (int i = 0; i < num; i++)
    {
        if (point[i].x == x && point[i].y == y)
        {
            *reset = YES;
            return;
        }
    }
}

int main()
{
    Tree tree;
    tree_init(&tree);

    int NumberOfPoint;
    printf("Total Number Of Point : ");
    scanf_s("%d", &NumberOfPoint);
    Point *input_data = (Point *)malloc(sizeof(Point) * NumberOfPoint); //동적할당

    srand(time(NULL));
    //값 임의지정
    for (int i = 0; i < NumberOfPoint; i++)
    {
        int reset = NO;
        input_data[i].x = rand() % 20 + 1;
        input_data[i].y = rand() % 20 + 1;

        CheckSameData(input_data, &i, &reset);
        if (reset == YES)
        {
            i--;
        }
    }

    // input_data[0].x = 3;
    // input_data[0].y = 3;

    // input_data[1].x = 15;
    // input_data[1].y = 3;

    for (int i = 0; i < NumberOfPoint; i++)
    {
        printf("data[%d].x : %d , data[%d].y = %d\n", i, input_data[i].x, i, input_data[i].y);
    }

    checkPoints(&tree, input_data);

    printf("===========Search Point Test============\n");
    int input_x;
    int input_y;
    printf("Which point do you want to search? : ");
    scanf_s("%d%d", &input_x, &input_y);
    printf("Search Point : (%d, %d)\n", input_x, input_y);
    Point *newPoint = (Point *)malloc(sizeof(Point));
    newPoint = init_point(input_x, input_y);
    searchPoint(&tree, newPoint);

    return 0;
}
