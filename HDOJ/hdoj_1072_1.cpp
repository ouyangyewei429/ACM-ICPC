#include <stdio.h>

#define onlinejudge

const int maxn = 10;

bool IsSolved, hash[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  casenum, n, m, sx, sy, min, maze[maxn][maxn];

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return false;
    
    return true;
}/* IsInBound */

void dfs(int x, int y, int ti, int bt)
{
    //-------------------------------------
    printf("%d %d %d %d\n", x, y, ti, bt);
    //-------------------------------------
    
    if (maze[x][y]==3 && bt>0)
    {
        IsSolved = true;
        if (ti < min)
            min = ti;
        return ;
    }/* End of If */
    
    for (int i=0; i<4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (!hash[nx][ny] && bt-1>0
            && maze[nx][ny] && IsInBound(nx, ny))
        {
            hash[nx][ny] = true;
            if (maze[nx][ny] == 4)
                dfs(nx, ny, ti+1, 6);
            else
                dfs(nx, ny, ti+1, bt-1);
            hash[nx][ny] = false;
        }
    }
}/* dfs */

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
                hash[i][j] = false;
                scanf("%d", &maze[i][j]);
                if (maze[i][j] == 2)
                    sx = i, sy = j;
            }
        }/* End of For */
        
        min = 0x3F3F3F3F;
        IsSolved = false;
        hash[sx][sy] = true;
        dfs(sx, sy, 0, 6);
        /***
        if (IsSolved)
            printf("%d\n", min);
        else
            printf("-1\n");
        ***/
        
        //-------------------------------------
        printf("\n\n");
        //-------------------------------------
    }/* End of While */
    
    return 0;
}
