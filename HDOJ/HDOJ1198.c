#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define LOCAL

char ch[55][55] = {0};
int  i, j, a, b;
int  nNum, mNum, ans;
int  rank[3000];
int  parent[3000];
int  graph[][4] = {
                    1, 0, 1, 0,
                    1, 0, 0, 1,
                    0, 1, 1, 0,
                    0, 1, 0, 1,
                    1, 1, 0, 0,
                    0, 0, 1, 1,
                    1, 0, 1, 1,
                    1, 1, 1, 0,
                    0, 1, 1, 1,
                    1, 1, 0, 1,
                    1, 1, 1, 1
                  }; /* 记录A-k可通行方向，1表示可通行 */
                    
int IsInBound(int x, int y)
{
    if (x<0 || y<0)
    {
        return 0;
    }
    
    return 1;
}/* IsInBound */

int FindSet(int k)
{
    while (k != parent[k])
    {   /* 找到 k 所从属的集合 */ 
        k = FindSet(parent[k]);
    }
    
    return k;
}/* FindSet */

void Union(int x, int y)
{
    /* 查找其自身所从属的集合 */ 
    x = FindSet(x);
    y = FindSet(y);
    if (x == y)
    {
        return ;
    }/* End of If */
    
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
    }
}/* Union */

int main()
{
#ifdef LOCAL
    freopen("E:\\hdoj1198.txt", "r", stdin);
    freopen("E:\\hdoj1198(result).txt", "w", stdout);
#endif

    while (2==scanf("%d %d", &mNum, &nNum), mNum>0)
    {
        getchar();
        memset(ch, 0, sizeof(ch));
        for (i=0; i<mNum; ++i)
        {   
            scanf("%s", &ch[i]);  
        }/* End of For */
        
        for (i=0; i<mNum*nNum; ++i)
        {
            rank[i] = 0;   /* 初置集合元素的秩为0 */ 
            parent[i] = i; /* 初置集合元素指向自身 */
        }/* End of For */
        
        for (i=0; i<mNum; ++i)
        {
            for (j=0; j<nNum; ++j)
            {
                if (IsInBound(i-1, j))
                {   /* 判断其上方是否连通 */ 
                    if (graph[ch[i][j]-'A'][0] && graph[ch[i-1][j]-'A'][1])
                    {   /* 合并集合 */
                        a = (i-1)*nNum + j;
                        b = i*nNum + j;
                        Union(a, b);
                    }
                }
                if (IsInBound(i, j-1))
                {   /* 判断其左方是否连通 */ 
                    if (graph[ch[i][j]-'A'][2] && graph[ch[i][j-1]-'A'][3])
                    {   /* 合并集合 */
                        a = i*nNum + j-1;
                        b = i*nNum + j;
                        Union(a, b);
                    }
                }/* End of If */
            }
        }/* End of For */

        ans = 0;
        for (i=0; i<nNum*mNum; ++i)
        {
            if (FindSet(i) == i)
            {
                ++ans;
            }
        }
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
