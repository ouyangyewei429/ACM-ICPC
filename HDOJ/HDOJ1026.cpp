#include <queue>
#include <cstdio>
#include <ctype.h>
#include <cstdlib>
#include <cstring>
#include <memory.h>
using namespace std;

#define onlinejudge

const int MAXSIZE = 110;
char  maze[MAXSIZE][MAXSIZE];
int   nNum, mNum, vis[MAXSIZE][MAXSIZE];
int   dx[] = {-1, 1, 0, 0};
int   dy[] = {0, 0, -1, 1};  

struct Node
{
    int x;
    int y;
    int step;
};

struct parent
{
    int px;
    int py;
}prev[MAXSIZE][MAXSIZE];

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=nNum || y>=mNum)
    {
        return false;
    }
    
    return true;
}/* IsInBound */

void dfs(int x, int y)
{
    if (prev[x][y].px+prev[x][y].py != 0)
    {
        dfs(prev[x][y].px, prev[x][y].py);
    }/* End of If */
    
    printf("%d %d\n", x, y);
    return ;
}

void bfs()
{
    queue <Node> q;
    bool IsSolve = false;
    struct Node cur = {0};
    struct Node next = {0};
    
    cur.x = 0;
    cur.y = 0;
    cur.step = 0;
    q.push(cur);
    
    vis[cur.x][cur.y] = 1;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if (cur.x==nNum-1 && cur.y==mNum-1)
        {
            IsSolve = true;
            //printf("It takes %d seconds to reach the target position, let me show you the way.\n", cur.step);
            //dfs(cur.x, cur.y);
            break;
        }/* End of If */
        
        if (maze[cur.x][cur.y]>='1' && maze[cur.x][cur.y]<='9')
        {
            int temp = maze[cur.x][cur.y] - '1';
            if (temp == 0)
            {
                maze[cur.x][cur.y] = '.';
            }
            else
            {
                maze[cur.x][cur.y] = temp + '0';
            }

            ++cur.step;
            
            ////////////////////////////////
            printf("%d %d %d %c\n", cur.x, cur.y, cur.step, maze[cur.x][cur.y]);
            ////////////////////////////////
            
            vis[cur.x][cur.y] = 1;
            q.push(cur);
        }/* End of If */
        else
        {
            for (int i=0; i<4; ++i)
            {
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                next.step = cur.step + 1;
                
                if (!vis[next.x][next.y] && IsInBound(next.x, next.y) && maze[next.x][next.y]!='X')
                {
                    ////////////////////////////////
                    printf("%d %d %d %c\n", next.x, next.y, next.step, maze[cur.x][cur.y]);
                    ////////////////////////////////
                    
                    vis[next.x][next.y] = 1;
                    prev[next.x][next.y].px = cur.x;
                    prev[next.x][next.y].py = cur.y;
                    q.push(next);
                }
            }
        }/* End of Else */
    }/* End of While */
    if (!IsSolve)
    {
        printf("God please help our poor hero.\n");
    }
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1026.txt", "r", stdin);
    freopen("E:\\hdoj1026(result).txt", "w", stdout);
#endif

    while (~scanf("%d %d", &nNum, &mNum))
    {
        getchar();
        memset(vis, 0, sizeof(vis));
        memset(maze, 0, sizeof(maze));
        memset(prev, 0, sizeof(prev));
        
        for (int i=0; i<nNum; ++i)
        {
            scanf("%s", maze[i]);
        }/* End of For */
        
        bfs();
    }/* End of While */
    
    return 0;
}
