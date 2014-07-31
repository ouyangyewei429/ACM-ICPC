/*
PROG:   Rank
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define DEBUG 0
#define maxn  504

bool hash[maxn][maxn];
int  T, N, M, cnt, graph[maxn][maxn];

bool dfs(int start, int dest)
{
    if (start == dest)
        return true;
    
    int i;
    for (i=1; i<=N; ++i)
    {
        if (!hash[start][i] && graph[start][i])
        {
            hash[start][i] = true;
            if ( dfs(i, dest) )
                return true;

            hash[start][i] = false;
        }
    }/* search */
    
    return false;
}/* dfs */

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1704.txt", "r", stdin);
    freopen("E:\\hdoj_1704_ans.txt", "w", stdout);
#endif

    int i, j, a, b;
    
    scanf("%d", &T);
    while ( T-- )
    {
        scanf("%d %d", &N, &M);
        memset(graph, 0, sizeof(graph));
        
        for (i=1; i<=M; ++i)
        {
            scanf("%d %d", &a, &b);
            graph[a][b] = 1;
        }/* Merge */
    
        cnt = 0;
        for (i=1; i<=N; ++i)
        {
            for (j=i+1; j<=N; ++j)
            {
                memset(hash, false, sizeof(hash));
                if ( !dfs(i, j) )
                    ++cnt;
            }
        }/* counting */
        
        printf("%d\n", cnt);
    }/* End of while */
    
    return 0;
}
