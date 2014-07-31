/*
PROG:   Minimum Transport Cost
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 1

const int maxn = 8;
const int INF = 0x3F3F3F3F;

bool vis[maxn], hash[maxn];
int  N, EndPoint, tax[maxn], edge[maxn][maxn];
int  dist[maxn], parent[maxn], costs[maxn][maxn];

void ReadData()
{
    int i, j;
    for ( i=1; i<=N; ++i )
    {
        for ( j=1; j<=N; ++j )
            scanf("%d", &edge[i][j]);
    }// graph
    for ( i=1; i<=N; ++i )
        scanf("%d", &tax[i]);
}// ReadData

void Initalize( int src, int dest )
{
    for ( int i=1; i<=N; ++i )
    {
        for ( int j=1; j<=N; ++j )
        {
            if ( j!=src && j!=dest && edge[i][j]!=0 && edge[i][j]!=-1 )
                costs[i][j] = edge[i][j]+tax[j];
            else
                costs[i][j] = ( edge[i][j]==-1 ) ? INF:edge[i][j];
        }
    }// End of for
    
    /*
    for ( int i=1; i<=N; ++i )
    {
        for ( int j=1; j<=N; ++j )
            printf("%10d ", costs[i][j]);
        printf("\n");
    }
    printf("\n");
    */
    
}// Initalize

void Dijkstra( int src )
{
    int i, j, u, minValue;
    for ( i=1; i<=N; ++i )
    {
        hash[i] = vis[i] = false;
        dist[i] = costs[src][i];
        if ( i!=src && dist[i]<INF )	parent[i]=src;
		else	parent[i]=-1;
    }// Init
    
    vis[src]=true, dist[src]=0;
    for ( i=1; i<N; ++i )
    {
        minValue = INF;
        for ( j=1; j<=N; ++j )
        {
            if ( !vis[j] && minValue>dist[j] )
                u=j, minValue=dist[j];
        }// Find the nearest vertex
        
        vis[u]=true;
        for ( j=1; j<=N; ++j )
        {
            if ( !vis[j] && dist[u]+costs[u][j]<=dist[j] )
            {
                dist[j] = dist[u]+costs[u][j];
                if ( !hash[j] )
                    parent[j] = u, hash[j] = true;
				else if ( parent[j]>u )
					parent[j] = u;
            }
        }
    }// Find N-1 vertexs
}// Dijkstra

void dfs( int src, int k )
{
    if ( k!=src )
        dfs( src, parent[k] );
    
    if ( k!=EndPoint )
        printf("%d-->", k);
    
    return ;
}// dfs

void output( int src, int dest )
{
    EndPoint = dest;
    printf("From %d to %d :\n", src, dest);
    printf("Path: ");
    dfs( src, dest );
    printf("%d\n", dest);
    printf("Total cost : %d\n\n", dist[dest]);
}// output

void Solve()
{
    int ss, tt;
    while ( ~scanf("%d %d", &ss, &tt), ss+tt!=-2 )
    {
        Initalize( ss, tt );
        //Dijkstra( ss );
        //output( ss, tt );
    }// start point and destination
}// Solve

int main()
{
#if DEBUG
    freopen("E:\\zoj_1456.in", "r", stdin);
    freopen("E:\\zoj_1456.out", "w", stdout);
#endif

    while ( ~scanf("%d", &N), N!=0 )
    {
        ReadData();
        Solve();
    }// End of while
    
    return 0;
}
