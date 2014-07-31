#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
using namespace std;

#define localjudge

const int maxn = 80;
char maze[maxn][maxn];
int  mNum, nNum, door[6], totKey[6], vis[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
typedef struct Node
{
    int x, y;
}Graph;

bool IsInBound(int x, int y)
{
    if (x<0 || x>=mNum || y<0 || y>=nNum)
        return false;
    
    return true;
}/* IsInBound */

void bfs(int sx, int sy, int tx, int ty)
{
    bool  flag = false;
    bool  isSolve = false;
    int   key[6] = {0};
    Graph next, cur;
    queue <Graph> q;
    
    cur.x = sx;
    cur.y = sy;
    q.push(cur);
    
    vis[cur.x][cur.y] = 1;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if (cur.x==tx && cur.y==ty)
        {
            for (int i=0; i<5; ++i)
            {
                if (door[i])
                    break;
                else if (i == 4)
                {
                    isSolve = true;
                    printf("YES\n");
                    flag = true;
                    break;
                }    
            }
            if (flag)
                break;
        }
        
        if (maze[cur.x][cur.y]>='a' && maze[cur.x][cur.y]<='e')
        {
            ++key[maze[cur.x][cur.y]-'a'];
            maze[cur.x][cur.y] = '.';
            
            q.push(cur);
        }
        else if (maze[cur.x][cur.y]>='A' && maze[cur.x][cur.y]<='E')
        {
            if (totKey[maze[cur.x][cur.y]-'A']!=0
                && key[maze[cur.x][cur.y]-'A']==totKey[maze[cur.x][cur.y]-'A'])
            {
                door[maze[cur.x][cur.y]-'A'] = 0;
                maze[cur.x][cur.y] = '.';
            }
            
            q.push(cur);
        }
        else
        {
            for (int i=0; i<4; ++i)
            {
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                
                if (!vis[next.x][next.y] && IsInBound(next.x, next.y)
                    && maze[next.x][next.y]!='X')
                {                    
                    vis[next.x][next.y] = 1;
                    q.push(next);
                }
            }
        }
    }/* End of While */
    if (!isSolve)
        printf("NO\n");
}/* bfs */

int main()
{
#ifdef localjudge
    freopen("E:\\nyist82.txt", "r", stdin);
    freopen("E:\\nyist82(result).txt", "w", stdout);
#endif

    while (~scanf("%d %d", &mNum, &nNum), mNum+nNum!=0)
    {
        memset(vis, 0, sizeof(vis));
        memset(maze, 0, sizeof(maze));
        memset(door, 0, sizeof(door));
        memset(totKey, 0, sizeof(totKey));
        
        for (int i=0; i<mNum; ++i)
            scanf("%s", maze[i]);
        
        int sx, sy, tx, ty;
        for (int i=0; i<mNum; ++i)
        {
            for (int j=0; j<nNum; ++j)
            {
                if (maze[i][j] == 'S')
                    sx = i, sy = j;
                else if (maze[i][j] == 'G')
                    tx = i, ty = j;
                else if (maze[i][j]>='a' && maze[i][j]<='e')
                    ++totKey[maze[i][j]-'a'];
                else if (maze[i][j]>='A' && maze[i][j]<='E')
                    door[maze[i][j]-'A'] = 1;
            }
        }
        
        bfs(sx, sy, tx, ty);
    }/* End of While */
    
    return 0;
}
