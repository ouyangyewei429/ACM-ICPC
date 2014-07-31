/**
 * PROG: ÕûÊý²ð·Ö
 */
#include <cstdio>

const int MAX_FACTOR_TABLE_SIZE = 21;

int g_count = 0;
int g_target = 0;
int g_limit = 0;
int g_factor[MAX_FACTOR_TABLE_SIZE] = {0};

void GetFactor()
{
    for (int i=0; i<MAX_FACTOR_TABLE_SIZE; ++i)
    {
        g_factor[i] = (1<<i);
        //printf("** %d **\n", g_factor[i]);
    }
}

void dfs(int last, int sum)
{
    if (sum == g_target)
    {
        g_count = (g_count + 1) % 1000000000;
        return ;
    }

    for (int i=0; i<=g_limit; ++i)
    {
        if (g_factor[i]>=last && sum+g_factor[i]<=g_target)
        {
            dfs(g_factor[i], sum+g_factor[i]);
        }
    }
}

int main(void)
{
    GetFactor();

    while (~scanf("%d", &g_target))
    {
        for (int i=0; i<MAX_FACTOR_TABLE_SIZE; ++i)
        {
            if (g_factor[i] >= g_target)
            {
                g_limit = i;
                break;
            }
        }

        g_count = 0;
        dfs(1, 1);
        printf("%d\n", g_count);
    }
    return 0;
}
