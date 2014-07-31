/*
PROG:   畅通工程续
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <memory.h>

const int maxn = 204;
const int INF = 0x3F3F3F3F;

int N, M, a, b, x, ss, tt;
int hash[maxn], dist[maxn], graph[maxn][maxn];

void Dijkstra(int st)
{
    for (int i=0; i<N; ++i)
        dist[i] = graph[st][i];
        
    dist[st]=0, hash[st]=true;
    for (int i=0; i<N; ++i)
    {
        int u, minValue=INF;
        for (int j=0; j<N; ++j)
        {
            if (!hash[j] && minValue>dist[j])
                u=j, minValue=dist[j];
        }// Find the minValue
        
        hash[u] = true;
        for (int j=0; j<N; ++j)
        {
            if (!hash[j] && dist[j]>dist[u]+graph[u][j])
                dist[j] = dist[u]+graph[u][j];
        }
    }// End of for
    
    if (dist[tt] == INF)
        printf("-1\n");
    else
        printf("%d\n", dist[tt]);
    
    return ;
}// Dijkstra

int main()
{
    while (~scanf("%d %d", &N, &M))
    {
        memset(graph, INF, sizeof(graph));
        for (int i=0; i<N; ++i)
        {
            scanf("%d %d %d", &a, &b, &x);
            graph[a][b] = graph[b][a] = x;
        }// Input
        
        scanf("%d %d", &ss, &tt);
        Dijkstra(ss);
    }/* End of While */
    
    return 0;
}
