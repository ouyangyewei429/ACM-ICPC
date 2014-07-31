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

#define DEBUG 1

const int maxn = 104;
const double INF = 1000000;

int    N, M, pSizes;
double px[maxn], py[maxn][5], dist[maxn];
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

bool IsOkey(POINT a, POINT b)
{   
    if (a.x > b.x)
        return false;
    
    int  i, k=0;
    bool flag=true;
    while (px[k]<=a.x && k<N)
        ++k;
    
    for (i=k; px[i]<b.x&&i<N; ++i)
    {
        if (cross(a.x, a.y, b.x, b.y, px[k], 0)
            *cross(a.x, a.y, b.x, b.y, px[k], py[k][0])<0 ||
            cross(a.x, a.y, b.x, b.y, px[k], py[k][1])
            *cross(a.x, a.y, b.x, b.y, px[k], py[k][2])<0 ||
            cross(a.x, a.y, b.x, b.y, px[k], py[k][3])
            *cross(a.x, a.y, b.x, b.y, px[k], 10)<0 )
        {
            flag = false;
            break;
        }
    }// judge if two coordinate x and y cannot connect
    
    return flag;
}// IsOkey

double DIS(POINT a, POINT b)
{
    return ( sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ) );
}// DIS

void Read_Data()
{
    int i, j;
    
    p[0].x=0, p[0].y=5;   // start point (0, 5)
    pSizes=1;
    for (i=0; i<N; ++i)
    {
        scanf("%lf", &px[i]);
        for (j=0; j<4; ++j)
        {
            p[pSizes].x=px[i];
            scanf("%lf", &py[i][j]);
            p[pSizes].y=py[i][j];
            ++pSizes;
        }
    }// read the data

    p[pSizes].x=10, p[pSizes].y=5;  // end point(10, 5)
    ++pSizes;

    // creat the graph
    M = 0;
    for (i=0; i<pSizes; ++i)
    {
        for (j=i+1; j<pSizes; ++j)
        {
            if ( IsOkey(p[i], p[j]) )
            {
                edge[M].u=i, edge[M].v=j;
                edge[M].w=DIS( p[i], p[j] );
                ++M;
            }
        }
    }// end of for
}// Read_Data

void Bellman_Ford(int src)
{
    int  i, k;
    bool exit=true;
    for (i=0; i<pSizes; ++i)
        dist[i] = INF;
    
    dist[src]=0;
    for (k=0; k<pSizes&&exit; ++k)
    {
        exit = false;
        for (i=0; i<M; ++i)
        {
            if (dist[edge[i].u]<INF
            && dist[edge[i].u]+edge[i].w<dist[edge[i].v])
            {
                exit = true;
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
        Read_Data();
        Bellman_Ford( 0 );
        
        printf("%.2lf\n", dist[pSizes-1]);
    }// end of while
    
    return 0;
}
