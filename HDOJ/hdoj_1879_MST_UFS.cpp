/*
PROG:   继续畅通工程
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 5004;

int M, NCity, city[104];
struct EDGE
{
    int u, v, w;
}edge[maxn];

int compare(const void *c, const void *d)
{
    return ( (*(EDGE *)c).w - (*(EDGE *)d).w );
}// compare

int FindSet( int k )
{
    while ( k!=city[k] )
        k = city[k];
    
    return k;
}// FindSet

bool Merge(int x, int y)
{
    int r1 = FindSet( x );
    int r2 = FindSet( y );
    if ( r1==r2 )
        return false;
    
    if ( r1<r2 )
        city[r2] = r1;
    else
        city[r1] = r2;
    
    return true;
}// Merge

int Kruskal()
{
    int i, edgeNums=0, lowcost=0;
    
    for (i=0; i<M; ++i)
    {
        if ( Merge(edge[i].u, edge[i].v) )
        {
            ++edgeNums;
            lowcost += edge[i].w;
        }
    }// MST
    
    return lowcost;
}// Kruskal

int main()
{
    int i, a, b, c, tag;
    while (~scanf("%d", &NCity), NCity!=0)
    {
        for (i=0; i<=NCity; ++i)
            city[i] = i;
        
        M = NCity*(NCity-1)/2;
        for (i=0; i<M; ++i)
        {
            scanf("%d %d %d %d", &a, &b, &c, &tag);
            if (tag == 0)
                edge[i].u=a, edge[i].v=b, edge[i].w=c;
            else
                edge[i].u=a, edge[i].v=b, edge[i].w=0;
        }// preprocess
        
        qsort(edge, M, sizeof(edge[0]), compare);
        printf("%d\n", Kruskal());
    }// End of while
    
    return 0;
}
