#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

int  nNum, mNum;
int  i, j, sum, max;
int  vis[1010][100];
char graph[1010][100];

void dfs(int x, int y)
{
    if (x<0 || y<0 || x>=nNum || y>=mNum
            || vis[x][y] || graph[x][y]=='.')
    {
        return ;
    }
    else
    {
        ++sum;
        vis[x][y] = 1;
        dfs(x-1, y); dfs(x+1, y);
        dfs(x, y-1); dfs(x, y+1);
    }
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj3051.txt", "r", stdin);
    freopen("E:\\poj3051(result).txt", "w", stdout);
#endif

    while (2 == scanf("%d %d", &mNum, &nNum))
    {
        getchar();
        memset(vis, 0, sizeof(vis));
        memset(graph, 0, sizeof(graph));
        
        for (i=0; i<nNum; ++i)
        {
            scanf("%s", graph[i]);
        }/* End of For */
        
        max = -1;
        for (i=0; i<nNum; ++i)
        {
            for (j=0; j<mNum; ++j)
            {
                if (vis[i][j]==0 && graph[i][j]=='*')
                {
                    sum = 0;
                    dfs(i, j);
                    if (max < sum)
                    {
                        max = sum;
                    }
                }/* End of If */
            }
        }/* End of For */
        
        printf("%d\n", max);
    }/* End of While */
    
    return 0;
}
