#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlinejudge

const int maxn = 2004;
const int INF = 0x7FFFFFF;

char graph[maxn][9];
int  i, j, k, dif, nNum, dist[maxn][maxn], vis[maxn], lowcost[maxn];

int prim()
{
    int v, minValue, result=0;
    
    for (i=0; i<nNum; ++i)
        lowcost[i] = dist[0][i];
    
    vis[0] = 1;
    for (i=0; i<nNum; ++i)
    {
        minValue = INF;
        for (j=0; j<nNum; ++j)
        {
            if (!vis[j] && lowcost[j]<minValue)
            {
                v = j;
                minValue = lowcost[j];
            } 
        }
        ///////////////////////////////////
        printf("#%d#\n", minValue);
        ///////////////////////////////////
        vis[v] = 1;
        result += minValue;
        for (j=0; j<nNum; ++j)
        {
            if (!vis[j] && lowcost[j]>dist[v][j])
                lowcost[j] = dist[v][j];
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

    while (~scanf("%d", &nNum), nNum)
    {
        memset(vis, 0, sizeof(vis));
        memset(graph, 0, sizeof(graph));
        memset(dist, INF, sizeof(dist));
        
        /*********
        for (i=0; i<nNum; ++i)
        {
            for (j=0; j<nNum; ++j)
                printf("%d\n", dist[i][j]);
        }
        **************/
        
        for (i=0; i<nNum; ++i)
            scanf("%s", graph[i]);
        
        /********************
        for (i=0; i<nNum; ++i)
            printf("%s\n", graph[i]);
        **********************/
            
        for (i=0; i<nNum; ++i)
        {
            for (j=i+1; j<nNum; ++j)
            {
                dif = 0;
                for (k=0; k<7; ++k)
                {
                    if (graph[i][k] != graph[j][k])
                        ++dif;
                }
                
                dist[i][j] = dist[j][i] = dif;
            }
        }/* End of For */
        
        int ans = prim();
        printf("The highest possible quality is 1/%d.\n", ans);
    }/* End of While */
    
    return 0;
}
