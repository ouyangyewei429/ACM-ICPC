/*
PROG:   哈密顿绕行世界问题
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

//#define onlinejudge

const int maxn = 24;

bool hash[maxn], mat[maxn][maxn];
int  a, b, c, M, routes, path[maxn];

void dfs(int city, int cnt)
{
    //------------------------------------
    //printf("%d %d\n", city, cnt);
    //-------------------------------------
    
    if (cnt==20 && city==M)
    {
        printf("%d:  %d", routes++, M);
        for (int i=0; i<20; ++i)
            printf(" %d", path[i]);
        printf("\n");
        
        return ;
    }/* End of IF */
    
    for (int i=1; i<=20; ++i)
    {
        if (!hash[i] && mat[city][i])
        {
            hash[i]=true, path[cnt]=i;
            dfs(i, cnt+1);
            hash[i]=false, path[cnt]=0;
        }
    }/* End of For */
    
    return ;
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2181.txt", "r", stdin);
    freopen("E:\\hdoj_2181_ans.txt", "w", stdout);
#endif

    for (int i=1; i<=20; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        mat[i][a] = mat[i][b] = mat[i][c] = true;
    }/* End of For */
    
    while (~scanf("%d", &M), M!=0)
    {
        memset(hash, false, sizeof(hash));
        
        routes = 1;
        dfs(M, 0);
    }/* End of While */
    
    return 0;
}
