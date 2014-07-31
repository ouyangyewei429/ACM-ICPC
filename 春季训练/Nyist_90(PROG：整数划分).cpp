/**
 * PROG: 整数划分
 */
#include <cstdio>

int g_target;
int g_solution_count;

void dfs(int prev, int sum)
{
    if (sum == g_target)
    {
        ++g_solution_count;
        return ;
    }

    for (int i=g_target; i>=1; --i)
    {
        if (sum+i<=g_target && i<=prev)
        {
            dfs(i, sum+i);
        }
    }
}

int main(void)
{
    int nCases;
    scanf("%d", &nCases);
    while (nCases--)
    {
        scanf("%d", &g_target);

        g_solution_count = 0;
        dfs(g_target, 0);
        printf("%d\n", g_solution_count);
    }// End of while
    return 0;
}
