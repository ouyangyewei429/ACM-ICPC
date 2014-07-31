#include <queue>
#include <stdio.h>
using namespace std;

//#define onlinejudge

const int maxn = 10;

int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  casenum, n, m, sx, sy, maze[maxn][maxn], boom[maxn][maxn];
struct Graph
{
    int x, y, t, bom;
};

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return false;
    
    return true;
}/* IsInBound */

int bfs()
{
    queue <Graph> q;
    struct Graph cur, next;
    
    cur.x = sx;
    cur.y = sy;
    cur.t = 0;
    cur.bom = boom[sx][sy] = 6;
    
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if (maze[cur.x][cur.y]==3 && cur.bom>0)
            return cur.t;
        
        for (int i=0; i<4; ++i)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            next.t = cur.t + 1;
            
            if (IsInBound(next.x, next.y) && maze[next.x][next.y]
                && cur.bom>1)
            {
                if (maze[next.x][next.y] == 4)
                {   /* Boom Reset Place */
                    if (boom[next.x][next.y] < 6)
                    {
                        next.bom = boom[next.x][next.y] = 6;
                        q.push(next);
                    }    
                }
                else
                {   /* Other grids */
                    if (boom[next.x][next.y] < cur.bom-1)
                    {
                        next.bom = boom[next.x][next.y] = cur.bom - 1;
                        q.push(next);
                    }
                }
            }
        }/* End of For */
    }/* End of While */
    
    return -1;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1072.txt", "r", stdin);
    freopen("E:\\hdoj_1072_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
            {
                boom[i][j] = 0;
                scanf("%d", &maze[i][j]);
                if (maze[i][j] == 2)
                    sx = i, sy = j;
            }
        }/* End of For */
        
        printf("%d\n", bfs());
    }/* End of While */
    
    return 0;
}
