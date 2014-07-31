/*
PROG:   畅通工程续
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 1024;
const int INF = 0x3F3F3F3F;

bool hash[maxn];
int  N, M, a, b, c, ss, tt;
int  dist[maxn], graph[maxn][maxn];

void dijkstra()
{
    for (int i=0; i<N; ++i)
        dist[i] = graph[ss][i];
    dist[ss] = 0;
    
    hash[ss] = true;
    for (int i=0; i<N; ++i)
    {
        int u, minValue=INF;
        for (int j=0; j<N; ++j)
        {
            if (!hash[j] && minValue>dist[j])
                u=j, minValue=dist[j];
        }// Find the nearest node of ss
        
        hash[u] = true;
        for (int j=0; j<N; ++j)
        {
            if (!hash[j] && dist[j]>dist[u]+graph[u][j])
                dist[j] = dist[u]+graph[u][j];
        }// modify the node
    }// End of For
}// dijkstra

int main()
{
    while (~scanf("%d %d", &N, &M))
    {
        memset(graph, INF, sizeof(graph));
        for (int i=0; i<M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            graph[a][b] = graph[b][a] = c;
        }// input
        
        scanf("%d %d", &ss, &tt);
        dijkstra();
        if (dist[tt] == INF)
            printf("-1\n");
        else
            printf("%d\n", dist[tt]);
    }// End of while
    
    return 0;
}
