/*
PROG:   Eddy's picture
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

int NCity, M, cas=1, rt=0, city[104];
struct POINT
{
    double x, y;
}p[104];
struct EDGE
{
    int u, v;
    double w;
}edge[maxn];

double dist(double x1, double y1, double x2, double y2)
{
    return ( sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) ) );
}// dist

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

double Kruskal()
{
    int edgeNums = 0;
    double lowcost = 0;
    for (int i=0; i<=NCity; ++i)
        city[i] = i;

    for (int i=0; i<M; ++i)
    {
        if ( Merge(edge[i].u, edge[i].v) )
        {
            ++edgeNums;
            lowcost += edge[i].w;
        }
        if (edgeNums == NCity-1)
            break;
    }// Main Process
    
    return lowcost;
}// Kruaksl

int main()
{
    int i, j;
    while (~scanf("%d", &NCity))
    {
        for (i=0; i<NCity; ++i)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        
        M = 0;
        for (i=0; i<NCity; ++i)
        {
            for (j=i+1; j<NCity; ++j)
            {
                edge[M].u=i, edge[M].v=j;
                edge[M++].w=dist(p[i].x, p[i].y, p[j].x, p[j].y);
            }
        }// record the edges
        
        qsort(edge, M, sizeof(edge[0]), compare);
        
        printf("%.2lf\n", Kruskal());
    }// End of while
    
    return 0;
}
