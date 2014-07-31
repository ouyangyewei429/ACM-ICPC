#include <cmath>
#include <cstdio>

int n, cas=1;
int vis[30], ans[30], IsPrime[50]={1, 1, 0};

void dfs(int cnt)
{
    if (cnt==n+1 && !IsPrime[1+ans[cnt-1]])
    {
        for (int i=1; i<=n; ++i)
            printf(i==1 ? "%d":" %d", ans[i]);
        printf("\n");
        
        return ;
    }/* End of IF */
    else
    {
        for (int i=2; i<=n; ++i)
        {
            if (!vis[i] && !IsPrime[i+ans[cnt-1]])
            {
                ans[cnt] = i;
                
                vis[i] = 1;
                dfs(cnt+1);
                vis[i] = 0;
            }
        }
    }
}/* dfs */

int main()
{
    freopen("E:\\hdoj_1016.txt", "r", stdin);
    freopen("E:\\hdoj_1016_ans.txt", "w", stdout);

    for (int i=2; i<=(int)sqrt(50.0); ++i)
    {
        if (!IsPrime[i])
        {
            for (int j=i*i; j<=50; j+=i)
                IsPrime[j] = 1;
        }
    }/* End of For */
    
    while (~scanf("%d", &n))
    {
        printf("Case %d:\n", cas++);
        
        if ((n&1) == 0)
        {
            ans[1]=1, vis[1]=1;
            dfs(2);
        }
        printf("\n");   
    }/* End of While */
    
    return 0;
}
