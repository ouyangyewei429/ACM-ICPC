/*
PROG:   一个人的旅行
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 1004;
const int INF = 0x3F3F3F3F;

bool in[maxn];
int  T, S, D, N, lowcost;
int  ss[maxn], tt[maxn], dist[maxn], edge[maxn][maxn];

void Dijkstra(int src)
{
    int i, j, u, minValue;
    for (i=1; i<=N; ++i)
        dist[i]=edge[src][i], in[i]=false;
    
    dist[src]=0, in[src]=true;
    for (i=1; i<N; ++i)
    {
        minValue = INF;
        for (j=1; j<=N; ++j)
        {
            if (!in[j] && minValue>dist[j])
                u=j, minValue=dist[j];
        }// Find the nearest node
        
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
    while (~scanf("%d %d %d", &T, &S, &D))
    {
        memset(edge, INF, sizeof(edge));
        
        N = -1;
        for (i=1; i<=T; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            if (c < edge[a][b])
                edge[a][b] = edge[b][a] = c;
            if (a>b && a>N)
                N = a;
            else if (b>a && b>N)
                N = b;
        }// Input
        for (i=1; i<=S; ++i)
            scanf("%d", &ss[i]);
        for (i=1; i<=D; ++i)
            scanf("%d", &tt[i]);
        
        lowcost = INF;
        for (i=1; i<=S; ++i)
        {
            //memset(dist, INF, sizeof(dist));
            Dijkstra( ss[i] );
            for (j=1; j<=D; ++j)
            {
                if (lowcost > dist[ tt[j] ])
                    lowcost = dist[ tt[j] ];
            }
        }// Find the minimum
        
        printf("%d\n", lowcost);
    }// end of while
    
    return 0;
}

