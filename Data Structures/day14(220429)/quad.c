#include <math.h>
#include <time.h>
#include <malloc.h>
#include <stdio.h>
/*
    quad tree 만들기

    주어진 범위 내에 점이 주어질 것이다.
    범위는 사분면 중 1사분면이고, x, y값은 1부터 20까지의 양수이며 맵의 크기는 21x21이다.

    region quad tree이므로 기준점에서 4분할 하는것만 완료하면 나머지는 재귀적으로 처리하면 된다.
*/

#define MAP_SIZE 21
#define NODATA 0

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

    printf("%d", tree->map->center->x);

    return;
}

#define TR 0
#define TL 1
#define BL 2
#define BR 3
#define MAX 100

// 해당 MAP 안에 몇개의 점이 존재하는지 파악하는 함수. 점이 1개일 경우 분열하지 않고, 점이 2개 이상일 경우 분열한다. 만약 0개면 아무것도 하지 않으면 된다.
void checkPoints(Tree *tree, Point data[])
{
    int numberOfPoints = _msize(data) / sizeof(Point);
    // printf("numberOfPoints : %d\n", numberOfPoints);

    // map 내부에 점이 0개일 경우
    if (numberOfPoints == NODATA)
    {
        return;
    }
    else if (numberOfPoints == 1) // 점이 1개인 경우 더이상의 탐색은 종료하며 tree에 데이터를 넣는다.
    {
        Point *point = (Point *)malloc(sizeof(Point));
        tree->map->point = point;
        tree->map->point->x = data[0].x;
        tree->map->point->y = data[0].y;

        printf("x: %d, y: %d\n", tree->map->point->x, tree->map->point->y);
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

        tree->top_right = newTree[TR];
        tree->top_left = newTree[TL];
        tree->bottom_left = newTree[BL];
        tree->bottom_right = newTree[BR];

        tree->top_right->map = init_map(tree->map->center->x, tree->map->center->y, tree->map->top_right->x, tree->map->top_right->y);
        tree->top_left->map = init_map(tree->map->bottom_left->x, tree->map->center->y, tree->map->center->x, tree->map->top_right->y);
        tree->bottom_left->map = init_map(tree->map->bottom_left->x, tree->map->bottom_left->y, tree->map->center->x, tree->map->center->y);
        tree->bottom_right->map = init_map(tree->map->center->x, tree->map->bottom_left->y, tree->map->top_right->x, tree->map->center->y);

        checkPoints(tree->top_right, map_data[TR]);
        checkPoints(tree->top_left, map_data[TL]);
        checkPoints(tree->bottom_left, map_data[BL]);
        checkPoints(tree->bottom_right, map_data[BR]);
    }

    return;
}

void searchPoint(int x, int y)
{
    // TODO
}

int main()
{
    Tree tree;
    tree_init(&tree);

    int NumberOfPoint;
    printf("Total Number Of Point : ");
    scanf_s("%d", &NumberOfPoint);
    Point *input_data = (Point *)malloc(sizeof(Point) * NumberOfPoint); //동적할당

    // 값 임의지정
    for (int i = 0; i < NumberOfPoint; i++)
    {
        input_data[i].x = i + 3;
        input_data[i].y = i + 1;
    }

    for (int i = 0; i < NumberOfPoint; i++)
    {
        printf("data[%d].x : %d , data[%d].y = %d\n", i, input_data[i].x, i, input_data[i].y);
    }

    checkPoints(&tree, input_data);

    return 0;
}
