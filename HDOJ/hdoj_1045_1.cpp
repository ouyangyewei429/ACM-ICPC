#include <stdio.h>
#include <memory.h>

//#define onlinejudge

const int maxn = 10;

int  n, max;
char net[maxn][maxn];

bool check(int row, int col)
{
    for (int i=col-1; i>=0; --i)
    {
        if (net[row][i] == '@')
            return false;
        if (net[row][i] == 'X')
            break;
    }
    for (int i=row-1; i>=0; --i)
    {
        if (net[i][col] == '@')
            return false;
        if (net[i][col] == 'X')
            break;
    }
    
    return true;
}/* check */

void dfs(int cnt, int ans)
{
    if (cnt == n*n)
    {
        if (ans>max)
            max = ans;
        return ;
    }
    else
    {
        int x = cnt/n;
        int y = cnt%n;
        
        //-------------------------------------------
        //printf("%d %d\n", x, y);
        //-------------------------------------------
        
        if (net[x][y]=='.' && check(x, y))
        {
            net[x][y] = '@';
            dfs(cnt+1, ans+1);
            net[x][y] = '.';
        }
        
        dfs(cnt+1, ans);
    }    
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1045.txt", "r", stdin);
    freopen("E:\\hdoj_1045_ans.txt", "w", stdout);
#endif

    while (~scanf("%d", &n), n!=0)
    {
        for (int i=0; i<n; ++i)
            scanf("%s", net[i]);
        /******
        for (int i=0; i<n; ++i)
            printf("%s\n", net[i]);
        *******/
        max = -1;
        dfs(0, 0);
        
        printf("%d\n", max);
    }/* End of While */
    
    return 0;
}
