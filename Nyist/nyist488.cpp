#include <stdio.h>
#include <math.h>

int n, cas=1;
int ans[50], vis[50], IsPrime[101]={1, 1, 0};

void dfs(int cnt)
{
    if (cnt==n+1 && !IsPrime[1+ans[cnt-1]])
    {
        for (int i=1; i<=n; ++i)
            printf("%d ", ans[i]);
        printf("\n");
        
        return ;
    }/* End of If */
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
    }/* End of Else */
}/* dfs */

int main()
{
    for (int i=2; i<=(int)sqrt(100.0); ++i)
    {
        if (!IsPrime[i])
        {
            for (int j=i*i; j<=100; j+=i)
                IsPrime[j] = 1;
        }
    }/* End of For */
    
    while (~scanf("%d", &n), n!=0)
    {
        printf("Case %d:\n", cas++);
        if ((n&1) == 0)
        {
            ans[1]=1, vis[1]=1;
            dfs(2);
        }
        else if (n == 1)
            printf("1\n");
        else
            printf("No Answer\n");
    }/* End of While */
    
    return 0;
}
