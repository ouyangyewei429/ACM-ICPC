#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 1001;
const int INF = 0x3F3F3F3F;

int QM[maxn], dist[maxn], pn[maxn<<1];
int g[maxn][maxn], cost[maxn][maxn];
int a, b, d, p, sx, tx, nNum, mNum;

int spfa()
{
    int   x;
    queue <int> q;

    q.push(1);
    dist[1]=0, QM[1]=1;
    
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        QM[x] = 0; /* Took Away */

        for (int i=1; i<=nNum; ++i)
        {
            if (dist[i] > dist[x]+g[x][i])
            {
                dist[i] = dist[x] + g[x][i];
                
                if (QM[i] == 0)
                {
                    QM[i] = 1;
                    q.push(i);
                }
            }/* End of IF */
        }/* End of For */
    }/* End of While */

    return dist[tx];
}/* spfa */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj3790.txt", "r", stdin);
    freopen("E:\\hdoj3790(result).txt", "w", stdout);
#endif

    while (~scanf("%d %d", &nNum, &mNum), nNum+mNum!=0)
    {
        memset(QM, 0, sizeof(QM));
        memset(g, INF, sizeof(g));
        memset(dist, INF, sizeof(INF));
        
        for (int i=1; i<=mNum; ++i)
        {
            scanf("%d %d %d %d", &a, &b, &d, &p);
            
            g[a][b] = g[b][a] = d;
        }/* End of For */
        
        scanf("%d %d", &sx, &tx);
        
        printf("%d\n", spfa());
    }/* End of While */
    
    return 0;
}
