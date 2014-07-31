#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
using namespace std;

#define onlinejudge

char maze[210][210];
int  vis[210][210];
int  i, j, nNum, mNum, sx, sy;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};

struct Node
{
    int x, y, step;
    
    bool operator < (const Node &a) const
    {
        return step > a.step;
    }
};

int IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=nNum || y>=mNum)
    {
        return 0;
    }
    
    return 1;
}/* IsInBound */

void BFS()
{
    int  k, isSolve = 0;
    Node cur, next;
    priority_queue<Node> q;
    
    cur.x = sx;
    cur.y = sy;
    cur.step = 0;
    q.push(cur);
    
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        cur = q.top();
        q.pop();
        
        if (maze[cur.x][cur.y] == 'r')
        {
            isSolve = 1;
            break;
        }
        
        for (k=0; k<4; ++k)
        {
            next.x = cur.x + dx[k];
            next.y = cur.y + dy[k];
            next.step = cur.step + 1;
            
            if (IsInBound(next.x, next.y) && !vis[next.x][next.y]
               && maze[next.x][next.y]!='#')
           {
               vis[next.x][next.y] = 1;
               if (maze[next.x][next.y] == 'x')
               {
                   ++next.step;
               }
               
               q.push(next);
           }
        }/* End of For */
    }/* End of While */
    if (isSolve)
    {
        printf("%d\n", cur.step);
    }
    else
    {
        printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
}/* BFS */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1242.txt", "r", stdin);
    freopen("E:\\hdoj1242(result).txt", "w", stdout);
#endif

    while (2 == scanf("%d %d", &nNum, &mNum))
    {
       getchar();
       memset(vis, 0, sizeof(vis));
       memset(maze, 0, sizeof(maze));
       
       for (i=0; i<nNum; ++i)
       {
           scanf("%s", maze[i]);
       }/* End of For */
       
       for (i=0; i<nNum; ++i)
       {
           for (j=0; j<mNum; ++j)
           {
               if (maze[i][j] == 'a')
               {
                   sx = i, sy = j;
               }
           }
       }/* End of For */
       
       BFS();
    }/* End of While */
    
    return 0;
}
