#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

#define localjudge

const int maxn = 110;
int mNum, nNum, parent[maxn], rank[maxn];
struct Graph
{
    int u, v, w;
}edge[maxn];

int compare(const void *a, const void *b)
{
    return (*(Graph *)a).w - (*(Graph *)b).w;
}/* compare */

int FindSet(int k)
{
    while (k != parent[k])
        k = parent[k];
    
    return k;
}/* FindSet */

void Merge(int x, int y)
{
    x = FindSet(x);
    y = FindSet(y);
    
    if (x == y)
        return ;
    
    /* path compression */
    if (rank[x] > rank[y])
        parent[y] = x;
    else
    {
        if (rank[x] == rank[y])
            ++rank[y];
        
        parent[x] = y;
    }
}/* Merge */

int Kruskal()
{
    int sn1, sn2, edgeNum=0, lowcost=0;
    
    for (int i=0; i<mNum; ++i)
    {
        sn1 = FindSet(edge[i].u);
        sn2 = FindSet(edge[i].v);
        
        if (sn1 != sn2)
        {   /* vertex u and w are not in the same set,
             * so it won't form a ring
             */
            lowcost += edge[i].w;
            ++edgeNum;
            
            Merge(edge[i].u, edge[i].v);
        }
    }/* End of For */
    if (edgeNum == mNum-1)
        return lowcost;
    else
        return 0;
}/* Kruskal */

int main()
{
#ifdef localjudge
    freopen("E:\\hdoj1863.txt", "r", stdin);
    freopen("E:\\hdoj1863(result).txt", "w", stdout);
#endif

    while (~scanf("%d %d", &nNum, &mNum), nNum!=0)
    {
        memset(edge, 0, sizeof(edge));
        
        /* Initialize the Union_Find_Set */
        for (int i=1; i<=mNum; ++i)
        {
            rank[i] = 0;
            parent[i] = i;
        }

        for (int i=0; i<nNum; ++i)
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        
        /* Edge Weight Sorting in ascending order */
        qsort(edge, nNum, sizeof(edge[0]), compare);
        
        int ans = Kruskal();
        if (ans)
            printf("%d\n", ans);
        else
            printf("?\n");
    }/* End of While */
    
    return 0;
}
