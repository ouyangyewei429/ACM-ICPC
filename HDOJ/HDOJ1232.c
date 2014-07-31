#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define LOCAL

int i, ans;
int nNum, mNum;
int xNum, yNum;

struct node
{
    int rank;   /* 记录集合的秩 */ 
    int parent; /* 记录集合的相亲 */ 
}t[1010];

int FindSet(int k)
{   /* 查找 k 所从属的集合 */ 
    if (k != t[k].parent)
    {
        k = FindSet(t[k].parent);
    }/* End of If */
    
    return k;
}

void Union(int x, int y)
{
    /* 寻找 x，y 所属的集合 */ 
    x = FindSet(x);
    y = FindSet(y);
    if (x == y)
    {
        return ;
    }
    
    /* 路径压缩 */ 
    if (t[x].rank > t[y].rank)
    {
        t[y].parent = x;
    }
    else
    {
        if (t[x].rank == t[y].rank)
        {
            ++t[y].rank;
        }
        t[x].parent = y;
    }/* End of Else */
}

int main()
{
#ifdef LOCAL
    freopen("E:\\hdoj1232.txt", "r", stdin);
    freopen("E:\\hdoj1232(result).txt", "w", stdout);
#endif

    while (2 == scanf("%d %d", &nNum, &mNum), nNum!=0)
    {
        for (i=1; i<=nNum; ++i)
        {   /* 初置集合 */ 
            t[i].rank = 0;
            t[i].parent = i;
        }/* End of For */
        
        for (i=0; i<mNum; ++i)
        {
            scanf("%d %d", &xNum, &yNum);
            Union(xNum, yNum);    /* 合并两个集合 */
        }
        
        ans = -1;
        for (i=1; i<=nNum; ++i)
        {   /* 统计一下相亲为自身的城镇数，最后减去一就是answer */ 
            if (t[i].parent == i)
            {
                ++ans;
            }
        }/* End of For */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
