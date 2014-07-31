/*
PROG:   畅通工程再续
ID  :   ouyangyewei
LANG:   C++
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 5004;

int NCity, M, city[104];
struct POINT
{
    int x, y;
}p[104];
struct EDGE
{
    int u, v;
    double w;
}edge[maxn];

int compare(const void *c, const void *d)
{
    return (*(EDGE *)c).w>(*(EDGE *)d).w ? 1:-1;
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

void Kruskal()
{
    int i, edgeNums=0;
    double lowcost = 0;
    
    for (i=0; i<=NCity; ++i)
        city[i] = i;
    
    for (i=0; i<M; ++i)
    {
        if ( Merge(edge[i].u, edge[i].v) )
        {
            edgeNums++;
            lowcost += edge[i].w;
        }
    }// Main Process
    if ( edgeNums==NCity-1 )
        printf("%.1lf\n", lowcost);
    else
        printf("oh!\n");
}// Kruskal

int main()
{
    int i, j, T;
    double dx, dy, tt;
    
    scanf("%d", &T);
    while ( T-- )
    {
        scanf("%d", &NCity);
        for (i=0; i<NCity; ++i)
            scanf("%d %d", &p[i].x, &p[i].y);
        
        M = 0;
        for (i=0; i<NCity-1; ++i)
        {
            for (j=i+1; j<NCity; ++j)
            {
                dx = p[i].x - p[j].x;
                dy = p[i].y - p[j].y;
                tt = sqrt( dx*dx+dy*dy );
                if (tt>=10 && tt<=1000)
                {
                    edge[M].u=i, edge[M].v=j;
                    edge[M++].w = 100*tt;
                }    
            }
        }// preprocess
        
        qsort(edge, M, sizeof(edge[0]), compare);
        Kruskal();
    }// End of while
    
    return 0;
}
