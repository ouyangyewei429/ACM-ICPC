#include <queue>
#include <stdio.h>
using namespace std;

#define onlinejudge

const int maxn = 24;

bool keys[15];
char maze[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  n, m, sx, sy, tx, ty, lim, boom[maxn][maxn];
struct Graph
{
    int x, y, t;
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
    boom[sx][sy] = cur.t = lim;
    
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if (cur.x==tx && cur.y==ty && cur.t>0)
            return lim-cur.t;
        
        for (int i=0; i<4; ++i)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            next.t = cur.t - 1;
            
            if (IsInBound(next.x, next.y) && cur.t>1
                && maze[next.x][next.y]!='*')
            {
                if (maze[next.x][next.y]>='a' && maze[next.x][next.y]<='j')
                {
                    
                }
            }
        }/* End of For */
    }/* End of While */

    return -1;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1429.txt", "r", stdin);
    freopen("E:\\hdoj_1429_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &n, &m, &lim))
    {
        memset(key, false, sizeof(key));
        
        for (int i=0; i<n; ++i)
        {
            getchar();
            for (int j=0; j<m; ++j)
            {
                boom[i][j] = 0;
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == '@')
                    sx = i, sy = j;
                if (maze[i][j] == '^')
                    tx = i, ty = j;
            }
        }/* End of For */
        
        printf("%d\n", bfs());
    }/* End of While */
    
    return 0;
}
