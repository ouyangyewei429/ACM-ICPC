#include <stdio.h>
#include <memory.h>

#define onlinejudge

const int maxn = 40;

bool hash[maxn];
int  N, K, stand[10];
int  dist[maxn], graph[maxn][maxn];

void dijkstra()
{
    int u, minValue;
    
    for (int i=0; i<N; ++i)
        dist[i] = graph[0][i];
    
    dist[0]=0, hash[0]=true;
    for (int i=0; i<N; ++i)
    {
        minValue = 0x3F3F3F3F;
        for (int j=0; j<N; ++j)
        {
            if (!hash[j] && minValue>dist[j])
                u=j, minValue=dist[j];
        }/* End of For */
        
        hash[u] = true;
        for (int j=0; j<N; ++j)
        {
            if (!hash[j] && (dist[j]>dist[u]+graph[u][j]))
                dist[j] = dist[u] + graph[u][j];
        }
    }/* End of For */
}

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1572.txt", "r", stdin);
    freopen("E:\\hdoj_1572_ans.txt", "w", stdout);
#endif

    while (~scanf("%d", &N), N!=0)
    {
        for (int i=0; i<N; ++i)
        {
            hash[i] = false;
            for (int j=0; j<N; ++j)
                scanf("%d", &graph[i][j]);
        }/* End of For */
        
        scanf("%d", &K);
        for (int i=0; i<K; ++i)
            scanf("%d", &stand[i]);
        
        dijkstra();
        
        int ans = 0;
        for (int i=0; i<K; ++i)
            ans += dist[i];
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
