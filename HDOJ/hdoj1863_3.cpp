#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define localjudge

const int maxn = 105;
int nNum, mNum, city[maxn];
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
    while (-1 != city[k])
        k = city[k];
    
    return k;
}/* FindSet */

bool Merge(int x, int y)
{
    int r1 = FindSet(x);
    int r2 = FindSet(y);
    
    if (r1 == r2)
        return false;
    
    if (r1 < r2)
        city[r2] = r1;
    else
        city[r1] = r2;
    
    return true;
}/* Merge */

int Kruskal()
{
    int lowcost=0, edgeNum=0;
    
    for (int i=0; i<nNum; ++i)
    {
        if (Merge(edge[i].u, edge[i].v))
        {
            ++edgeNum;
            lowcost += edge[i].w;
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
        memset(city, -1, sizeof(city));
        
        for (int i=0; i<nNum; ++i)
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
            
        qsort(edge, nNum, sizeof(edge[0]), compare);
        
        int ans = Kruskal();
        if (ans)
            printf("%d\n", ans);
        else
            printf("?\n");
    }/* End of While */
    
    return 0;
}
