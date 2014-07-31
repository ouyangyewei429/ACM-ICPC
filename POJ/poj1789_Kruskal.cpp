#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define onlinejudge

const int maxn = 2004;

char graph[maxn][10];
int  i, j, k, dist, cnt, nNum, parent[maxn];
struct Graph
{
    int u, v, w;
}edge[1999000];

int compare(const void *a, const void *b)
{
    return (*(Graph *)a).w - (*(Graph *)b).w;
}/* compare */

int FindSet(int k)
{
    while (-1 != parent[k])
        k = parent[k];
    
    return k;
}/* FindSet */

int Merge(int x, int y)
{
    int r1 = FindSet(x);
    int r2 = FindSet(y);
    
    if (r1 == r2)
        return 0;
    
    if (r1 < r2)
        parent[r2] = r1;
    else
        parent[r1] = r2;
    
    return 1;
}/* Merge */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj1789.txt", "r", stdin);
    freopen("E:\\poj1789(result).txt", "w", stdout);
#endif

    while (~scanf("%d", &nNum), nNum)
    {
        memset(edge, 0, sizeof(edge));
        memset(graph, 0, sizeof(graph));
        memset(parent, -1, sizeof(parent));
        
        for (i=0; i<nNum; ++i)
            scanf("%s", graph[i]);
                
        cnt = 0;
        for (i=0; i<nNum; ++i)
        {
            for (j=i+1; j<nNum; ++j)
            {
                dist = 0;
                for (k=0; k<7; ++k)
                {
                    if (graph[i][k] != graph[j][k])
                        ++dist;
                }
                               
                edge[cnt].u=i, edge[cnt].v=j, edge[cnt].w=dist;
                ++cnt;
            }
        }/* End of For */
        
        qsort(edge, cnt, sizeof(edge[0]), compare);
        
        int lowcost=0, edgeNum=0;
        for (i=0; i<cnt; ++i)
        {
            if (Merge(edge[i].u, edge[i].v))
            {
                ++edgeNum;
                lowcost += edge[i].w;
            }
        }/* End of For */
        
        printf("The highest possible quality is 1/%d.\n", lowcost);
    }/* End of While */
    
    return 0;
}
