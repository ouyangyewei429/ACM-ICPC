#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 2010;
char graph[maxn][maxn];
int  nNum, dist, mat[maxn];
struct Graph
{
    int u, v, w;
}edge[maxn+maxn];

int compare(const void *a, const void *b)
{
    return (*(Graph *)a).w - (*(Graph *)b).w;
}/* compare */

int FindSet(int k)
{
    while (-1 != mat[k])
        k = mat[k];
    
    return k;
}/* FindSet */

int Merge(int x, int y)
{
    int r1 = FindSet(x);
    int r2 = FindSet(y);
    
    if (r1 == r2)
        return 0;
    
    if (r1 < r2)
        mat[r2] = r1;
    else
        mat[r1] = r2;
    
    return 1;
}/* Merge */

int main()
{
    while (~scanf("%d", &nNum), nNum!=0)
    {
        memset(mat, -1, sizeof(mat));
        memset(edge, 0, sizeof(edge));
        memset(graph, 0, sizeof(graph));
        
        for (int i=0; i<nNum; ++i)
            scanf("%s", graph[i]);
        
        int i, j, cnt = 0;
        for (i=0; i<nNum; ++i)
        {
            for (j=i+1; j<nNum; ++j)
            {
                dist = 0;
                for (int k=0; k<nNum; ++k)
                {
                    if (graph[i][k] != graph[j][k])
                        ++dist;
                }
            }
            
            edge[cnt].u=i, edge[cnt].v=j, edge[cnt].w=dist;
            ++cnt;
            edge[cnt].u=j, edge[cnt].v=i, edge[cnt].w=dist;
            ++cnt;
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
            if (edgeNum == nNum-1)
                break;
        }
        if (edgeNum == nNum-1)
            printf("The highest possible quality is 1/%d.\n", lowcost);
    }/* End of While */
    
    return 0;
}
