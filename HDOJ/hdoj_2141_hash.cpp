#include <stdio.h>
#include <memory.h>

#define onlinejudge
#define INF (1<<16)

const int maxn = 504;
const int size = 300011;

int L, N, M, S, x, casenum=1;
int a[maxn], b[maxn], c[maxn], hash[size];

void HashInsert(int xx)
{
    int t;
    for (t=xx%size; t<=size&&hash[t]; t=(t+1)%size);
    if (t <= size)
        hash[t] = xx;
}/* HashFc */

bool HashFind(int xx)
{
    int t;
    for (t=xx%size; t<=size&&hash[t]!=xx; t=(t+1)%size);
    if (t<=size && hash[t]==xx)
        return true;
    else
        return false;
}/* HashFind */

bool solve(int x)
{
    for (int i=1; i<=L; ++i)
    {
        for (int j=1; j<=N; ++j)
        {
            if (HashFind(x-a[i]-b[j]+INF))
                return true;
        }/* End of For */
    }/* End of For */

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
        memset(hash, 0, sizeof(hash));
        
        for (int i=1; i<=L; ++i)
            scanf("%d", &a[i]);
        for (int i=1; i<=N; ++i)
            scanf("%d", &b[i]);
        for (int i=1; i<=M; ++i)
        {
            scanf("%d", &c[i]);
            HashInsert(c[i]+INF);
        }/* End of For */
            
        printf("Case %d:\n", casenum++);
        
        scanf("%d", &S);
        for (int i=1; i<=S; ++i)
        {
            scanf("%d", &x);
            if (solve(x))
                printf("YES\n");
            else
                printf("NO\n");
        }/* End of For */
    }/* End of While */
    
    return 0;
}
