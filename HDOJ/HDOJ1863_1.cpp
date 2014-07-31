#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int village[110];
int i, nNum, mNum, cnt, lowcost;

struct road
{
    int u;
    int v;
    int w;
}edge[110];

int compare(const void *a, const void *b)
{
    return (*(road *)a).w - (*(road *)b).w;
}/* compare */

int FindSet(int k)
{
    while (village[k] != -1)
    {
        k = village[k];
    }
    
    return k;
}/* FindSet */

int Merge(int x, int y)
{
    int r1 = FindSet(x);
    int r2 = FindSet(y);
    
    if (r1 == r2)
    {
        return 0;
    }
    
    /* 更加巧妙的路径压缩方法，节省内存，减低时间复杂度 */ 
    if (r1 < r2)
    {
        village[r2] = r1;
    }
    else
    {
        village[r1] = r2;
    }
    
    return 1;
}/* Merge */

int main()
{
    while (2==scanf("%d %d", &nNum, &mNum), nNum)
    {
        memset(edge, 0, sizeof(edge));
        memset(village, -1, sizeof(village));
        
        for (i=0; i<nNum; ++i)
        {
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        }/* End of For */
        
        cnt = lowcost = 0;
        qsort(edge, nNum, sizeof(edge[0]), compare);
        for (i=0; i<nNum; ++i)
        {
            if (Merge(edge[i].u, edge[i].v))
            {
                ++cnt;
                lowcost += edge[i].w;
            }
            if (cnt == mNum-1)
            {
                break;
            }
        }/* End of For */
        if (cnt == mNum-1)
        {
            printf("%d\n", lowcost);
        }
        else
        {
            printf("?\n");
        }
    }/* End of While */
    
    return 0;
}
