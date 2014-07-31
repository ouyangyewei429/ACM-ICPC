#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define INF (1<<30)

const int maxn = 504;
const int hsize = 300001;

bool    flag;
int     L, N, M, S, casenum=1;
__int64 X, a[maxn], b[maxn], c[maxn], hash[hsize];

void insert(__int64 xx)
{
    __int64 t=xx%hsize;
    
    if (t < 0)
        t += hsize;
    for (; hash[t]&&t<=hsize; )
        t = (t+1)%hsize;
    
    if (hash[t]==0 && t<=hsize)
        hash[t] = xx;
}/* insert */

bool Find(__int64 xx)
{
    __int64 t=xx%hsize;
    
    if (t < 0)
        t += hsize;
    for (; hash[t]&&hash[t]!=xx&&t<=hsize; )
        t = (t+1)%hsize;
    
    if (hash[t]==0 || t>hsize)
        return false;
    else if (hash[t] && hash[t]==xx)
        return true;
}/* Find */

int main()
{
    while (~scanf("%d %d %d", &L, &N, &M))
    {
        for (int i=0; i<L; ++i) scanf("%I64d", &a[i]);
        for (int i=0; i<N; ++i) scanf("%I64d", &b[i]);
        for (int i=0; i<M; ++i) scanf("%I64d", &c[i]);
        
        /* insert into hash table */
        for (int i=0; i<L; ++i)
        {
            for (int j=0; j<N; ++j)
                insert(a[i]+b[j]+INF);
        }/* End of For */
        
        scanf("%d", &S);
        printf("Case %d:\n", casenum++);
        while (S--)
        {
            flag = false;
            scanf("%I64d", &X);
            for (int k=0; k<M; ++k)
            {
                if (Find(X-c[k]+INF))
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
