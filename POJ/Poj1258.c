#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define INF 0x3f3f3f3f

int nNum, ans;
int mat[110][110];

int prim()
{
    int result = 0;
    int pos, min, i, j;
    int visit[110] = {0};
    int lowcost[110] = {0}; /* 保存 (pos, i)边 的最少权值 */ 
    
    /* 初置起点 */ 
    pos = 0, visit[0] = 1;
    for (i=1; i<nNum; ++i)
    {
        lowcost[i] = mat[pos][i];
    }/* End of For */
     
    /* 对 N-1 个顶点进行操作 */ 
    for (i=1; i<nNum; ++i)
    {
        min = INF;
        for (j=0; j<nNum; ++j)
        {
            if (visit[j]==0 && min>lowcost[j])
            {
                pos = j; /* 记录距离最近，边权值最少的顶点位置 */ 
                min = lowcost[j]; /* 记录当前最少边权值 */ 
            }
        }/* End of for */
        
        result += min;  /* 每次最少权值相加 */
        visit[pos] = 1; /* pos顶点设置为已被访问 */
        
        /* 更新 lowcost */ 
        for (j=0; j<nNum; ++j)
        {
            if (visit[j]==0 && lowcost[j]>mat[pos][j])
            {
                lowcost[j] = mat[pos][j];
            }
        }/* End of for */
    }/* End of For */
    
    return result;
}

int main()
{
    int i, j;
    
    while (1 == scanf("%d", &nNum))
    {
        for (i=0; i<nNum; ++i)
        {
            for (j=0; j<nNum; ++j)
            {
                scanf("%d", &mat[i][j]);
            }
        }/* End of For */
        
        ans = prim(); /* 利用 prim 算法构造最少生成树 */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
