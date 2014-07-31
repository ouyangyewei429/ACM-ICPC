#include <stdio.h>
#include <memory.h>

//#define onlinejudge

const int maxn = 101;

int casenum, n, m, grids, vis[maxn][maxn];
int dir[8][2] = {{-1,}}
struct Graph
{
    int  row;
    char col;
}path[maxn*maxn];

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return false;
    
    return true;
}/* IsInBound */

void dfs(int x, int y)
{
    for (int i=0; i<8; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (!vis[nx][ny] && IsInBound(nx, ny))
        {
            ++grids;
            vis[nx][ny] = 1;
            path[grids].row = nx+1;
            path[grids].col = ny+'A';
            
            dfs(nx, ny);
        }
    }
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj_2488.txt", "r", stdin);
    freopen("E:\\poj_2488_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    for (int k=1; k<=casenum; ++k)
    {
        memset(vis, 0, sizeof(vis));
        //memset(path, 0, sizeof(path));
        
        scanf("%d %d", &n, &m);
        
        grids = 1;
        vis[0][0] = 1;
        dfs(0, 0);
        
        printf("Scenario #%d:\n", k);
        if (grids != n*m)
            printf("impossible\n");
        else
        {
            printf("A1");
            for (int i=2; i<=n*m; ++i)
                printf("%c%d", path[i].col, path[i].row);
            printf("\n");
        }
        printf("\n");
    }/* End of For */
    
    return 0;
}
