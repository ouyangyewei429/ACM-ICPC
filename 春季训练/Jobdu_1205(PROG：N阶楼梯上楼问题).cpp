/**
 * PROG: N½×Â¥ÌİÉÏÂ¥ÎÊÌâ
 */
#include <cstdio>

const int MAX_SIZE = 128;

int g_stairs;
long long g_steps[MAX_SIZE] = {0, 1, 2};
/*
int f(int n)
{
    if (n >= g_stairs)
    {
        if (n == g_stairs)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return f(n+1) + f(n+2);
}
*/
int main(void)
{
    for (int i=3; i<MAX_SIZE; ++i)
    {
        g_steps[i] = g_steps[i-1] + g_steps[i-2];
    }

    while (~scanf("%d", &g_stairs))
    {
        printf("%lld\n", g_steps[g_stairs]);
    }
    return 0;
}
