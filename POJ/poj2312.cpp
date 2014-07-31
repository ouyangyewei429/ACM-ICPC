#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
using namespace std;

#define localjudge

const int maxn = 310;
char maze[maxn][maxn];
int  mNum, nNum, vis[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
typedef struct Node
{
    int x, y, step;
}Graph;

bool IsInBound(int x, int y)
{
    if (x<0 || x>=mNum || y<0 || y>=nNum)
        return false;
    
    return true;
}/* IsInBound */

void bfs(int sx, int sy, int tx, int ty)
{
    bool  isSolve = false;
    Graph cur, next;
    queue <Graph> q;
    
    cur.x = sx;
    cur.y = sy;
    cur.step = 0;
    q.push(cur);
    
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if (cur.x==tx && cur.y==ty)
        {
            isSolve = true;
            printf("%d\n", cur.step);
            break;
        }
        
        if (maze[cur.x][cur.y] == 'B')
        {
            ++cur.step;
            maze[cur.x][cur.y] = 'E';
            
            q.push(cur);
        }/* End of If */
        else
        {
            for (int i=0; i<4; ++i)
            {
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                
                if (!vis[next.x][next.y] && IsInBound(next.x, next.y)
                    && maze[next.x][next.y]!='R' && maze[next.x][next.y]!='S')
                {
                    vis[next.x][next.y] = 1;
                    next.step = cur.step + 1;
                    
                    q.push(next);
                }
            }
        }/* End of Else */
    }/* End of While */
    if (!isSolve)
        printf("-1\n");
}/* bfs */

int main()
{
#ifdef localjudge
    freopen("E:\\poj2312.txt", "r", stdin);
    freopen("E:\\poj2312(result).txt", "w", stdout);
#endif

    while (~scanf("%d %d", &mNum, &nNum), mNum||nNum)
    {
        memset(vis, 0, sizeof(vis));
        memset(maze, 0, sizeof(maze));
        
        for (int i=0; i<mNum; ++i)
            scanf("%s", maze[i]);
        
        int sx, sy, tx, ty;
        for (int i=0; i<mNum; ++i)
        {
            for (int j=0; j<nNum; ++j)
            {
                if (maze[i][j] == 'Y')
                    sx = i, sy = j;
                else if (maze[i][j] == 'T')
                    tx = i, ty = j;
            }
        }
        
        bfs(sx, sy, tx, ty);
    }/* End of While */
    
    return 0;
}
