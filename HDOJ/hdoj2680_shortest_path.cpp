/*
PROG:   Choose the best route
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 20004;
const int INF = 0x3F3F3F3F;

int N, M, K, tt, ss, lowcost, dist[1004];
struct EDGE
{
    int u, v, w;
}edge[maxn];

void Bellman_Ford(int src)
{
    int i, k;
    for (i=1; i<=N; ++i)
        dist[i] = INF;
    
    dist[src]=0;
    for (k=1; k<N; ++k)
    {
        for (i=0; i<M; ++i)
        {
            if (dist[edge[i].u]<INF
            && dist[edge[i].u]+edge[i].w<dist[edge[i].v])
            {
                dist[edge[i].v] = dist[edge[i].u]+edge[i].w;
            }
        }// end of for
    }// end of for
}// Bellman_Ford

int main()
{
    int i, a, b, c;
    while (~scanf("%d %d %d", &N, &M, &tt))
    {
        for (i=0; i<M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[i].u=a, edge[i].v=b, edge[i].w=c;
        }// input
        
        lowcost = INF;
        scanf("%d", &K);
        for (i=0; i<K; ++i)
        {
            scanf("%d", &ss);
            Bellman_Ford( ss );
            if (dist[tt]<INF && lowcost>dist[tt])
                lowcost = dist[tt];
        }// Main Process
        
        if (lowcost < INF)
            printf("%d\n", lowcost);
        else
            printf("-1\n");
    }// end of while 
    
    return 0;
}
