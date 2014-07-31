#include <stdio.h>

//#define onlinejudge

const int maxn = 20;

bool IsSolved;
int  n, t, num[maxn], ans[maxn];

void dfs(int st, int cnt, int sum, int last)
{
    if (sum == t)
    {
        IsSolved = true;
        for (int i=1; i<cnt; ++i)
            printf(i==1 ? "%d":"+%d", ans[i]);
        printf("\n");
        
        return ;
    }/* End of IF */
    
    for (int i=st; i<=n; ++i)
    {
        if (last != num[i])
        {
            ans[cnt] = num[i];
            dfs(i+1, cnt+1, sum+num[i], last);
            last = num[i];
        }
    }/* End of For */
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1258.txt", "r", stdin);
    freopen("E:\\hdoj_1258_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &t, &n), n!=0)
    {
        printf("Sums of %d:\n", t);
        
        for (int i=1; i<=n; ++i)
            scanf("%d", &num[i]);
        
        IsSolved = false;
        dfs(1, 1, 0, -1);
        
        if (!IsSolved)
            printf("NONE\n");
    }/* End of While */
    
    return 0;
}
