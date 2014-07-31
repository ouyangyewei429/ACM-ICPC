#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

int  nNum, mNum;
int  i, j, ans;
int  vis[110][110];
char graph[110][110];

void dfs(int x, int y)
{
    if (x<0 || y<0 || x>=nNum || y>=mNum
        || vis[x][y] || graph[x][y]=='.')
    {
        return ;
    }
    else
    {
        vis[x][y] = 1;
        
        dfs(x-1, y-1); dfs(x-1, y); dfs(x-1, y+1);
        dfs(x, y-1);                dfs(x, y+1);
        dfs(x+1, y-1); dfs(x+1, y); dfs(x+1, y+1);
    }
}/* DFS */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj2386.txt", "r", stdin);
    freopen("E:\\poj2386(result).txt", "w", stdout);
#endif

    while (2 == scanf("%d %d", &nNum, &mNum))
    {
        getchar();
        memset(vis, 0, sizeof(vis));
        memset(graph, 0, sizeof(graph));
        
        for (i=0; i<nNum; ++i)
        {
            scanf("%s", graph[i]);
        }/* End of For */
        
        /****
        for (i=0; i<nNum; ++i)
            printf("%s\n", graph[i]);
        printf("\n");
        ****/
        
        for (i=0; i<nNum; ++i)
        {
            for (j=0; j<mNum; ++j)
            {
                if (vis[i][j]==0 && graph[i][j]=='W')
                {
                    ++ans;
                    
                    dfs(i, j);
                }
            }
        }/* End of For */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
