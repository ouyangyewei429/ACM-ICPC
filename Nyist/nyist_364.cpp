#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//#define onlinejudge

int i, N, ans, tian[1004], king[1004];

inline int compare_1(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}/* compare */

inline int compare_2(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}/* compare */

int main()
{
#ifdef onlinejudge
    freopen("E:\\nyist_364.txt", "r", stdin);
    freopen("E:\\nyist_364_ans.txt", "w", stdout);
#endif

    while (EOF != scanf("%d", &N))
    {
        for (i=0; i<N; ++i)
            scanf("%d", &tian[i]);
        for (i=0; i<N; ++i)
            scanf("%d", &king[i]);
        
        qsort(tian, N, sizeof(tian[0]), compare_1);
        qsort(king, N, sizeof(king[0]), compare_2);
        
        for (i=0,ans=0; i<N; ++i)
        {
            if (tian[i] > king[i])
                ans += 200;
        }/* End of For */
        
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
