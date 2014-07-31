#include <stdio.h>
#include <memory.h>

//#define onlinejudge

const int maxn = 101;

char ans[maxn*maxn];
int  n, m, casenum, grids, cnt, hash[maxn][maxn];
int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};

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
        
        if (!hash[nx][ny] && IsInBound(nx, ny))
        {
            ++grids;
            ans[cnt++] = ny+'A';  // col
            ans[cnt++] = nx+'1';  // row
            
            hash[nx][ny] = 1;
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
        //memset(ans, 0, sizeof(ans));
        memset(hash, 0, sizeof(hash));
        
        scanf("%d %d", &n, &m);
        
        grids = 1;
        hash[0][0] = 1;
        ans[0]='A', ans[1]='1';
        
        cnt = 2;
        dfs(0, 0);
        ans[cnt] = '\0';
        
        printf("Scenario #%d:\n", k);
        if (grids != n*m)
            printf("impossible\n");
        else
            printf("%s\n", ans);
        printf("\n");
    }/* End of For */
    
    return 0;
}
