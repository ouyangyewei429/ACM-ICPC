/*
PROG:   Constructing Roads
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int MAXN = 104;
const int MAXM = 5004;
const int INF = 0x3F3F3F3F;

int N, Q;
int nearvex[MAXN], lowcost[MAXN], edge[MAXN][MAXN];

int prim(int src)
{
    int i, j, u, minValue, sumWeight=0;
    for (i=1; i<=N; ++i)
        lowcost[i]=edge[src][i], nearvex[i]=src;
    
    lowcost[src] = 0;
    nearvex[src] = -1;
    for (i=1; i<N; ++i)
    {
        u=-1, minValue=INF;
        for (j=1; j<=N; ++j)
        {
            if ( nearvex[j]!=-1 && minValue>lowcost[j] )
                u=j, minValue=lowcost[j];
        }// Find the nearest vertex
        
        if ( u!=-1 )    // have found the vertex
        {
            nearvex[u] = -1;
            sumWeight += lowcost[u];
            for (j=1; j<=N; ++j)
            {
                if ( nearvex[j]!=-1 && lowcost[j]>edge[u][j] )
                    lowcost[j] = edge[u][j];
            }
        }// End of If
    }// Main Process
    
    return sumWeight;
}// prim

int main()
{
    int i, j, u, v;
    while (~scanf("%d", &N))
    {
        for (i=1; i<=N; ++i)
        {
            for (j=1; j<=N; ++j)
                scanf("%d", &edge[i][j]);
        }// Input
        
        scanf("%d", &Q);
        for (i=1; i<=Q; ++i)
        {
            scanf("%d %d", &u, &v);
            edge[u][v] = edge[v][u] = 0;
        }// preprocess
        
        printf("%d\n", prim( 1 ));
    }// End of While
    
    return 0;
}
