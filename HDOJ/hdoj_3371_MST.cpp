/*
PROG:   Connect the Cities
ID  :   ouyangyewei
LAAG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int MAXN = 504;
const int MAXM = 25004;
const int INF = 0x3F3F3F3F;

int T, N, M, K, t;
int vex[MAXN], city[MAXN], dist[MAXN];
struct EDGE
{
    int u, v, w;
}edge[MAXM];

int compare(const void *c, const void *d)
{
    return ( (*(EDGE *)c).w - (*(EDGE *)d).w );
}// compare

int FindSet(int k)
{
    int s, tmp;
    for (s=k; city[s]>=0; s=city[s])
        ;
    while ( s!=k )
    {
        tmp = city[k];
        city[k] = s;
        k = tmp;
    }
    
    return s;
}// FindSet

void Merge(int x, int y)
{
    int r1 = FindSet( x );
    int r2 = FindSet( y );
    int tmp = city[r1]+city[r2];
    
    if ( city[r1]>city[r2] )
        city[r1]=r2, city[r2]=tmp;
    else
        city[r2]=r1, city[r1]=tmp;
}// Merge

int Kruskal()
{
    int i, edgeNums=0, lowcost=0;
    for (i=1; i<=N; ++i)
        city[i] = -1;
    
    for (i=0; i<M; ++i)
    {
        if ( FindSet(edge[i].u)!=FindSet(edge[i].v) )
        {
            ++edgeNums;
            lowcost += edge[i].w;
            Merge(edge[i].u, edge[i].v);
        }
        if ( edgeNums==N-1 )
            break;
    }// Main Process
    if ( edgeNums==N-1 )
        return lowcost;
    else
        return -1;
}// Kruskal

int main()
{
    int i, j, a, b, c;
    
    scanf("%d", &T);
    while ( T-- )
    {
        scanf("%d %d %d", &N, &M, &K);
        for (i=0; i<M; ++i)
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        
        for (i=0; i<K; ++i)
        {
            scanf("%d", &t);
            for (j=0; j<t; ++j)
            {
                scanf("%d", &vex[j]);
                if ( j!=0 )
                {
                    edge[M].u=vex[j-1];
                    edge[M].v=vex[j];
                    edge[M++].w = 0;
                }// preprocess 
            }
        }// End of for
        
        qsort(edge, M, sizeof(edge[0]), compare);
        printf("%d\n", Kruskal());
    }// end of while
    
    return 0;
}
