#include <stdio.h>

#define onlinejudge
#define maxn  31

char maze[maxn][maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  rNum, cNum, vis[maxn][maxn], cnt, IsSolved;

int IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=rNum || y>=cNum)
        return 0;
    
    return 1;
}/* IsInBound */

void dfs(int x, int y, int ti)
{
    int i, nx, ny;
    
    if (x==rNum-1 && y==cNum-1)
    {
        IsSolved = 1;
        if (ti < cnt)
            cnt = ti; /* Search for the shortest path */
    }
    else
    {
        for (i=0; i<4; ++i)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            
            if (!vis[nx][ny] && IsInBound(nx, ny)
                && maze[nx][ny]=='0')
            {
                vis[nx][ny] = 1;
                dfs(nx, ny, ti+1); /* dfs for next step */
                vis[nx][ny] = 0;
            }
        }
    }/* End of Else */
    
    return ;
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1530.txt", "r", stdin);
    freopen("E:\\hdoj1530(ans).txt", "w", stdout);
#endif

    int i, j;
    
    while (~scanf("%d %d", &rNum, &cNum))
    {
        for (i=0; i<rNum; ++i)
        {
            for (j=0; j<cNum; ++j)
            {
                maze[i][j] = '0';
                vis[i][j] = 0;
            }
        }/* End of For */
        
        for (i=0; i<rNum; ++i)
            scanf("%s", maze[i]);
        /******
        printf("\n");
        for (int i=0; i<rNum; ++i)
        {
            for (int j=0; j<cNum; ++j)
                printf("%c", maze[i][j]);
            
            printf("\n");
        }
        *****/
        IsSolved = 0;
        cnt=0x3F3F3F3F;
        dfs(0, 0, 0);
        
        if (IsSolved)
            printf("%d\n", cnt);
        else
            printf("Impossible!\n");
    }/* End of While */
    
    return 0;
}
