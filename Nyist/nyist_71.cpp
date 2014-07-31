#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlinejudge

int i, j, tmp, casenum, N, K, ans, w[12];

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}/* compare */

int main()
{
#ifdef onlinejudge
    freopen("E:\\nyist_71.txt", "r", stdin);
    freopen("E:\\nyist_71_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d %d", &K, &N);
        for (i=0; i<N; ++i)
            scanf("%d", &w[i]);
        
        qsort(w, N, sizeof(w[0]), compare);
        
        tmp = ans = 0;
        for (i=0; i<N&&w[i]<=K; ++i)
        {
            for (j=N-1; j>i; --j)
            {
                if (w[i]+w[j] <= K)
                    ++ans, tmp+=2, w[i]=w[j]=0x3F3F3F3F;
            }
        }/* End of For */
        
        if (tmp == N)
            printf("%d\n", ans);
        else
            printf("%d\n", ans+N-tmp);
    }/* End of While */
    
    return 0;
}
