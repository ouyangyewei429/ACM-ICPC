#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define onlinejudge

const int MAX_VER = 101;
const int MAX_EDGE = 10001;
const int INF = 0x3F3F3F3F;

int a, b, c, nNum, mNum;
int g[MAX_VER][MAX_VER];
int vis[MAX_VER], dist[MAX_VER];

int Dijkstra()
{
    int minValue, vex;
    
    for (int i=1; i<=nNum; ++i)
        dist[i] = g[1][i];
    
    vis[1] = 1, dist[1] = 0;;
    for (int i=1; i<=nNum; ++i)
    {
        minValue = INF;
        for (int j=1; j<=nNum; ++j)
        {
            if (!vis[j] && minValue>dist[j])
            {
                vex = j;
                minValue = dist[j];
            }
        }/* End of for */
        
        vis[vex] = 1;
        for (int j=1; j<=nNum; ++j)
        {
            if (!vis[j] && dist[j]>dist[vex]+g[vex][j])
                dist[j] = dist[vex]+g[vex][j];
        }/* End of for */
    }/* End of For */
    
    return dist[nNum];
}/* Dijkstra */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj2544.txt", "r", stdin);
    freopen("E:\\hdoj2544(result).txt", "w", stdout);
#endif

    while (~scanf("%d %d", &nNum, &mNum), nNum+mNum!=0)
    {
        memset(g, INF, sizeof(g));
        memset(vis, 0, sizeof(vis));
        memset(dist, INF, sizeof(dist));
        
        for (int i=1; i<=mNum; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            g[a][b] = g[b][a] = c;
        }/* End of For */
        
        printf("%d\n", Dijkstra());
    }/* End of While */
    
    return 0;
}
