#include <stdio.h>
#include <stdlib.h>

const int maxn = 504;

bool    flag;
int     L, N, M, S, casenum=1;
__int64 X, a[maxn], b[maxn], c[maxn], ab[maxn*maxn];

int compare(const void *a, const void *b)
{
    return *(__int64 *)a - *(__int64 *)b;
}/* compare */

void bin()
{
    int k=0;
    for (int i=0; i<L; ++i)
    {
        for (int j=0; j<N; ++j)
            ab[k++] = a[i]+b[j];
    }/* End of For */
    
    qsort(ab, L*N, sizeof(ab[0]), compare);
}/* bin */

bool solve(int t)
{
    int l=0, r=L*N-1, m;
    while (l <= r)
    {
        m=(l+r)>>1;
        if (t == ab[m])
            return true;
        else if (t <= ab[m])
            r = m-1;
        else if (t > ab[m])
            l = m+1;
    }/* End of While */
    
    return false;
}/* solve */

int main()
{
    while (~scanf("%d %d %d", &L, &N, &M))
    {
        for (int i=0; i<L; ++i) scanf("%I64d", &a[i]);
        for (int i=0; i<N; ++i) scanf("%I64d", &b[i]);
        for (int i=0; i<M; ++i) scanf("%I64d", &c[i]);
        
        bin();
        scanf("%d", &S);
        printf("Case %d:\n", casenum++);
        while (S--)
        {
            flag = false;
            scanf("%I64d", &X);
            for (int k=0; k<M; ++k)
            {
                if (solve(X-c[k]))
                {
                    flag = true;
                    break;
                }
            }/* End of For */
            if (flag)
                printf("YES\n");
            else
                printf("NO\n");
        }/* End of While */
    }/* End of While */
    
    return 0;
}
