/*
PROG:   agrinet
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

const int maxn = 102;
const int INF = 0x3F3F3F3F;

bool vis[maxn];
int  N, dist[maxn], edge[maxn][maxn];

void ReadData()
{
    scanf("%d", &N);
    for ( int i=0; i<N; ++i )
    {
        for ( int j=0; j<N; ++j )
            scanf("%d", &edge[i][j]);
    }// End of For
}// ReadData

void Prim( int src )
{
    int i, j, u, minValue, lowcost=0;
    
    for ( i=0; i<N; ++i )
        vis[i]=false, dist[i]=edge[src][i];
    
    vis[ src ]=true, dist[ src ]=0;
    for ( i=1; i<N; ++i )
    {
        minValue = INF;
        for ( j=0; j<N; ++j )
        {
            if ( !vis[j] && minValue>dist[j] )
                u=j, minValue=dist[j];
        }// Find the nearest vertex
        
        vis[ u ]=true;
        lowcost += dist[ u ];
        for ( j=0; j<N; ++j )
        {
            if ( !vis[j] && edge[u][j]<dist[j] )
                dist[j] = edge[u][j];
        }// Modify the dist table
    }// End of for
    
    printf("%d\n", lowcost);
    return ;
}// Prim

int main()
{
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);

    ReadData();
    Prim( 0 );
    
    return 0;
}
