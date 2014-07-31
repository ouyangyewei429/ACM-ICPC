#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

#define MAX 200
#define INF 0x3F3F3F3F

int k, nNum, sNum, tNum, kNum;
int dist[MAX+5], mat[MAX+5][MAX+5], vis[MAX+5];

int Min(int x, int y)
{
    return (x<y ? x:y);
}/* Min */

int Dijkstra(int start, int end)
{
    int i, u, mindis;
    
    vis[start] = 1;  /* visited */
    dist[start] = 0; /* from start to start */
    while (start != end)
    {   /* loop until reach the last vertex */
        mindis = INF;
        for (i=1; i<=nNum; ++i)
        {
            if (mat[start][i] != INF)
            {
                dist[i] = Min(dist[i], dist[start]+mat[start][i]);
            }
            if (!vis[i] && mindis>dist[i])
            {
                u = i, mindis = dist[i];
            }
        }/* End of For */
     
        if (mindis != INF)
        {
            start = u;  /* next start is vertex u */
            vis[u] = 1; /* vertex is added in set */
        }
        else
        {   /* It means no vertexs in graph are conneted to start */
            break;
        }
    }/* End of While */
    
    if (dist[end] == INF)
    {   /* It means vertex(start) cannot connected to vertex(end) */
        return -1;
    }
    
    return dist[end];
}/* Dijkstra */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1548.txt", "r", stdin);
    freopen("E:\\hdoj1548(result).txt", "w", stdout);
#endif

    while (~scanf("%d", &nNum), nNum)
    {
        /* Initialize the array*/
        memset(dist, INF, sizeof(dist));
        memset(mat, INF, sizeof(mat));
        memset(vis, 0, sizeof(vis));
        
        scanf("%d %d", &sNum, &tNum);
        
        /* Creat a digraph */
        for (k=1; k<=nNum; ++k)
        {
            scanf("%d", &kNum);
            if (k+kNum <= nNum)
            {
                mat[k][k+kNum] = 1;
            }
            if (k-kNum >= 1)
            {
                mat[k][k-kNum] = 1;
            }
        }/* End of For */
        
        printf("%d\n", Dijkstra(sNum, tNum));
    }/* End of While */
    
    return 0;
}
