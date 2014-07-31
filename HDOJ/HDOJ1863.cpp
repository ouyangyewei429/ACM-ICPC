#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define LOCAL

int i, ans;
int nNum, mNum;
int rank[110] = {0};    /* 集合的秩 */ 
int parent[110] = {0};  /* 集合的从属关系 */ 
struct node
{
    int u;  /* 起点 */ 
    int v;  /* 尾点 */ 
    int w;  /* 权值 */ 
}edge[110];

/* Sorting for the edge(u,v) in ascending order*/ 
int compare(const void *a, const void *b)
{
    return (*(node *)a).w - (*(node *)b).w;
}/* Compare */

int FindSet(int k)
{
    while (k != parent[k])
    {
        k = parent[k];
    }/* End of While */
    
    return k;
}/* FindSet */

void Union(int x, int y)
{
    /* 查找元素x，y所属的集合编号 */ 
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
    }
}/* Union */

int Kruskal()
{
    int cnt = 0;    /* 统计已经生成的边数 */ 
    int result = 0; /* 记录利用kruskal算法构造最少生成树的总权值 */ 
    int j, sn1, sn2;
    
    for (j=1; j<=mNum; ++j)
    {
        /* 取一条边(u,v), sn1, sn2得到 u, v 两个顶点所属的集合编号 */ 
        sn1 = FindSet(edge[j].u);
        sn2 = FindSet(edge[j].v);
        if (sn1 != sn2)
        {   /* 两个顶点不在同一个集合，说明不会形成回路，
             * 则边（u，v）是最少生成树的一条边
             **/
             ++cnt;  /* 生成的边数增加一 */ 
             result += edge[j].w;  /* 统计最少的权值 */ 
             Union(sn1, sn2);      /* 将 u 和 v 两个顶点合并 */ 
        }
    }/* End of While */
    
    if (cnt == mNum-1)
    {   /* 生成边数为 M-1 时说明最少生成树构造完成 */ 
        return result;
    }
    else
    {
        return 0;
    }
}/* Kruskal */

int main()
{
#ifdef LOCAL
    freopen("E:\\hdoj1863.txt", "r", stdin);
    freopen("E:\\hdoj1863(result).txt", "w", stdout);
#endif

    while (2==scanf("%d %d", &nNum, &mNum), nNum!=0)
    {
        memset(edge, 0, sizeof(edge));
        for (i=1; i<=nNum; ++i)
        {
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        }/* End of For */
        
        /* 初始化并查集树 */
        for (i=1; i<=mNum; ++i)
        {   /* 注意i从1开始 */ 
            rank[i] = 0;
            parent[i] = i;
        }/* End of For */
        
        /* 对edge的边集进行升序排序 */ 
        qsort(edge, mNum, sizeof(edge[0]), compare);
        
        ans = Kruskal(); // 利用Kruskal算法构造最少生成树
        if (ans)
        {
            printf("%d\n", ans);
        }
        else
        {
            printf("?\n");
        }
    }/* End of While */
    
    return 0;
}
