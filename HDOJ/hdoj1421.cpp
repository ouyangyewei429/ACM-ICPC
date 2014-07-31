#include <stdio.h>

#define onlinejudge

int casenum, kNum, mNum;
int u, v, edge[110];

int FindSet(int k)
{
    while (k != edge[k])
        k = edge[k];
    
    return k;
}/* FindSet */

void Merge(int x, int y)
{
    int r1 = FindSet(x);
    int r2 = FindSet(y);
    
    if (r1 == r2)
        return ;
    
    if (r1 > r2)
        edge[r1] = r2; 
    else
        edge[r2] = r1;
        
    return ;
}/* Merge */

int main()
{
#ifdef onlinejudge
    freopen("E:\\bcl1421.txt", "r", stdin);
    freopen("E:\\bcl1421(ans).txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {        
        scanf("%d %d", &kNum, &mNum);
        
        /* Initialized */
        for (int i=0; i<kNum; ++i)
            edge[i] = i;
        
        /* Union_Find_Set */
        for (int i=0; i<mNum; ++i)
        {
            scanf("%d %d", &u, &v);
            Merge(u, v);
        }
        
        /****
        for (int i=0; i<kNum; ++i)
            printf("%d ", edge[i]);
        printf("\n");
        ****/
        
        /* Count the connected component */
        int ans = 0;
        for (int i=0; i<kNum; ++i)
        {
            if (edge[i] == i)
                ++ans;
        }
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
