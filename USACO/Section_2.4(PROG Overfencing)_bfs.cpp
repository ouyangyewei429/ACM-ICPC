/*
PROG:   maze1
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG 0

const int MAXH = 102;
const int MAXW = 40;

char graph[MAXH<<1|1][MAXW<<1|1];
bool hash[MAXH][MAXW];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  W, H, zx[2], zy[2];
int  dist[2][MAXH][MAXW];
struct Node
{
    int x, y, t;
};

void ReadData()
{   // Read the maze and find two start points

    int k = 0;
    scanf("%d %d", &W, &H);
    for ( int i=1; i<=( H<<1|1 ); ++i )
    {
        getchar();
        for ( int j=1; j<=( W<<1|1 ); ++j )
        {
            scanf("%c", &graph[i][j]);
            if ( ( i==1 || i==(H<<1|1) ) && graph[i][j]==' ' )
            {
                if ( i==1 ) zx[k] = 1, zy[k] = j/2;
                else    zx[k] = H, zy[k] = j/2;

				++k, graph[i][j] = '-'; // 封闭入口 
            }
            if ( ( j==1 || j==(W<<1|1) ) && graph[i][j]==' ' )
            {
                if ( j==1 ) zx[k] = i/2, zy[k] = 1;
                else    zx[k] = i/2, zy[k] = W;

				++k, graph[i][j] = '|'; // 封闭入口 
            }
        }
    }
}// ReadData

bool IsOut( int x, int y )
{
    return ( x<1 || y<1 || x>(H<<1|1) || y>(W<<1|1) );
}// IsOut

void bfs( int ss, int tt, int index )
{
    Node c, n;
    queue <Node> q;
    
    // Init
    hash[ss][tt] = true;
    dist[index][ss][tt] = 1;    // 从入口走到起点，走了一步 
    c.x = ss, c.y = tt, c.t = 1;
    
    q.push( c );
    while ( !q.empty() )
    {
        c = q.front();
        q.pop();
        
        for ( int k=0; k<4; ++k )
        {
            if ( graph[ 2*c.x+dx[k] ][ 2*c.y+dy[k] ]==' ' ) // 判断下一步的方向上是否有障碍物 
            {
                n.x = c.x+dx[k], n.y = c.y+dy[k];
                if ( hash[n.x][n.y] )   continue;
                
                hash[n.x][n.y] = true;
                n.t = dist[index][n.x][n.y] = c.t+1;
                q.push( n );
            }// legal position
        }
    }// End of while
}// bfs

int main()
{
#if DEBUG
    freopen("E:\\maze1.txt", "r", stdin);
    freopen("E:\\maze1_ans.txt", "w", stdout);
#endif
    
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    
    ReadData();
    
    bfs( zx[0], zy[0], 0 );   // first start point, index of array dist

    memset( hash, false, sizeof(hash) );
    bfs( zx[1], zy[1], 1 );   // second start point, index of array dist
    
    int min, max=-1;
    for ( int i=1; i<=H; ++i )
    {
        for ( int j=1; j<=W; ++j )
        {
            min = dist[0][i][j]<dist[1][i][j] ? dist[0][i][j]:dist[1][i][j];
            max = min>max ? min:max;
        }
    }// Find the result
    
    printf("%d\n", max);
    
//	system("pause");
    return 0;
}
