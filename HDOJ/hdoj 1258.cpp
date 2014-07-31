#include <stdio.h>

#define onlinejudge

const int maxn = 200;

bool IsSolved, hash[maxn];
int  t, n, num[maxn], ans[maxn];

void dfs(int s, int cnt, int sum)
{
    if (sum == t)
    {
        IsSolved = true;
        for (int i=1; i<cnt; ++i)
            printf(i==1 ? "%d":"+%d", ans[i]);
        printf("\n");
    }
    else
    {
        for (int i=s; i<=n; ++i)
        {
            if (!hash[i] && num[i]+sum<=t)
            {
                ans[cnt] = num[i];
                
                hash[i] = true;
                dfs(i+1, cnt+1, sum+num[i]);
                hash[i] = false;
            }
        }/* End of For */
    }
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1258.txt", "r", stdin);
    freopen("E:\\hdoj_1258_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &t, &n), n!=0)
    {
        for (int i=1; i<=n; ++i)
        {
            hash[i] = false;
            scanf("%d", &num[i]);
        }

        printf("Sums of %d:\n", t);
        
        IsSolved = false;
        dfs(1, 1, 0);
        if (!IsSolved)
            printf("NONE\n");
    }/* End of While */
    
    return 0;
}
