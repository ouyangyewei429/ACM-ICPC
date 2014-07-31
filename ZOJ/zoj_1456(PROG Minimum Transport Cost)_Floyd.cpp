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

#define DEBUG 0

const int maxn = 36;
const int INF = 0x3F3F3F3F;

int  N, EndPoint, tax[maxn], edge[maxn][maxn];
int  path[maxn][maxn], dist[maxn][maxn];

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
            path[i][j] = j;
            if ( j!=src && j!=dest && edge[i][j]!=0 && edge[i][j]!=-1 )
                dist[i][j] = edge[i][j]+tax[j];
            else
                dist[i][j] = ( edge[i][j]==-1 ) ? INF:edge[i][j];
        }
    }// End of for
    
    /*
    for ( int i=1; i<=N; ++i )
    {
        for ( int j=1; j<=N; ++j )
            printf("%10d ", dist[i][j]);
        printf("\n");
    }
    printf("\n");
    */
    
}// Initalize

void Floyd( int src )
{
    for ( int k=1; k<=N; ++k )
    {
        for ( int i=1; i<=N; ++i )
        {
            for ( int j=1; j<=N; ++j )
            {
				if ( k==i || k==j )	continue;
				
				int tt = dist[i][k]+dist[k][j];
                if ( tt<dist[i][j] )
                    dist[i][j] = tt, path[i][j] = path[i][k];
                else if ( tt==dist[i][j] && path[i][j]>path[i][k] )
                    path[i][j] = path[i][k];
            }
        }
    }// Loop
}// Floyd
/*
void dfs( int ss, int tt )
{
    if ( tt!=ss )
        dfs( ss, path[ss][tt] );
    
    if ( tt!=EndPoint )
        printf("%d-->", tt);
}// dfs
*/
void output( int src, int dest )
{
    printf("From %d to %d :\nPath: %d", src, dest, src);
    
    int t = src;
    while ( t!=dest )
    {
        printf("-->%d", path[t][dest]);
        t = path[t][dest];
    }

    printf("\nTotal cost : %d\n\n", dist[src][dest]);
}// output

void Solve()
{
    int ss, tt;
    while ( ~scanf("%d %d", &ss, &tt), ss+tt!=-2 )
    {
        Initalize( ss, tt );
        Floyd( ss );
        output( ss, tt );
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
