#include <stdio.h>
#include <string.h>

//#define onlinejudge

const int maxn = 104;

char maze[maxn][maxn];
int  cas, n, m, ans, vis[maxn][maxn], graph[maxn][maxn];

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return false;
    
    return true;
}/* IsInBound */

void dfs(int x, int y)
{
    if (!vis[x][y] && IsInBound(x, y) && maze[x][y]=='#')
    {
        vis[x][y] = 1;
        dfs(x, y-1); dfs(x-1, y);
        dfs(x, y+1); dfs(x+1, y);
    }
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2952.txt", "r", stdin);
    freopen("E:\\hdoj_2952_ans.txt", "w", stdout);
#endif

    scanf("%d", &cas);
    while (cas--)
    {
        memset(vis, 0, sizeof(vis));
        memset(graph, -1, sizeof(graph));
        
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; ++i)
            scanf("%s", maze[i]);
        
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
            {
                if (!vis[i][j] && maze[i][j]=='#')
                {
                    dfs(i, j);
                    graph[i][j] = 1;
                }    
            }
        }/* End of For */
        
        ans = 0;
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
            {
                if (graph[i][j] == 1)
                    ++ans;
                    
            }
        }/* End of For */
        
        //printf("\n");//---------------------------------
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
