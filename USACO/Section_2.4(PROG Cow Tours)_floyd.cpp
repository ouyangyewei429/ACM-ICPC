/*
PROG:   cowtour
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

const int maxn = 175;
const double INF = 1E15;

int N, x[maxn], y[maxn], parent[maxn];
double vert[maxn], dist[maxn][maxn];

double dis( int x1, int y1, int x2, int y2 )
{
    return ( sqrt( 1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2) ) );
}// distance

int FindSet( int k )
{
    while ( k!=parent[ k ] )
        k = parent[ k ];
    
    return k;
}// FindSet

void Merge( int xx, int yy )
{
    int r1 = FindSet( xx );
    int r2 = FindSet( yy );
    if ( r1==r2 )
        return ;
    
    if ( r1<r2 )
        parent[ r2 ] = r1;
    else
        parent[ r1 ] = r2;
}// Merge

void ReadData()
{
    char c;
    int  i, j;
    
    scanf("%d", &N);
    for ( i=1; i<=N; ++i )
    {
        vert[i] = -1, parent[i] = i;
        scanf("%d %d", &x[i], &y[i]);
    }// coordinare
    
    for ( i=1; i<=N; ++i )
    {
        getchar();
        for ( j=1; j<=N; ++j )
        {
            scanf("%c", &c);
            if ( i==j ) dist[i][j] = 0;
            else if ( c=='0' )  dist[i][j] = INF;
            else if ( c=='1' )
            {
                Merge( i, j );
                dist[i][j] = dis( x[i], y[i], x[j], y[j] );
            }    
        }
    }// creat the graph
}// ReadData

void Floyd()
{
    for ( int k=1; k<=N; ++k )
    {
        for ( int i=1; i<=N; ++i )
        {
            for ( int j=1; j<=N; ++j )
            {
                if ( k==i || k==j ) continue;
                if ( dist[i][k]+dist[k][j]<dist[i][j] )
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
}// Floyd

void Solve()
{
    int i, j;
    double dd, lowcost;
    
    for ( i=1; i<=N; ++i )
    {
        for ( j=1; j<=N; ++j )
        {
            if ( dist[i][j]!=INF && vert[i]<dist[j][i] )
                vert[i] = dist[j][i];
        }
    }// Find the longest path of the shortest path
    
    lowcost = INF;
    for ( i=1; i<=N; ++i )
    {
        for ( j=i+1; j<=N; ++j )
        {
            if ( dist[i][j]==INF && parent[i]!=parent[j] )
            {
                dd = dis( x[i], y[i], x[j], y[j] );
                if ( vert[i]+dd+vert[j]<lowcost )
                    lowcost = vert[i]+dd+vert[j];
            }
        }
    }// Find the shortest path
    
    for ( i=1; i<=N; ++i )
    {
        if ( vert[i]>lowcost )
            lowcost = vert[i];
    }
    
    printf("%.6lf\n", lowcost);
}// Solve

int main()
{
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    ReadData();
    Floyd();
    Solve();
    
    return 0;
}
