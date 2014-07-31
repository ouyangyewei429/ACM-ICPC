/**
 * PROG: ªı±“√Ê÷µ
 */
#include <cstdio>
#include <memory.h>

const int MAX_COIN_COUNT = 128;

int g_nCoins;
int g_coin[MAX_COIN_COUNT] = {0};
int g_visit[MAX_COIN_COUNT] = {false};

bool dfs(int value, int target)
{
    if (value == target)
    {
        return true;
    }

    for (int i=0; i<g_nCoins; ++i)
    {
        if (!g_visit[i] && value+g_coin[i]<=target)
        {
            g_visit[i] = true;
            if (dfs(value+g_coin[i], target))
            {
                return true;
            }
            g_visit[i] = false;
        }
    }
    return false;
}

int main(void)
{
    while (~scanf("%d", &g_nCoins))
    {
        for (int i=0; i<g_nCoins; ++i)
        {
            scanf("%d", &g_coin[i]);
        }

        for (int min_value=1; ; ++min_value)
        {
            memset(g_visit, false, sizeof(g_visit));
            if (!dfs(0, min_value))
            {
                printf("%d\n", min_value);
                break;
            }
        }
    }// End of while
    return 0;
}
