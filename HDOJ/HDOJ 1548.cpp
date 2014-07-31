#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define INF 300
//#define onlinejudge

int k, nNum, sNum, tNum, kNum, ans;
int vis[210], mat[210][210], dist[210];

int Dijkstra()
{
    int mindis, i, j, u;
    
    for (i=1; i<=nNum; ++i)
    {
        vis[i] = 0;
        dist[i] = mat[sNum][i];
    }/* End of For */
    
    vis[sNum] = 1;
    for (i=1; i<=nNum; ++i)
    {
        mindis = INF;
        for (j=1; j<=nNum; ++j)
        {
            if (!vis[j] && dist[j]<mindis)
            {
                u = j;
                mindis = dist[j];
            }
        }/* End of for */
        
        vis[u] = 1;
        for (j=1; j<=nNum; ++j)
        {
            if (!vis[j] && dist[u]+mat[u][j]<dist[j])
            {
                dist[j] = dist[u] + mat[u][j];
            }
        }/* End of for */
    }/* End of For */
    
    if (vis[tNum])
    {
        return dist[tNum];
    }
    else
    {
        return 0;
    }
}/* Dijkstra */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1548.txt", "r", stdin);
    freopen("E:\\hdoj1548(result).txt", "w", stdout);
#endif

    while (~scanf("%d", &nNum), nNum)
    {
        memset(mat, INF, sizeof(mat));
        
        scanf("%d %d", &sNum, &tNum);
            
        /* Creat a digraph */
        for (k=1; k<=nNum; ++k)
        {
            scanf("%d", &kNum);
                
            mat[k][k] = 0;
            if (k+kNum <= nNum)
            {
                mat[k][k+kNum] = 1;
            }
            if (k-kNum >= 1)
            {
                mat[k][k-kNum] = 1;
            }
        }/* End of For */
        
        if (sNum == tNum)
        {
            printf("0\n");
        }
        else
        {
            memset(vis, 0, sizeof(vis));
            memset(dist, 0, sizeof(dist));
            
            ans = Dijkstra();
            if (ans)
            {
                printf("%d\n", ans);
            }
            else
            {
                printf("-1\n");
            }
        }    
    }/* End of While */
    
    return 0;
}
