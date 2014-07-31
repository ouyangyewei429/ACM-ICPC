/*
PROG:   comehome
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

#define DEBUG 0

const int maxn = 56;
const int INF = 0x3F3F3F3F;

bool inq[maxn], hash[maxn];
int  N, M, lowcosts, dist[maxn], edge[maxn][maxn];

void spfa( int src )
{
    int u, i;
    queue <int> q;
    
    inq[src]=true, dist[src]=0;
    q.push( src );
    while ( !q.empty() )
    {
        u = q.front();
        q.pop();
        inq[ u ]=false;
        
        for ( i=0; i<maxn; ++i )
        {
            if ( !hash[i] ) continue;
            if ( dist[i]>dist[u]+edge[u][i] )
            {
                dist[i] = dist[u]+edge[u][i];
                if ( !inq[i] )
                    inq[i]=true, q.push( i );
            }// relaxing
        }
    }// End of while
}// spfa

int main()
{/*
#if DEBUG
    freopen("E:\\comehome.txt", "r", stdin);
    freopen("E:\\comehome_ans.txt", "w", stdout);
#endif
*/

    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);

    char a, b;
    int  i, j, u, v, w, ss;
    for ( i=0; i<maxn; ++i )
    {
        dist[i] = INF;
        inq[i] = hash[i] = false;
        for ( j=0; j<maxn; ++j )
            edge[i][j] = INF;
    }// Init
    
    scanf("%d", &N);
    for ( i=0; i<N; ++i )
    {
        getchar();
        scanf("%c %c %d", &a, &b, &w);
        u = ( a>='A'&&a<='Z' ) ? (a-'A'):(a-'a'+26);    // 大写字母分布在 0~25， 小写字母分布在 26~55 
        v = ( b>='A'&&b<='Z' ) ? (b-'A'):(b-'a'+26);
        if ( w<edge[u][v] ) // 输入有重边，要判重 
        {
            edge[u][v] = edge[v][u] = w;
            hash[u] = hash[v] = true;
        }    
    }// Input
    
    spfa( 25 ); // 以终点“Z”作为起点，求出起点到各 pasture 的最短路径 
    
    lowcosts = INF;
    for ( i=0; i<25; ++i )
    {
        if ( hash[i] && lowcosts>dist[i] )
            ss=i+'A', lowcosts=dist[i];
    }// Find the shortest path
    
    printf("%c %d\n", ss, lowcosts);
    
//    system("pause");
    return 0;
}
