#include <queue>
#include <stdio.h>
#include <memory.h>
using namespace std;

const int maxn = 100;

char maze[maxn][maxn];
bool hash[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  n, m, t, p, sx, sy, tx, ty, casenum=1;
struct Graph
{
    int x, y, sec, magic;
};

void bfs(int x, int y, int mag)
{
    queue <Graph> q;
    struct Graph cur, next;
    
    cur.x = x;
    cur.y = y;
    cur.sec = 0;
    cur.magic = mag;
    hash[x][y] = true;
    
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if (cur.x==tx && cur.y==ty)
        {
            if (sec <= t)
                printf("Yes, Yifenfei will kill Lemon at %d sec.\n", cur.sec);  
            else
                printf("Poor Yifenfei, he has to wait another ten thousand years.\n");
            return ;
        }/* End of IF */
        
        if (maze[cur.x][cur.y] == '.')
        {
            cur
        }
        else if ()
        {
            
        }
        else
        {
            for (int i=0; i<4; ++i)
            {
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                
                if ()
            }
        }
    }
}/* bfs */

int main()
{
    while (~scanf("%d %d %d %d", &n, &m, &t, &p))
    {
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
            {
                hash[i][j] = false;
                scanf("%1s", &maze[i][j]);
                if (maze[i][j] == 'Y')
                    sx = i, sy = j;
                if (maze[i][j] == 'L')
                    tx = i, ty = j;
            }
        }/* End of For */
        
        printf("Case %d:\n", casenum++);
        bfs(sx, sy, p);
    }/* End of While */
    
    return 0;
}
