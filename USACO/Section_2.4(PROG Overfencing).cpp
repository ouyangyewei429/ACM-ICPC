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

char graph[204][204];
bool hash[204][204];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  px[] = {-2, 2, 0, 0};
int  py[] = {0, 0, -2, 2};
int  W, H, s1, t1, s2, t2;
int  b[204][204], c[204][204], maze[204][204][4];
struct Node
{
    int x, y, t;
};

void ReadData()
{
	scanf("%d %d", &W, &H);
    for ( int i=1; i<=( H<<1|1 ); ++i )
    {
        getchar();
        for ( int j=1; j<=( W<<1|1 ); ++j )
            scanf("%c", &graph[i][j]);
    }    
}// ReadData

void Creat_Graph()
{
    for ( int x=2, i=2; i<=( H<<1|1 ); i+=2, x+=2 )
    {
        for ( int y=2, j=2; j<=( W<<1|1 ); j+=2, y+=2 )
        {
            for ( int k=0; k<4; ++k )
            {
                if ( graph[ i+dx[k] ][ j+dy[k] ]!=' ' )
                    maze[x][y][k] = -1;
            }
        }
    }
}// Creat_Graph

void Find_Graph()
{
	// Find the start_point and destination
    for ( int i=3; i<=H; ++i )
    {
        for ( int j=1; j<=W; ++j )
        {
            int x = (i<<1), y= (j<<1);
            for ( int k=0; k<4; ++k )
            {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if ( ( nx==0 || nx==(H<<1|1) ) && graph[nx][ny]==' ' )
                    s1 = x, t1 = y;
                if ( ( ny==0 || ny==(W<<1|1) ) && graph[nx][ny]==' ' )
                    s2 = x, t2 = y;
            }
        }
    }
}// Find_Graph

bool IsOut( int x, int y )
{
    return ( x<2 || y<2 || x>2*H || y>2*W );
}// IsOut

void bfs( int ss, int tt, int t[][204] )
{
    Node c, n;
    queue <Node> q;
    
    c.x = ss, c.y = tt, c.t = 1;
    hash[ss][tt] = true;
    
    q.push( c );
    while ( !q.empty() )
    {
        c = q.front();
        q.pop();
        
        for ( int k=0; k<4; ++k )
        {
            n.x = c.x+px[k];
            n.y = c.y+py[k];
            if ( maze[c.x][c.y][k]==-1 )    continue;
            if ( IsOut( n.x, n.y ) || hash[n.x][n.y] )  continue;
            
            hash[n.x][n.y] = true;
            n.t = c.t+1, t[n.x][n.y] = n.t;
            q.push( n );
        }
    }// End of while
}// bfs

int main()
{
#if DEBUG
    freopen("E:\\maze1.txt", "r", stdin);
    freopen("E:\\maze1_ans.txt", "w", stdout);
#endif
    /*
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    */
    ReadData();
    Creat_Graph();
	Find_Graph();
	
	b[s1][t1] = 1;
	bfs( s1, t1, b );
	
	c[s2][t2] = 1;
	memset( hash, false, sizeof(hash) );
	bfs( s2, t2, c );
	
	int min, max=-1;
	for ( int i=2; i<=( H<<1|1 ); i+=2 )
	{
	    for ( int j=2; j<=( W<<1|1 ); j+=2 )
	    {
	        min = b[i][j]<c[i][j] ? b[i][j]:c[i][j];
            max = min>max ? min:max;
        }    
    }
    
    printf("%d\n", max);
    
	system("pause");
    return 0;
}
