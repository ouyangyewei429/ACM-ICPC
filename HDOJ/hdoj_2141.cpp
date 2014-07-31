#include <stdio.h>
#include <stdlib.h>

//#define onlinejudge

const int maxn = 504;

int     L, N, M, S, casenum=1;
__int64 x, a[maxn], b[maxn], c[maxn], sum[maxn*maxn];

int compare(const void *a, const void *b)
{
    return *(__int64 *)a - *(__int64 *)b;
}/* compare */

void bin()
{
    int i, j, k=0;
    for (i=0; i<L; ++i)
    {
        for (j=0; j<N; ++j)
            sum[k++] = a[i]+b[j];
    }/* End of For */
    
    qsort(sum, k-1, sizeof(sum[0]), compare);
}/* bin */

bool solve(__int64 t)
{
    int l=0, r=L*N-1, m=(l+r)>>1;
    
    while (l <= r)
    {
        if (t == sum[m])
            return true;
        else if (t <= sum[m])
            r = m-1;
        else
            l = m+1;
            
        m = (l+r)>>1;
    }/* End of While */
    
    return false;
}/* solve */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2141.txt", "r", stdin);
    freopen("E:\\hdoj_2141_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &L, &N, &M))
    {
		int i, j, k;

        for (i=0; i<L; ++i)
            scanf("%I64d", &a[i]);
        for (i=0; i<N; ++i)
            scanf("%I64d", &b[i]);
        for (i=0; i<M; ++i)
            scanf("%I64d", &c[i]);
        
        bin();
        printf("Case %d:\n", casenum++);
        
        scanf("%d", &S);
        for (i=0; i<S; ++i)
        {
            bool sign = false;
            scanf("%I64d", &x);
            for (k=0; k<M; ++k)
            {
                if (solve(x-c[k]))
                {
                    sign = true;
                    break;
                }    
            }
            if (sign)
                printf("YES\n");
            else
                printf("NO\n");
        }/* End of For */
    }/* End of While */
    
    return 0;
}
