/*
PROG:   spfa
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

//#define onlinejudge

const int maxn = 1004;
const int INF = 0x3F3F3F3F;

bool inq[maxn];
int  N, M, K, ss, tt, lowcost;
int  dist[maxn], edge[maxn][maxn];

void spfa(int src)
{
    int i, u;
    queue <int> q;
    
    for (int i=1; i<=N; ++i)
        dist[i]=INF, inq[i]=false;
    
    dist[src]=0, inq[src]=true;
    q.push(src);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        inq[u] = false;
        
        for (i=1; i<=N; ++i)
        {
            if (dist[u]+edge[u][i] < dist[i])
            {
                dist[i] = dist[u]+edge[u][i];
                if (!inq[i])
                    q.push(i), inq[i]=true;
            }
        }// end of for
    }// end of while
}// spfa

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2680.txt", "r", stdin);
    freopen("E:\\hdoj_2680_ans.txt", "w", stdout);
#endif

    int i, a, b, c;
    while (~scanf("%d %d %d", &N, &M, &tt))
    {
        memset(edge, INF, sizeof(edge));
        
        for (i=0; i<M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a][b] = c;
        }// end of for
        
        lowcost = INF;
        scanf("%d", &K);
        for (i=0; i<K; ++i)
        {
            scanf("%d", &ss);
            
            spfa( ss );
            if (dist[tt]<INF && lowcost>dist[tt])
                lowcost = dist[tt];
        }// end of for
        if (lowcost < INF)
            printf("%d\n", lowcost);
        else
            printf("-1\n");
    }// end of while
    
    return 0;
}
