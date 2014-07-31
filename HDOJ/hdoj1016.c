#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int nNum, casenum=1;
int vis[30];   /* 设置访问数组 */ 
int seq[30];   /* 保存序列 */ 
int IsPrime[50] = {1, 1, 0};  /* 保存40以内的素数 */ 

void DFS(int cur)
{
    int i;
    if (cur==nNum+1 && (!IsPrime[1+seq[cur-1]]))
    {   /* 退出条件，当前seq保存一种情况的素数环 */
        for (i=1; i<=nNum; ++i)
        {
            printf(i==1? "%d":" %d", seq[i]);
        }
        printf("\n");
        
        return ;
    }/* End of If */

    for (i=2; i<=nNum; ++i)
    {   /* 试探性放置一个数字，看是否满足条件 */ 
        if (vis[i]==0 && (!IsPrime[seq[cur-1]+i]))
        {   /* 与前面的数字之和是素数 */
            vis[i] = 1;     /* 设置为已被访问 */ 
            seq[cur] = i;   /* 保存当前值 */ 
            DFS(cur+1);     /* 继续访问下一个位置 */
            vis[i] = 0;     /* 重新设置为未被访问 */ 
        }
    }
}/* DFS */

int main()
{
    int i, j;
    for (i=2; i<=(int)sqrt(40); ++i)
    {
        if (!IsPrime[i])
        {
            for (j=i*i; j<=40; j+=i)
            {
                IsPrime[j] = 1;
            }
        }
    }/* End of For */

    while (1 == scanf("%d", &nNum))
    {
        if ((nNum&1) == 0)
        {   /* 只有当 N 为偶数时才能形成素数环 */ 
            memset(vis, 0, sizeof(vis));
            printf("Case %d:\n", casenum++);
    
            seq[1] = 1;
            DFS(2); /* 从位置 2 开始搜索，因为起点始终是从 1 开始 */
            
            printf("\n");
        }     
    }/* End of While */

    return 0;
}
