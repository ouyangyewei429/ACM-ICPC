#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlineJudge

int rank[110] = {0};
int parent[110] = {0};
int nNum, sn1, sn2;
int i, cnt, cost, edge;
struct tree
{
    int u;
    int v;
    int w;
}graph[5050];

int compare(const void *a, const void *b)
{
    return (*(tree *)a).w - (*(tree *)b).w;
}/* compare */

int FindSet(int k)
{
    while (k != parent[k])
    {
        k = parent[k];
    }
    
    return k;
}/* FindSet */

int Merge(int x, int y)
{
    x = FindSet(x);
    y = FindSet(y);
    if (x == y)
    {
        return 0;
    }
    
    if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else
    {
        if (rank[x] == rank[y])
        {
            ++rank[y];
        }
        parent[x] = y;
    }
    
    return 1;
}/* Merge */

int main()
{
#ifdef onlineJudge
    freopen("E:\\hdoj1233.txt", "r", stdin);
    freopen("E:\\hdoj1233(result).txt", "w", stdout);
#endif

    while (1==scanf("%d", &nNum), nNum)
    {
        memset(graph, 0, sizeof(graph));
        
        cnt = nNum*(nNum-1)/2;
        for (i=0; i<cnt; ++i)
        {
            scanf("%d %d %d", &graph[i].u, &graph[i].v, &graph[i].w);
        }/* End of For */
        
        /* Make Set */
        for (i=1; i<=nNum; ++i)
        {
            rank[i] = 0;
            parent[i] = i;
        }/* End of For */
        
        qsort(graph, cnt, sizeof(graph[0]), compare);
        
        edge = cost = 0;
        for (i=0; i<cnt; ++i)
        {
            if (Merge(graph[i].u, graph[i].v))
            {
                ++edge;
                cost += graph[i].w;
            }
            if (edge == nNum-1)
            {
                break;
            }
        }/* End of For */
        
        printf("%d\n", cost);
    }/* End of While */
    
    return 0;
}
