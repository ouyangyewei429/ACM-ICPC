/*
PORG:   Choose the best route
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 1004;
const int INF = 0x3F3F3F3F;

int N, M, K, ss, tt, lowcost;
int edge[maxn][maxn], dist[maxn][maxn];

void Floyd()
{
    int i, j, k;
    for (i=1; i<=N; ++i)
    {
        for (j=1; j<=N; ++j)
            dist[i][j] = (i!=j) ? edge[i][j]:0;
    }// preprocess
    
    for (k=1; k<=N; ++k)
    {
        for (i=1; i<=N; ++i)
        {
            if (dist[i][k] != INF)
            {
                for (j=1; j<=N; ++j)
                {
                    if (k==i || k==j)   continue;
                    if (dist[i][k]+dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k]+dist[k][j];
                }
            }// if road i is access to road k
        }
    }// Main Process
}// Floyd

int main()
{
    int i, j, a, b, c;
    while (~scanf("%d %d %d", &N, &M, &tt))
    {
        //memset(edge, INF, sizeof(edge));
        for (i=1; i<=N; ++i)
        {
            for (j=1; j<=N; ++j)
                edge[i][j] = INF;
        }// Init
        
        for (i=1; i<=M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a][b] = c;
        }// creat a graph
        
        Floyd();
        
        lowcost = INF;
        scanf("%d", &K);
        for (i=1; i<=K; ++i)
        {
            scanf("%d", &ss);
            if (dist[ss][tt]<INF && lowcost>dist[ss][tt])
                lowcost = dist[ss][tt];
        }// Find the minimum cost
        
        if (lowcost < INF)
            printf("%d\n", lowcost);
        else
            printf("-1\n");
    }// end of while
    
    return 0;
}
