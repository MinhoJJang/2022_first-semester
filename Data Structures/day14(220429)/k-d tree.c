#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_DIM 3 // 최대 차원 수. 현실적으로 3차원까지만 표현할 수 있다.
struct kd_node_t
{
    double x[MAX_DIM]; // x는 좌표값. x[0] = x, x[1] = y, x[2] = z 이다. 만약 2차원이라면 x[2] = 0 으로 고정값일 것이다.
    struct kd_node_t *left;
    struct kd_node_t *right;
    // 점을 기준으로 선을 그어 나눌 때 나눠지는 두 영역에서 선택한 각각의 중앙값을 의미한다.
};

// 점과 점 사이 거리를 계산하는 함수
double dist(struct kd_node_t *a, struct kd_node_t *b, int dim)
{
    double t, d = 0;
    while (dim--)
    {
        t = a->x[dim] - b->x[dim];
        d += t * t;
        // d = x^2 + y^2 가 저장된다. 즉, 이 값을 sqrt 시키면 거리 distance 가 나오게 된다.
    }
    return d;
}

// x와 y를 서로 스왑하는 함수이다.
void swap(struct kd_node_t *x, struct kd_node_t *y)
{
    double tmp[MAX_DIM];
    memcpy(tmp, x->x, sizeof(tmp));
    memcpy(x->x, y->x, sizeof(tmp));
    memcpy(y->x, tmp, sizeof(tmp));
}

/* see quickselect method */
// start 점부터 end 점 중에서 중앙값을 찾아 중앙에 위치한 점의 정보를 리턴하는 함수이다. 그래서 타입이 struct kd_node_t 타입이다.
// 여기서 idx는 어떤 축을 기준으로 start와 end를 나눌 것인지 알려주는, 정수값이다.
struct kd_node_t *find_median(struct kd_node_t *start, struct kd_node_t *end, int idx)
{

    if (end <= start)
    {
        return NULL;
    }
    if (end == start + 1)
    {
        return start;
        // 점이 start, end 두개일 경우 smaller median을 선택한다.
    }

    struct kd_node_t *p, *store;
    struct kd_node_t *md = start + (end - start) / 2; // start와 end 중앙에 위치한 점이다.
    double pivot;

    while (1)
    {
        pivot = md->x[idx]; // 피벗을, 중앙값의 기준값으로 정한다.

        swap(md, end - 1);
        for (store = p = start; p < end; p++)
        {
            if (p->x[idx] < pivot)
            {
                if (p != store)
                    swap(p, store);
                store++;
            }
        }
        swap(store, end - 1);

        /* median has duplicate values */
        if (store->x[idx] == md->x[idx])
            return md;

        if (store > md)
            end = store;
        else
            start = store;
    }
}

// 여기서 *t 는 시작점, len은 총 점의 개수, i는 어떤 축을 기준으로 하는지, dim은 몇 차원의 점을 가지고 tree를 만드는지.
struct kd_node_t *make_tree(struct kd_node_t *t, int len, int i, int dim)
{
    struct kd_node_t *n;

    if (!len)
        return 0;
    // len이 0이면 그냥 0을 리턴한다.
    // C에서 false 값은 0, true 값은 0이 아닌 모든 값이다. 출력으로 나타낼 때는 1로 표현한다.

    if ((n = find_median(t, t + len, i))) // 대입연산자의 결과값은 그 값 자체이다. 그러니까 n이 0이 되지 않는 이상 참이어서 if문 내부를 실행한다.
    {
        i = (i + 1) % dim; // 2차원이면 x,y만 반복해서 기준삼아 나누면 되니까 이런식으로 i를 0,1 번갈아가게 할 수 있도록 해준다.
        n->left = make_tree(t, n - t, i, dim);
        n->right = make_tree(n + 1, t + len - (n + 1), i, dim);
        // 중앙값을 찾았으면, 그건 곧 트리에 들어갈 공간 하나를 찾았다는 의미이며 그 중앙값을 기준으로 나뉘어진 것들을 다시 정리하고 그것들 중에서 다시 중앙값을 찾아 트리에 넣어야 한다. 이걸 재귀적으로 수행시키면 된다.
    }
    return n;
}

/* global variable, so sue me */
int visited;

void nearest(struct kd_node_t *root, struct kd_node_t *nd, int i, int dim, struct kd_node_t **best, double *best_dist)
{
    double d, dx, dx2;

    if (!root)
        return;
    d = dist(root, nd, dim);    //
    dx = root->x[i] - nd->x[i]; // 단순 거리. i에 따라 어떤 축의 길이인지..
    dx2 = dx * dx;

    visited++;

    if (!*best || d < *best_dist)
    {
        *best_dist = d;
        *best = root;
    }

    /* if chance of exact match is high */
    if (!*best_dist)
        return;

    if (++i >= dim)
        i = 0;

    nearest(dx > 0 ? root->left : root->right, nd, i, dim, best, best_dist);
    if (dx2 >= *best_dist)
        return;
    nearest(dx > 0 ? root->right : root->left, nd, i, dim, best, best_dist);
}

void rangeSearch()
{
}

int main()
{
    int i;
    struct kd_node_t wp[] = {{{2, 3}}, {{5, 4}}, {{9, 6}}, {{4, 7}}, {{8, 1}}, {{7, 2}}};
    struct kd_node_t testNode = {{4, 4}};
    struct kd_node_t *root, *found, *million;
    double best_dist;

    root = make_tree(wp, sizeof(wp) / sizeof(wp[1]), 0, 2);

    visited = 0;
    found = 0;
    nearest(root, &testNode, 0, 2, &found, &best_dist);

    printf(">> WP tree\nsearching for (%g, %g)\n"
           "found (%g, %g) dist %g\nseen %d nodes\n\n",
           testNode.x[0], testNode.x[1], found->x[0], found->x[1], sqrt(best_dist), visited);

    return 0;
}
