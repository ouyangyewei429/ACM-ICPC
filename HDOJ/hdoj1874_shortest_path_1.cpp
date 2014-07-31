/*
PROG:   畅通工程续
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 2004;
const int INF = 0x3F3F3F3F;

int  N, M, EdgeNums, ss, tt, dist[204];
struct EDGE
{
    int u, v, w;
}edge[maxn];

void Bellman_Ford()
{
    int i, k;
    for (i=0; i<N; ++i)
        dist[i] = INF;
    
    dist[ss] = 0;
    for (k=1; k<=N; ++k)
    {
        for (i=0; i<EdgeNums; ++i)
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
    int i, j, a, b, c;
    while (~scanf("%d %d", &N, &M))
    {
        for (i=0, EdgeNums=0; i<M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[EdgeNums].u=a, edge[EdgeNums].v=b, edge[EdgeNums].w=c;
            ++EdgeNums;
            edge[EdgeNums].u=b, edge[EdgeNums].v=a, edge[EdgeNums].w=c;
            ++EdgeNums;
        }
            
        scanf("%d %d", &ss, &tt);
        Bellman_Ford();
        if (dist[tt] < INF)
            printf("%d\n", dist[tt]);
        else
            printf("-1\n");
    }// end of while
    
    return 0;
}
