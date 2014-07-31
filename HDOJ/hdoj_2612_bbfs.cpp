/*
PROG:   Find A Way
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 204;

char maze[maxn][maxn];
int  N, M, yx, yy, mx, my, graph[2][maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
typedef struct node
{
    int x, y, t, num;
}NODE;

inline bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=N || y>=M);
}/* IsOut */

int bbfs()
{
    NODE    c, n;
    queue <NODE> q;
    
    c.x=yx, c.y=yy, c.t=0, c.num=0;
    q.push(c);
    
    c.x=mx, c.y=my, c.t=0, c.num=1;
    q.push(c);
    
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        for (int i=0; i<4; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            
            if (IsOut(n.x, n.y) || maze[n.x][n.y]=='#'
                || maze[n.x][n.y]=='Y' || maze[n.x][n.y]=='M')
                continue;
            
            if (graph[c.num][n.x][n.y])
                continue;
            
            if (maze[n.x][n.y] == '@')
            {
                if (graph[c.num^1][n.x][n.y] != 0)
                {
                    return (graph[c.num^1][n.x][n.y]+c.t+1);
                }/* Meet */
                else
                {
                    n.t=c.t+1, n.num=c.num;
                    graph[n.num][n.x][n.y]=graph[n.num][c.x][c.y]+1;
                
                    q.push(n);
                }/* his friend doesn't reach there */
            }/* KFC */
            else
            {
                n.t=c.t+1, n.num=c.num;
                graph[n.num][n.x][n.y]=graph[n.num][c.x][c.y]+1;
                
                q.push(n);
            }/* The Empty Space */
        }/* End of For */
    }/* End of While */
}/* bbfs */

int main()
{
    while (~scanf("%d %d", &N, &M))
    {
        memset(graph, 0, sizeof(graph));
        
        for (int i=0; i<N; ++i)
        {
            //getchar();
            for (int j=0; j<M; ++j)
            {
                cin >> maze[i][j];
                //graph[0][i][j]=graph[1][i][j]=0;
                //scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'Y')
                    yx=i, yy=j;
                if (maze[i][j] == 'M')
                    mx=i, my=j;
            }
        }/* Graph */
        
        printf("%d\n", 11*bbfs());
    }/* End of While */
    
    return 0;
}
