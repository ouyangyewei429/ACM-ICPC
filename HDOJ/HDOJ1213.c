#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define LOCAL

int i, ans;
int xNum, yNum;
int tNum, nNum, mNum;
int rank[1010];     /* 保存集合的秩 */
int parent[1010];   /* 保存集合各元素从属的集合 */

int FindSet(int k)
{
    if (k != parent[k])
    {
        k = FindSet(parent[k]);
    }/* End of If */
    
    return k;
}

void Union(int x, int y)
{
    /* 查找x，y所从属的集合 */ 
    x = FindSet(x);
    y = FindSet(y);
    if (x == y)
    {
        return ;
    }
    
    /* 路径压缩 */ 
    if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else
    {
        if (rank[x] == rank[y])
        {
            ++rank[y];
        }
        parent[x] = y;
    }/* End of Else */
}

int main()
{
#ifdef LOCAL
    freopen("E:\\hdoj1213.txt", "r", stdin);
    freopen("E:\\hdoj1213(result).txt", "w", stdout);
#endif

    scanf("%d", &tNum);
    while (tNum--)
    {
        scanf("%d %d", &nNum, &mNum);
        
        for (i=1; i<=nNum; ++i)
        {   /* 初置集合元素 */ 
            rank[i] = 0;
            parent[i] = i;
        }/* End of For */
        
        for (i=0; i<mNum; ++i)
        {
            scanf("%d %d", &xNum, &yNum);
            Union(xNum, yNum); /* 合并两个集合 */ 
        }/* End of For */
        
        ans = 0;
        for (i=1; i<=nNum; ++i)
        {   /* 统计集合的个数，如果parent指向自身，说明是一个单独的集合 */ 
            if (parent[i] == i)
            {
                ++ans;
            }
        }/* End of For */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
