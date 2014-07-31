#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 1001;
const int INF = 0x3F3F3F3F;

int a, b, d, p, nNum, mNum;
int dist[maxn], px[maxn], QM[maxn];
int cost[maxn][maxn], g[maxn][maxn];

void spfa(int sx, int tx)
{
    int   xx;
    queue <int> q;
    
    q.push(sx);
    QM[sx]=1, dist[sx]=0, px[sx]=0;
    
    while (!q.empty())
    {
        xx = q.front();
        q.pop();
        QM[xx] = 0; /* Took Away */
        
        for (int i=1; i<=nNum; ++i)
        {
            if (dist[i] > dist[xx]+g[xx][i])
            {
                dist[i] = dist[xx] + g[xx][i];
                px[i] = px[xx] + cost[xx][i];
                
                if (QM[i] == 0)
                {
                    QM[i] = 1;
                    q.push(i);
                }
            }/* End of if */
            else if (dist[i]==dist[xx]+g[xx][i]
                    && px[i]>px[xx]+cost[xx][i])
            {
                px[i] = px[xx] + cost[xx][i];
            }
        }/* End of For */
    }/* End of While */
    
    printf("%d %d\n", dist[tx], px[tx]);
}/* spfa */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj3790.txt", "r", stdin);
    freopen("E:\\hdoj3790(result).txt", "w", stdout);
#endif

    while (~scanf("%d %d", &nNum, &mNum), nNum+mNum!=0)
    {        
        for (int i=1; i<=nNum; ++i)
        {
            QM[i] = 0;
            px[i] = dist[i] = INF;
            
            for (int j=1; j<=nNum; ++j)
                g[i][j] = cost[i][j] = INF;
        }/* End of For */
        
        for (int i=1; i<=mNum; ++i)
        {
            scanf("%d %d %d %d", &a, &b, &d, &p);
            
            if (d < g[a][b])  /* Хажи */ 
            {
                g[a][b] = g[b][a] = d;
                cost[a][b] = cost[b][a] = p;
            }    
        }/* End of For */
        
        int sx, tx;
        
        scanf("%d %d", &sx, &tx);
        spfa(sx, tx);
    }/* End of While */
    
    return 0;
}
