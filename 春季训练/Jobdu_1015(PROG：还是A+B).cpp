/**
 * PROG: »¹ÊÇA+B
 */
#include <cstdio>

long GetRes(int k)
{
    switch (k)
    {
        case 1: return 10; break;
        case 2: return 100; break;
        case 3: return 1000; break;
        case 4: return 10000; break;
        case 5: return 100000; break;
        case 6: return 1000000; break;
        case 7: return 10000000; break;
        case 8: return 100000000; break;
        default: return 1; break;
    }
}

int main(void)
{
    int a, b, k;

    while (~scanf("%d %d %d", &a, &b, &k))
    {
        if (0 == a+b)
        {
            break;
        }

        long res = GetRes(k);
        if (a%res == b%res)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", a+b);
        }
    }

    return 0;
}
