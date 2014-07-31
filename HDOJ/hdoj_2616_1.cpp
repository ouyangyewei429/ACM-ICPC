#include <stdio.h>

//#define onlinejudge

const int maxn = 10000000;

bool IsSolved;
int  n, totHp, a[maxn], m[maxn], hash[maxn], min;

void dfs(int cnt, int hp)
{
    if (hp<=0 && min>cnt)
    {
        min = cnt;
        IsSolved = true;
        return ;
    }
    
    for (int i=1; i<=n; ++i)
    {
        if (!hash[i])
        {
            hash[i] = true;
            if (hp > m[i])
                dfs(cnt+1, hp-a[i]);
            else
                dfs(cnt+1, hp-a[i]-a[i]);
            hash[i] = false;
        }
    }/* End of For */
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2616.txt", "r", stdin);
    freopen("E:\\hdoj_2616_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &n, &totHp))
    {
        for (int i=1; i<=n; ++i)
        {
            hash[maxn] = 0;
            scanf("%d %d", &a[i], &m[i]);
        }/* End of For */
        
        IsSolved = false;
        min = 0x3F3F3F3F;
        dfs(0, totHp);
        
        if (IsSolved)
            printf("%d\n", min);
        else
            printf("-1\n");
    }/* End of While */
    
    return 0;
}
