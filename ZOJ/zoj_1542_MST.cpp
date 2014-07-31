/*
PROG:   Network
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int MAXN = 1004;
const int MAXM = 15004;

int N, M, px[MAXM], py[MAXM], hub[MAXN];
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
    while ( k!=hub[k] )
        k = hub[k];
    
    return k;
}// FindSet

bool Merge(int x, int y)
{
    int r1 = FindSet( x );
    int r2 = FindSet( y );
    if ( r1==r2 )
        return false;
    
    if ( r1<r2 )
        hub[r2] = r1;
    else
        hub[r1] = r2;
    
    return true;
}// Merge

void Kruskal()
{
    int i, edgeNums=0, maxLen=-1;
    for (i=0; i<M; ++i)
    {
        if ( Merge(edge[i].u, edge[i].v) )
        {
            px[edgeNums] = edge[i].u;
            py[edgeNums] = edge[i].v;
            edgeNums++;
            
            if ( maxLen<edge[i].w ) maxLen = edge[i].w;
        }
        if ( edgeNums==N-1 )
            break;
    }// Main Porcess
    
    printf("%d\n%d\n", maxLen, edgeNums);
    for (i=0; i<edgeNums; ++i)
        printf("%d %d\n", px[i], py[i]);
}// Kruskal

int main()
{
    int i;
    while (~scanf("%d %d", &N, &M))
    {
        for (i=1; i<=N; ++i)    // Init
            hub[i] = i;
        
        for (i=0; i<M; ++i)
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        
        qsort(edge, M, sizeof(edge[0]), compare);
        
        //printf("-----------------------\n");
        //for (i=0; i<M; ++i) printf("%d %d %d\n", edge[i].u, edge[i].v, edge[i].w);
        
        Kruskal();
    }// End of while
    
    return 0;
}
