/*
PROG:   The Doors
ID  :   ouyangyewei
LANG:   C++
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define DEBUG 0

const int maxn = 104;
const int INF = 1000000;

int    N, M, pSizes;
double px[50], py[50][5], dist[maxn];
struct POINT
{
    double x, y;
}p[maxn];
struct EDGE
{
    int u, v;
    double w;
}edge[maxn];

double cross(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return ( (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1) );
}// cross

bool CanTakeIt(POINT a, POINT b)
{
    int  k=0;
    bool flag=true;
    
    if (a.x >= b.x)
        return false;
        
    while (px[k]<=a.x && k<N)
        ++k;
    
    for (; px[k]<b.x&&k<N; ++k)
    {
        if (cross(a.x, a.y, b.x, b.y, px[k], 0)
            *cross(a.x, a.y, b.x, b.y, px[k], py[k][0])<0
        ||  cross(a.x, a.y, b.x, b.y, px[k], py[k][1])
            *cross(a.x, a.y, b.x, b.y, px[k], py[k][2])<0
        ||  cross(a.x, a.y, b.x, b.y, px[k], py[k][3])
            *cross(a.x, a.y, b.x, b.y, px[k], 10)<0)
        {
            flag = false;
            break;
        }// judge point a and b if were warded off by the kth wall
    }
    
    return flag;
}// CanTakeIt

double DIST(POINT a, POINT b)
{
    return ( sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ) );
}// DIST

void Read_Data()
{
    int i, j;
    
    p[0].x=0, p[0].y=5; // the start point
    pSizes = 1;
    for (i=0; i<N; ++i)
    {
        scanf("%lf", &px[i]);
        for (j=0; j<4; ++j)
        {
            p[pSizes].x = px[i];
            scanf("%lf", &py[i][j]);
            p[pSizes].y = py[i][j];
            ++pSizes;
        }
    }// Input
    p[pSizes].x=10, p[pSizes].y=5;  // the end point
    ++pSizes;
    
    M=0;
    for (i=0; i<pSizes; ++i)
    {
        for (j=i+1; j<pSizes; ++j)
        {
            if ( CanTakeIt(p[i], p[j]) )
            {
                edge[M].u=i, edge[M].v=j;
                edge[M].w=DIST( p[i], p[j] );
                ++M;
            }
        }
    }// creat the graph
}// Read_Data

void Bellman_Ford(int src)
{
    int  i, k;
    bool ex=true;
    for (i=0; i<=pSizes; ++i)
        dist[i] = INF;
    
    dist[src]=0;
    for (k=1; k<pSizes&&ex; ++k)
    {
        ex = false;
        for (i=0; i<M; ++i)
        {
            if (dist[edge[i].u]<INF
            && dist[edge[i].u]+edge[i].w<dist[edge[i].v])
            {
                ex = true;
                dist[edge[i].v] = dist[edge[i].u]+edge[i].w;
            }
        }
    }// Main Process
}// Bellman_Ford

int main()
{
#if DEBUG
    freopen("E:\\zoj_1721.txt", "r", stdin);
    freopen("E:\\zoj_1721_ans.txt", "w", stdout);
#endif
    
    while (~scanf("%d", &N), N!=-1)
    {
        memset(px, 0, sizeof(px));
        memset(py, 0, sizeof(py));
        memset(p, 0, sizeof(p));
        memset(edge, 0, sizeof(edge));

        Read_Data();
        Bellman_Ford( 0 );
        
        printf("%.2lf\n", dist[pSizes-1]);
    }// End of while
    
    return 0;
}
