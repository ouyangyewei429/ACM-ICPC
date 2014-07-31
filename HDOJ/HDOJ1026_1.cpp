#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
using namespace std;

//#define judge

const int maxn = 110;
char maze[maxn][maxn];
int  nNum, mNum, cnt, vis[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};

struct node
{
    int x, y, hp, step;
};

struct parent
{
    int px, py, pp;
}prev[maxn][maxn];

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=nNum || y>=mNum)
    {
        return false;
    }
    
    return true;
}/* IsInBound */

void dfs(int x, int y, int pp)
{
    if (prev[x][y].px+prev[x][y].py != 0)
        dfs(prev[x][y].px, prev[x][y].py, prev[x][y].pp);
    
    int px = prev[x][y].px;
    int py = prev[x][y].py;
    
    printf("%ds:(%d,%d)->(%d,%d)\n", cnt++, px, py, x, y);
    for (int i=1; i<=pp; ++i)
        printf("%ds:FIGHT AT (%d,%d)\n", cnt++, x, y);
}/* dfs */

void bfs()
{
    bool IsSolve = false;
    queue <node> q;
    struct node cur, next;
    
    cur.x = 0;
    cur.y = 0;
    cur.step = 0;
    cur.hp = 0;
    q.push(cur);
    
    vis[0][0] = 1;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if (cur.x==nNum-1 && cur.y==mNum-1
            && maze[cur.x][cur.y]=='.')
        {
            IsSolve = true;
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", cur.step);
            
            cnt = 1;
            dfs(cur.x, cur.y, cur.hp);
        }/* End of If */
        
        if (maze[cur.x][cur.y]>='1' && maze[cur.x][cur.y]<='9')
        {
            int tmp = maze[cur.x][cur.y] - '1';
            
            if (tmp == 0)
                maze[cur.x][cur.y] = '.';
            else
                maze[cur.x][cur.y] = tmp + '0';
            
            ++cur.step;
            q.push(cur);
        }/* End of If */
        else
        {
            for (int i=0; i<4; ++i)
            {
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                next.step = cur.step + 1;
                
                if (!vis[next.x][next.y] && IsInBound(next.x, next.y)
                    && maze[next.x][next.y]!='X')
                {
                    vis[next.x][next.y] = 1;
                    prev[next.x][next.y].px = cur.x;
                    prev[next.x][next.y].py = cur.y;
                    prev[next.x][next.y].pp = cur.hp;
                    
                    if (maze[next.x][next.y] == '.')
                        next.hp = 0;
                    else
                        next.hp = maze[next.x][next.y] - '0';
                    
                    q.push(next);
                }
            }/* End of For */
        }/* End of Else */
    }/* End of While */
    if (!IsSolve)
    {
        printf("God please help our poor hero.\n");
    }
}/* bfs */

int main()
{
#ifdef judge
    freopen("E:\\hdoj1026.txt", "r", stdin);
    freopen("E:\\hdoj1026(result).txt", "w", stdout);
#endif

    while (~scanf("%d %d", &nNum, &mNum))
    {
        memset(vis, 0, sizeof(vis));
        memset(maze, 0, sizeof(maze));
        memset(prev, 0, sizeof(prev));
        
        for (int i=0; i<nNum; ++i)
            scanf("%s", maze[i]);
            
        bfs();
        printf("FINISH\n");
    }/* End of While */
    
    return 0;
}
