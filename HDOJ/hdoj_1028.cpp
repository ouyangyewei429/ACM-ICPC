#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int  N, ans;
bool hash[124];

void dfs(int sum)
{
    if (sum == N)
    {
        ++ans;
        return ;
    }/* End of IF */
    
    for (int i=1; i<=N; ++i)
    {
        if (sum+i>N)
            continue;
        
        //hash[i] = true;
        dfs(sum+i);
        //hash[i] = false;
    }/* End of For */
}/* dfs */

int main()
{
    while (~scanf("%d", &N))
    {
        //memset(hash, false, sizeof(hash));
        
        ans = 0;
        dfs(0);
        printf("%d\n", ans);
    }/* End of While */
    
    return 0;
}
