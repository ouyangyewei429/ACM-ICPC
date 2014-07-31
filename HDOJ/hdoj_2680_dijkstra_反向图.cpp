/*
PROG:   Choose the best route
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 1004;
const int INF = 0x3F3F3F3F;

bool in[maxn];
int  N, M, K, ss, tt, lowcost;
int  dist[maxn], edge[maxn][maxn];

void Dijkstra(int src)
{
    int i, j, u, minValue;
    for (i=1; i<=N; ++i)
        dist[i]=edge[src][i], in[i]=false;
    
    dist[src]=0, in[src]=true;
    for (i=1; i<N; ++i)
    {
        u=0, minValue=INF;
        for (j=1; j<=N; ++j)
        {
            if (!in[j] && minValue>dist[j])
                u=j, minValue=dist[j];
        }// Find the nearest node
        
		if (u == 0)	return ;

        in[u] = true;
        for (j=1; j<=N; ++j)
        {
            if (!in[j] && dist[u]+edge[u][j]<dist[j])
                dist[j] = dist[u]+edge[u][j];
        }
    }// Main Process
}// Dijkstra

int main()
{
    int i, j, a, b, c;
    while (~scanf("%d %d %d", &N, &M, &ss))
    {
        //memset(edge, INF, sizeof(edge));
        for (i=1; i<=N; ++i)
        {
            for (j=1; j<=N; ++j)
                edge[i][j] = (i!=j) ? INF:0;
        }// Init
        
        for (i=1; i<=M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[b][a] = c;
        }// creat a backword graph
        
        Dijkstra( ss );
        
        lowcost = INF;
        scanf("%d", &K);
        for (i=1; i<=K; ++i)
        {
            scanf("%d", &tt);
            if (dist[tt]!=INF && lowcost>dist[tt])
                lowcost = dist[tt];
        }// Find the lowcost
        
        if (lowcost != INF)
            printf("%d\n", lowcost);
        else
            printf("-1\n");
    }// end of while
    
    return 0;
}

