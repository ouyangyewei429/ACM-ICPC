#include <stdio.h>
#include <memory.h>

//#define onlinejudge

const int maxn = 1004;

char maze[maxn][maxn];
bool hash[maxn][maxn];
int  n, m, sx, sy, tx, ty, min;
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};

bool IsInBound(int x, int y)
{
    if (x<=0 || y<=0 || x>n || y>m)
        return false;
    
    return true;
}/* IsInBound */

void dfs(int x, int y, int digs)
{
    if (x==tx && y==ty && min>digs)
    {
        min = digs;
        return ;
    }/* End of If */
    
    for (int i=0; i<4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (!hash[nx][ny] && IsInBound(nx, ny))
        {
            hash[nx][ny] = true;
            if (maze[nx][ny] == 'X')
                dfs(nx, ny, digs);
            else
                dfs(nx, ny, digs+1);
            hash[nx][ny] = false;
        }
    }
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2822.txt", "r", stdin);
    freopen("E:\\hdoj_2822_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &n, &m), n+m!=0)
    {
        for (int i=1; i<=n; ++i)
        {
            getchar();
            for (int j=1; j<=n; ++j)
            {
                hash[i][j] = false;
                scanf("%c", &maze[i][j]);
            }
        }/* End of For */
        
        scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
        
        min = 0x3F3F3F3F;
        hash[sx][sy] = true;
        dfs(sx, sy, 0);
        
        printf("%d\n", min);
    }/* End of While */
    
    return 0;
}
