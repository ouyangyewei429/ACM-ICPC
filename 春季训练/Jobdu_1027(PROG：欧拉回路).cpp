/**
 * PROG: 欧拉回路
 */
#include <cstdio>
#include <memory.h>

const int MAX_SIZE = 1024;

int  g_nNodes;
int  g_nSides;
int  g_route[MAX_SIZE][MAX_SIZE];
bool g_visit[MAX_SIZE][MAX_SIZE];

/**
 * @origin:  起点
 * @current: 当前节点
 */
bool dfs(int origin, int current, int sides)
{
    if (origin==current && sides==g_nSides)
    {   // check if all sides were visited
        // printf("****%d*%d*%d***\n", origin, current, sides);
        return true;
    }

    for (int next=1; next<=g_nNodes; ++next)
    {
        if (0!=g_route[current][next] && !g_visit[current][next])
        {
            g_visit[current][next] = g_visit[next][current] = true;
            if (dfs(origin, next, ++sides))
            {
                return true;
            }
            g_visit[current][next] = g_visit[next][current] = false;
        }
    }
    return false;
}

int main(void)
{
    int node_a, node_b;

    while (~scanf("%d", &g_nNodes))
    {
        if (0 == g_nNodes)
        {
            break;
        }
        scanf("%d", &g_nSides);

        memset(g_route, 0, sizeof(g_route));
        for (int i=1; i<=g_nSides; ++i)
        {
            scanf("%d %d", &node_a, &node_b);
            g_route[node_a][node_b] = g_route[node_b][node_a] = 1;
        }

        bool isFind = false;
        for (int j=1; j<=g_nNodes; ++j)
        {
            memset(g_visit, false, sizeof(g_visit));
            if (dfs(j, j, 0))
            {
                isFind = true;
                printf("1\n");
                break;
            }
        }
        if (!isFind)
        {
            printf("0\n");
        }
    }

    return 0;
}
/*
4 5
1 2
1 4
2 4
2 3
3 4
*/
