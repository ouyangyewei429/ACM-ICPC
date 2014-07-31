#include <stdio.h>
#include <string.h>

#define onlinejudge

const int maxn  = 24;

int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  m, n, sx, sy, ans, vis[maxn][maxn];
char maze[maxn][maxn];

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return false;
    
    return true;
}/* IsInBound */

void dfs(int x, int y)
{
    for (int i=0; i<4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (!vis[nx][ny] && IsInBound(nx, ny)
            && maze[nx][ny]=='.')
        {
            ++ans;
            
            vis[nx][ny] = 1;
            dfs(nx, ny);
            //vis[nx][ny] = 0;
        }
    }
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1312.txt", "r", stdin);
    freopen("E:\\hdoj_1312_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &m, &n), n+m!=0)
    {
        for (int i=0; i<n; ++i)
        {
            getchar();
            for (int j=0; j<m; ++j)
            {
                vis[i][j] = 0;
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == '@')
                    sx=i, sy=j;
            }
        }
        /******
        memset(vis, 0, sizeof(vis));
        memset(maze, 0, sizeof(maze));
        for (int i=0; i<n; ++i)
            scanf("%s", maze[i]);
        
        int flag=0;
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
            {
                if (maze[i][j] == '@')
                {
                    flag=1;
                    sx=i, sy=j;
                    break;
                }    
            }
            if (flag)
                break;
        }
        *****/
        /*****
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
                printf("%c", maze[i][j]);
            printf("\n");
        }
        *****/
        ans = 1;
        vis[sx][sy] = 1;
        dfs(sx, sy);
        
        printf("%d\n", ans);
        //printf("%d %d | %d\n", sx, sy, ans+1);
    }/* End of While */
    
    return 0;
}
