/*
PROG:   Choose the best route
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int MAXN_NODE = 1004;
const int MAXN_EDGE = 20004;
const int INF = 0x3F3F3F3F;

int N, M, K, ss, tt, lowcost, dist[MAXN_NODE];
struct EDGE
{
    int u, v, w;
}edge[MAXN_EDGE];

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
        }
    }// Main_Process
}// Bellman_Ford

int main()
{
    int i, j, a, b, c;
    while (~scanf("%d %d %d", &N, &M, &ss))
    {
        for (i=0; i<M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[i].u=b, edge[i].v=a, edge[i].w=c;
        }// input
        
        Bellman_Ford( ss );
        
        lowcost=INF;
        scanf("%d", &K);
        for (i=1; i<=K; ++i)
        {
            scanf("%d", &tt);
            if (dist[tt]<INF && lowcost>dist[tt])
                lowcost = dist[tt];
        }// Find the lowcost
        
        if (lowcost < INF)
            printf("%d\n", lowcost);
        else
            printf("-1\n");
    }// end of while
    
    return 0;
}
