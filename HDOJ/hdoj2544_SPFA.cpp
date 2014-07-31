#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 101;
const int INF = 0x3F3F3F3F;

int a, b, c, nNum, mNum;
int g[maxn][maxn], QM[maxn], dist[maxn];

int SPFA()
{
    int x;
    queue <int> q;
    
    q.push(1);
    QM[1] = 1, dist[1] = 0;
    
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        QM[x] = 0; /* Took Away*/
        
        for (int i=1; i<=nNum; ++i)
        {
            if (dist[i] > dist[x]+g[x][i])
            {
                dist[i] = dist[x] + g[x][i]; /* change the weight */
                
                /* push into queue if vertex i is QM of queue */
                if (QM[i] == 0)
                {
                    QM[i] = 1;
                    q.push(i);
                }
            }    
        }/* End of For */
    }/* End of While */
    
    return dist[nNum];
}/* SPFA */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj2544.txt", "r", stdin);
    freopen("E:\\hdoj2544(result).txt", "w", stdout);
#endif

    while (~scanf("%d %d", &nNum, &mNum), nNum+mNum!=0)
    {
        memset(g, INF, sizeof(g));
        memset(QM, 0, sizeof(QM));
        memset(dist, INF, sizeof(dist));
        
        for (int i=1; i<=mNum; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            g[a][b] = g[b][a] = c; /* Adjcent Matrix */
        }/* End of For */
        
        printf("%d\n", SPFA());    /* Solve with spfa algorithm */
    }/* End of While */
    
    return 0;
}
