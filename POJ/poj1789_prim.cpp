#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlinejudge

#define maxn 2004
#define INF 0x3F3F3F3F

char code[maxn][8];
int  i, j, k, dist, nNum;
int  lowcost[maxn], vis[maxn], graph[maxn][maxn];

int prim()
{
    int minValue, v, result=0;
    
    for (i=0; i<nNum; ++i)
        lowcost[i] = graph[0][i];
    
    vis[0] = 1;
    for (i=1; i<nNum; ++i)
    {
        minValue = INF;
        for (j=0; j<nNum; ++j)
        {
            if (!vis[j] && lowcost[j]<minValue)
            {
                v = j;
                minValue = lowcost[j];
            }
        }/* End of for */
        
        vis[v] = 1;
        result += minValue;
        for (k=0; k<nNum; ++k)
        {
            if (!vis[k] && lowcost[k]>graph[v][k])
                lowcost[k] = graph[v][k];
        }
    }/* End of For */
    
    return result;
}/* prim */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj1789.txt", "r", stdin);
    freopen("E:\\poj1789(result).txt", "w", stdout);
#endif

    while (~scanf("%d", &nNum), nNum!=0)
    {
        memset(vis, 0, sizeof(vis));
        memset(code, 0, sizeof(code));
        memset(graph, 0, sizeof(graph));
        memset(lowcost, 0, sizeof(lowcost));
        
        for (i=0; i<nNum; ++i)
            scanf("%s", code[i]);
        
        for (i=0; i<nNum; ++i)
        {
            for (j=i+1; j<nNum; ++j)
            {
                dist = 0;
                for (k=0; k<7; ++k)
                {
                    if (code[i][k] != code[j][k])
                        ++dist;
                }
                
                graph[i][j] = graph[j][i] = dist;
            }
        }/* End of For */
        
        printf("The highest possible quality is 1/%d.\n", prim());
    }/* End of While */
    
    return 0;
}
