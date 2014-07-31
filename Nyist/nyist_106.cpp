#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlinejudge

int i, casenum, N, K, ans;
struct knapsack
{
    int v, w;
}s[12];

int compare(const void *a, const void *b)
{
    return (*(struct knapsack *)b).v - (*(struct knapsack *)a).v;
}/* compare */

int main()
{
#ifdef onlinejudge
    freopen("E:\\nyist_106.txt", "r", stdin);
    freopen("E:\\nyist_106_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d %d", &N, &K);
        for (i=0; i<N; ++i)
            scanf("%d %d", &s[i].v, &s[i].w);
        
        qsort(s, N, sizeof(s[0]), compare);
        
        for (i=0,ans=0; i<N&&K>0; ++i)
        {
            if (K > s[i].w)
                ans += s[i].v * s[i].w, K -= s[i].w;
            else
                ans += s[i].v * K, K = 0;
        }/* End of For */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
