/**
 * PROG: xxx¶¨ÂÉ
 */
#include <cstdio>

int main(void)
{
    int n;
    while (~scanf("%d", &n))
    {
        if (0 == n)
        {
            break;
        }

        int nSteps = 0;
        while (1 != n)
        {
            if (0 != n%2)
            {
                n = n*3+1;
            }

            n /= 2;
            ++nSteps;
        }

        printf("%d\n", nSteps);
    }// End of While

    return 0;
}
